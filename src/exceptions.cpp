#include "exceptions.hpp"

namespace Prumath::Exceptions {
	InvalidExpression::InvalidExpression() {}

	const char* InvalidExpression::what() const noexcept {
		return "Invalid expression.";
	}
	
	ExceptionWithMessage::ExceptionWithMessage(const char* msg)
		: message(msg) {}

	ExceptionWithMessage::ExceptionWithMessage(const std::string& msg)
		: message(msg) {}

	const char* ExceptionWithMessage::what() const noexcept {
		return this->message.c_str();
	}

	UnexpectedCharacter::UnexpectedCharacter(const char* msg)
		: ExceptionWithMessage(
			std::string("Unexpected character in expression \"")
				.append(msg).append("\".")
		  ) {}

	UnexpectedCharacter::UnexpectedCharacter(const std::string& msg)
		: ExceptionWithMessage(
			std::string("Unexpected character in expression \"")
				.append(msg).append("\".")
		   ) {}

	const char* UnexpectedCharacter::what() const noexcept {
		return this->message.c_str();
	}

	InvalidNumber::InvalidNumber(const char* msg)
		: ExceptionWithMessage(
			std::string("Invalid number \"").append(msg)
				.append("\".")
		  ) {}
	
	InvalidNumber::InvalidNumber(const std::string& msg)
		: ExceptionWithMessage(
			std::string("Invalid number \"").append(msg)
				.append("\".")
		  ) {}

	const char* InvalidNumber::what() const noexcept {
		return this->message.c_str();
	}

	OutOfRangeNumber::OutOfRangeNumber(const char* msg)
		: ExceptionWithMessage(
			std::string("Number \"").append(msg)
				.append("\" is out of range.")
		  ) {}

	OutOfRangeNumber::OutOfRangeNumber(const std::string& msg)
		: ExceptionWithMessage(
			std::string("Number \"").append(msg)
				.append("\" is out of range.")
		  ) {}

	const char* OutOfRangeNumber::what() const noexcept {
		return this->message.c_str();
	}
}
