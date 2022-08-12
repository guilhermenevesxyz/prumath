#ifndef PRUMATH_PARSER_HPP
#define PRUMATH_PARSER_HPP

#include <memory>
#include <vector>

/*
 * TODO: remove this after tests.
 */
#include <iostream>

#include "token.hpp"

namespace Prumath::Parser {
	struct Node {
	public:
		Token::TokenType type;
		std::optional<float> value;
		std::unique_ptr<Node> a;
		std::unique_ptr<Node> b;

		friend std::ostream& operator<<(std::ostream& os,
		                                const Node& n) {
			auto value = .0f;

			if (n.value != std::nullopt) {
				value = n.value.value();
			}

			if (n.a && n.b) {
				return os << "Prumath::Parser::Node { type=" <<
					n.type << ", value=" << value <<
					", node1=" << *(n.a) << ", node2=" <<
					*(n.b) << " }";
			}

			return os << "Prumath::Parser::Node { type=" <<
				n.type << ", value=" << value << " }";
		}
	};

	std::unique_ptr<Node> parse(const std::vector<Token::Token>& tokens);
}

#endif
