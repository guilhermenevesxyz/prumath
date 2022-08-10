#ifndef PRUMATH_LEXER_HPP
#define PRUMATH_LEXER_HPP

#include <optional>
#include <string>
#include <vector>

namespace Prumath::Lexer {
	enum TokenType {
		NUM, ADD, SUB, MUL, DIV, MOD
	};

	struct Token {
		TokenType type;
		std::optional<std::string> value;
	};

	std::vector<Token> lex(const std::string& expr);
}

#endif
