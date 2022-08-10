#ifndef PRUMATH_CUSTOM_EXCEPTIONS_HPP
#define PRUMATH_CUSTOM_EXCEPTIONS_HPP

#include <exception>

namespace Prumath::CustomExceptions {
	class UnexpectedCharacter : public std::exception {
	public:
		virtual const char* what() const noexcept override;
	};
}

#endif
