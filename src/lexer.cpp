#include <map>
#include <array>
#include <algorithm>
#include <regex>

#include "lexer.hpp"
#include "exceptions.hpp"

namespace Prumath::Lexer {
	static const std::map<char, Token::TokenType> token_type_map = {
		{ '+', Token::TokenType::ADD },
		{ '-', Token::TokenType::SUB },
		{ '*', Token::TokenType::MUL },
		{ '/', Token::TokenType::DIV },
		{ '%', Token::TokenType::MOD }
	};

	std::vector<Token::Token> lex(std::string& expr) {
		expr = std::regex_replace(expr, std::regex(","), ".");

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
			if (token_type_map.count(c) > 0) {
				if (!current_numtoken.empty()) {
					push_number();
					current_numtoken = "";
				}

				tokens.push_back({
					token_type_map.at(c),
					std::nullopt
				});
			} else if (c == '.' || (c >= '0' && c <= '9')) {
				current_numtoken += c;
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
