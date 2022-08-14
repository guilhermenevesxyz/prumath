#include <iostream>

#include "lexer.hpp"
#include "syntax.hpp"
#include "parser.hpp"

int main() {
	std::string expression;

	while (true) {
		std::cout << "Enter an expression: ";
		std::getline(std::cin, expression);

		auto tokens = Prumath::Lexer::lex(expression);
		for (size_t i = 0; i < tokens.size(); ++i) {
			std::cout << (int)tokens[i].type << "\n";
		}

		Prumath::Syntax::validate(tokens);

		auto ast = Prumath::Parser::parse(tokens);
		std::cout << *ast << std::endl;
	}

	return EXIT_SUCCESS;
}
