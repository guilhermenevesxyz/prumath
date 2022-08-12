#include "syntax.hpp"
#include "exceptions.hpp"

namespace Prumath::Syntax {
	/* Checks whether a token expression has a valid syntax according to
	 * the rules for mathematical expressions. */
	void validate(const std::vector<Token::Token>& tokens) {
		for (auto token_it = tokens.begin(); token_it != tokens.end();
		     std::advance(token_it, 1)) {
			switch (token_it->type) {
			case Token::TokenType::NUM:
				{
					size_t sep_count = 0;
					bool has_digit = false;

					for (auto c : token_it->value.value()) {
						if (c == '.') {
							++sep_count;
						} else {
							has_digit = true;
						}
					}

					if (sep_count > 1 || !has_digit) {
						throw Exceptions::InvalidNumber(
							token_it->value.value()
						);

						return;
					}
				} break;

			case Token::TokenType::ADD:
			case Token::TokenType::SUB:
				if (std::next(token_it) == tokens.end()) {
					throw Exceptions::InvalidExpression();
					return;
				}

				break;
			
			case Token::TokenType::MUL:
			case Token::TokenType::DIV:
			case Token::TokenType::MOD:
				{
					const auto next_token_it =
						std::next(token_it);

					if (token_it == tokens.begin() ||
				    	    next_token_it == tokens.end()) {
						throw Exceptions::
							InvalidExpression();
						return;
					}

					if (std::prev(token_it)->type !=
					    Token::TokenType::NUM) {
						throw Exceptions::
							InvalidExpression();
						return;
					}
				} break;
			}
		}
	}
}
