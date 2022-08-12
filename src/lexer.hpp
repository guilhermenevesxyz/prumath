#ifndef PRUMATH_LEXER_HPP
#define PRUMATH_LEXER_HPP

#include <optional>
#include <string>
#include <vector>

#include "token.hpp"

namespace Prumath::Lexer {
	std::vector<Token::Token> lex(std::string& expr);
}

#endif
