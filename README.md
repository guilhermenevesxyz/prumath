# Prumath
## Overview
**Prumath** is a math expression evaluator written in modern C++.
It parses common math expressions and can solve equations fast,
using a quick parsing algorithm without much performance impact.

The name is Prumath due to this library being part of the Pru project.
It later was removed from the project due to not maching the standards,
but the name was kept. 

## Usage
To evaluate a math expression, use the `evaluate` function,
present inside the `Prumath` namespace.
Below is an example of a simple program that
prompts the user to enter an equation indefinitely and solves it,
presenting the result in the end.
```cpp
#include "include/prumath.hpp"
#include <iostream>

int main() {
	std::string expression;

	while (true) {
		std::cout << "Enter an expression: ";
		std::getline(std::cin, expression);

		std::cout << "Result: " <<
			Prumath::evaluate(expression) << '\n';
	}

	return EXIT_SUCCESS;
}
```

## Building
Prumath uses [Premake 5](https://premake.github.io/) to generate project files.
Please refer to [the Premake 5 documentation](https://premake.github.io/docs/)
for information on how to use the tool.

