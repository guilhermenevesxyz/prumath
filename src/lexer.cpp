#include <map>

#include "lexer.hpp"
#include "exceptions.hpp"

namespace Prumath::Lexer {
	static const std::map<char, Token::TokenType> operators = {
		{ '+', Token::TokenType::ADD },
		{ '-', Token::TokenType::SUB },
		{ '*', Token::TokenType::MUL },
		{ '/', Token::TokenType::DIV },
		{ '%', Token::TokenType::MOD }
	};

	std::vector<Token::Token> lex(const std::string& expr) {
		std::vector<Token::Token> tokens;
		std::string current_numtoken = "";

		auto push_number = [&tokens, &current_numtoken] () mutable
		                                                   -> void {
			tokens.push_back({
				Token::TokenType::NUM,
				current_numtoken
			});
		};

		for (const char& c : expr) {
			/* This will only return one or zero, depending on
			 * whether the map has the key or not, despite the
			 * confusing name. It will not iterate through the
			 * whole map! */
			if (operators.count(c) > 0) {
				if (!current_numtoken.empty()) {
					push_number();
					current_numtoken = "";
				}

				tokens.push_back({
					operators.at(c),
					std::nullopt
				});
			} else if (c == '.' || c == ',' || c == '_' ||
			           (c >= '0' && c <= '9')) {
				current_numtoken += c;
			} else if (c == ' '  || c == '\t') {
				if (!current_numtoken.empty()) {
					push_number();
					current_numtoken = "";
				}
			} else {
				throw Exceptions::UnexpectedCharacter(expr);
				return std::vector<Token::Token>();
			}
		}

		if (!current_numtoken.empty()) {
			push_number();
		}

		return tokens;
	}
}
