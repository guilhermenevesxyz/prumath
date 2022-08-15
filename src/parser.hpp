#ifndef PRUMATH_PARSER_HPP
#define PRUMATH_PARSER_HPP

#include <vector>

#include "ast.hpp"
#include "token.hpp"

namespace Prumath::Parser {
	std::shared_ptr<AST::Node> parse(
		const std::vector<Token::Token>& tokens);
}

#endif
