#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <array>
#include <exception>
#include <algorithm>

#define IS_IN_ARRAY(item, array) \
	(std::find(std::begin(array), std::end(array), item) != std::end(array))

class UnexpectedCharacterException : public std::exception {
public:
	virtual const char* what() const noexcept override {
		return "Unexpected character in math expression.";
	}
};

void string_replace(std::string& src, const std::string& from, const std::string& to) {
	if (from.empty()) {
		return;
	}

	size_t start_pos = 0;
	while ((start_pos = src.find(from, start_pos)) != std::string::npos) {
		src.replace(start_pos, from.length(), to);
		start_pos += to.length();
	}
}

enum TokenType {
	NUM, ADD, SUB, MUL, DIV, MOD
};

struct Token {
	TokenType type;
	std::unique_ptr<std::string> value;
};

static const std::array<char, 5> operators = {
	'+', '-', '*', '/', '%'
};

static const std::array<char, 2> separators = {
	'.', ','
};

std::vector<Token> lex(const std::string& expr) {
	/* Clean the expression. */
	std::string clean_expr = "";
	for (const char& c : expr) {
		if (IS_IN_ARRAY(c, operators) ||
		    IS_IN_ARRAY(c, separators) ||
		    (c >= '0' && c <= '9')) {
			clean_expr += c;
			break;
		} else {
			throw UnexpectedCharacterException();
		}
	}

	std::vector<Token> tokens;
	std::string current_numtoken = "";

	for (const char& c : expr) {
		if (IS_IN_ARRAY(c, operators)) {
			if (current_numtoken != "") {
				tokens.push_back({
					TokenType::NUM,
					std::make_unique<std::string>(current_numtoken)
				});

				current_numtoken = "";
			}

			switch (c) {
			case '+':
				tokens.push_back({
					TokenType::ADD,
					nullptr
				});

				break;

			case '-':
				tokens.push_back({
					TokenType::SUB,
					nullptr
				});

				break;

			case '*':
				tokens.push_back({
					TokenType::MUL,
					nullptr
				});

				break;

			case '/':
				tokens.push_back({
					TokenType::DIV,
					nullptr
				});

				break;

			case '%':
				tokens.push_back({
					TokenType::MOD,
					nullptr
				});

				break;
			}
		} else {
			current_numtoken += c;
		}
	}

	if (!current_numtoken.empty()) {
		tokens.push_back({
			TokenType::NUM,
			std::make_unique<std::string>(current_numtoken)
		});
	}

	return tokens;
}

int main() {
	std::string expression;

	while (true) {
		std::cout << "Enter an expression: ";
		std::getline(std::cin, expression);
		std::cout << expression << std::endl;

		auto tokens = lex(expression);
		for (size_t i = 0; i < tokens.size(); ++i) {
			std::cout << (int)tokens[i].type << "\n";
		}
	}

	return EXIT_SUCCESS;
}
