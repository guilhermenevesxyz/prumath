#ifndef PRUMATH_TOKEN_HPP
#define PRUMATH_TOKEN_HPP

#include <optional>
#include <string>

namespace Prumath::Token {
	enum TokenType {
		NUM, ADD, SUB, MUL, DIV, MOD
	};

	struct Token {
	public:
		TokenType type;
		std::optional<std::string> value;
	};
}

#endif
