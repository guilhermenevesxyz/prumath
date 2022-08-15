#include <regex>
#include <functional>

#include "parser.hpp"
#include "exceptions.hpp"

namespace Prumath::Parser {
	class Parser {
	private:
		const std::vector<Token::Token>& tokens;
		std::vector<Token::Token>::const_iterator token_it;

		std::unique_ptr<Node> binary_operation_rule(
			std::function<std::unique_ptr<Node>()> requirement,
			const std::vector<Token::TokenType>& operations
		) {
			auto result = requirement();

			while (std::find(operations.begin(), operations.end(),
			       this->token_it->type) != operations.end()) {
				const auto token_type = this->token_it->type;

				std::advance(this->token_it, 1);

				result = std::make_unique<Node>(Node {
					token_type,
					std::nullopt,
					std::move(result),
					requirement()
				});
			}

			return result;
		}
		
		std::unique_ptr<Node> factor() {
			switch (this->token_it->type) {
			case Token::TokenType::NUM:
				{
					std::string num_str =
						std::regex_replace(
							std::regex_replace(
								this->token_it->
								      value
								      .value(),
								std::regex(","),
								"."
							),
							std::regex("_"),
							""
						);

					float num_float = 0.0f;

					try {
						num_float = std::stof(num_str);
					} catch (std::out_of_range e) {
						throw Exceptions::
							OutOfRangeNumber(
								this->token_it->
									value
									.value()
							);

						return std::unique_ptr<Node>(
							nullptr);
					}

					std::advance(this->token_it, 1);

					return std::make_unique<Node>(Node {
						Token::TokenType::NUM,
						num_float,
						std::unique_ptr<Node>(nullptr),
						std::unique_ptr<Node>(nullptr)
					});
				} break;

			case Token::TokenType::ADD:
			case Token::TokenType::SUB:
				{
					const auto token_type = this->token_it->
						type;

					std::advance(this->token_it, 1);
					
					return std::make_unique<Node>(Node {
						token_type,
						std::nullopt,
						std::make_unique<Node>(Node {
							Token::TokenType::NUM,
							0.0f,
							std::unique_ptr<Node>(
								nullptr
							),
							std::unique_ptr<Node>(
								nullptr
							)
						}),
						this->factor()
					});
				} break;
			
			case Token::TokenType::LPA:
				{
					std::advance(this->token_it, 1);
					auto result = this->expression();
					std::advance(this->token_it, 1);
					return result;
				} break;

			default:
				return std::unique_ptr<Node>(nullptr);
				break;
			}
		}

		std::unique_ptr<Node> term() {
			return this->binary_operation_rule(
				std::bind(&Parser::factor, this),
				{ Token::TokenType::MUL, Token::TokenType::DIV }
			);
		}

		std::unique_ptr<Node> expression() {
			return this->binary_operation_rule(
				std::bind(&Parser::term, this),
				{ Token::TokenType::ADD, Token::TokenType::SUB }
			);
		}

		std::unique_ptr<Node> comparison() {
			return this->binary_operation_rule(
				std::bind(&Parser::expression, this),
				{
					Token::TokenType::GRT,
					Token::TokenType::SMT,
					Token::TokenType::EQS
				}
			);
		}

	public:
		explicit Parser(const std::vector<Token::Token>& token_list)
			: tokens(token_list),
			  token_it(this->tokens.begin()) {}

		std::unique_ptr<Node> parse_expression() {
			auto result = this->comparison();
			return result;
		}
	};

	std::unique_ptr<Node> parse(const std::vector<Token::Token>& tokens) {
		auto parser_obj = Parser(tokens);
		return parser_obj.parse_expression();
	}
}
