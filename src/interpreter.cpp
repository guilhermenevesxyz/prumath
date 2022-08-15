#include "interpreter.hpp"

#include <cmath>

namespace Prumath::Interpreter {
	float interpret(std::shared_ptr<AST::Node> node) {
		switch (node->type) {
		case Token::TokenType::NUM:
			return node->value.value();
			break;

		case Token::TokenType::ADD:
			return interpret(node->a) + interpret(node->b);
			break;

		case Token::TokenType::SUB:
			return interpret(node->a) - interpret(node->b);
			break;

		case Token::TokenType::MUL:
			return interpret(node->a) * interpret(node->b);
			break;

		case Token::TokenType::DIV:
			return interpret(node->a) / interpret(node->b);
			break;

		case Token::TokenType::MOD:
			return std::fmod(
				interpret(node->a),
				interpret(node->b)
			);
			
			break;

		case Token::TokenType::GRT:
			return interpret(node->a) > interpret(node->b) ? 1 : 0;
			break;

		case Token::TokenType::SMT:
			return interpret(node->a) < interpret(node->b) ? 1 : 0;
			break;

		case Token::TokenType::EQS:
			return interpret(node->a) == interpret(node->b) ? 1 : 0;
			break;
		}

		return 0.0f;
	}
}
