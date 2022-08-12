#ifndef PRUMATH_SYNTAX_HPP
#define PRUMATH_SYNTAX_HPP

#include <vector>

#include "token.hpp"

namespace Prumath::Syntax {
	void validate(const std::vector<Token::Token>& tokens);
}

#endif
