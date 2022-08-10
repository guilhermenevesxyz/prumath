#include "custom_exceptions.hpp"

namespace Prumath::CustomExceptions {
	const char* UnexpectedCharacter::what() const noexcept {
		return "Unexpected character in math expression.";
	}
}
