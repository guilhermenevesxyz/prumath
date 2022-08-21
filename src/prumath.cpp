#include "../include/prumath.hpp"
#include "lexer.hpp"
#include "syntax.hpp"
#include "parser.hpp"
#include "interpreter.hpp"

namespace Prumath {
	float evaluate(const std::string& expr) {
		auto tokens = Prumath::Lexer::lex(expr);
		Prumath::Syntax::validate(tokens);
		
		return Prumath::Interpreter::interpret(
			Prumath::Parser::parse(tokens)
		);
	}
}

