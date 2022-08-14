#ifndef PRUMATH_LEXER_HPP
#define PRUMATH_LEXER_HPP

#include <string>
#include <vector>

#include "token.hpp"

namespace Prumath::Lexer {
	std::vector<Token::Token> lex(const std::string& expr);
}

#endif
