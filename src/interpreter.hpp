#ifndef PRUMATH_INTERPRETER_HPP
#define PRUMATH_INTERPRETER_HPP

#include <memory>

#include "ast.hpp"

namespace Prumath::Interpreter {
	float interpret(std::shared_ptr<AST::Node> ast);
}

#endif
