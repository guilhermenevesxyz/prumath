#ifndef PRUMATH_EXCEPTIONS_HPP
#define PRUMATH_EXCEPTIONS_HPP

#include <exception>
#include <string>

namespace Prumath::Exceptions {
	class InvalidExpression : public std::exception {
	public:
		explicit InvalidExpression();
		const char* what() const noexcept override;
	};

	class UnmatchedParenthesis : public std::exception {
	public:
		explicit UnmatchedParenthesis();
		const char* what() const noexcept override;
	};

	class ExceptionWithMessage : public std::exception {
	protected:
		const std::string message;

	public:
		explicit ExceptionWithMessage(const char* msg);
		explicit ExceptionWithMessage(const std::string& msg);
		virtual const char* what() const noexcept;
	};

	class UnexpectedCharacter : public ExceptionWithMessage {
	public:
		explicit UnexpectedCharacter(const char* msg);
		explicit UnexpectedCharacter(const std::string& msg);
		const char* what() const noexcept override;
	};

	class InvalidNumber : public ExceptionWithMessage {
	public:
		explicit InvalidNumber(const char* msg);
		explicit InvalidNumber(const std::string& msg);
		const char* what() const noexcept override;
	};

	class OutOfRangeNumber : public ExceptionWithMessage {
	public:
		explicit OutOfRangeNumber(const char* msg);
		explicit OutOfRangeNumber(const std::string& msg);
		const char* what() const noexcept override;
	};
}

#endif
