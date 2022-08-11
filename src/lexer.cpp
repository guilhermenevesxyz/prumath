#include <map>
#include <array>
#include <algorithm>

#include "lexer.hpp"
#include "exceptions.hpp"

namespace Prumath::Lexer {
	static const std::map<char, TokenType> token_type_map = {
		{ '+', TokenType::ADD },
		{ '-', TokenType::SUB },
		{ '*', TokenType::MUL },
		{ '/', TokenType::DIV },
		{ '%', TokenType::MOD }
	};

	static const std::array<char, 2> separators = {
		'.', ','
	};

	std::vector<Token> lex(const std::string& expr) {
		std::vector<Token> tokens;
		std::string current_numtoken = "";

		for (const char& c : expr) {
			if (token_type_map.count(c) > 0) {
				if (!current_numtoken.empty()) {
					tokens.push_back({
						TokenType::NUM,
						current_numtoken
					});

					current_numtoken = "";
				}

				tokens.push_back({
					token_type_map.at(c),
					std::nullopt
				});
			} else if (std::any_of(separators.begin(),
			           separators.end(),
				   [c] (const auto &i) { return i == c; }) ||
				   (c >= '0' && c <= '9')) {
				current_numtoken += c;
			} else {
				throw Exceptions::UnexpectedCharacter(expr);
				return std::vector<Token>();
			}
		}

		if (!current_numtoken.empty()) {
			tokens.push_back({
				TokenType::NUM,
				current_numtoken
			});
		}

		return tokens;
	}
}
