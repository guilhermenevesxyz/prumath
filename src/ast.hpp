#ifndef PRUMATH_AST_HPP
#define PRUMATH_AST_HPP

#include <optional>
#include <memory>

#include "token.hpp"

namespace Prumath::AST {
	struct Node {
	public:
		Token::TokenType type;
		std::optional<float> value;
		std::shared_ptr<Node> a;
		std::shared_ptr<Node> b;

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
}

#endif
