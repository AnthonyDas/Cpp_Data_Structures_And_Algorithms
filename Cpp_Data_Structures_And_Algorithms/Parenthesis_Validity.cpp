#include <iostream>
#include <cstring>
#include "Stack.h"

bool IsValid(char expression[]) {
	int n = strlen(expression);

	Stack<char> stackChar;

	for (int i = 0; i < n; ++i) {
		// If input is opened parenthesis
		// just store it in the stack
		if (expression[i] == '{') {
			stackChar.Push('{');
		}
		else if (expression[i] == '[') {
			stackChar.Push('[');
		}
		else if (expression[i] == '(') {
			stackChar.Push('(');
		}
		// Check when the input
		// is closed parenthesis
		else if (expression[i] == '}' || expression[i] == ']' || expression[i] == ')') {
			// If the stack is empty
			// or the last parenthesis is different
			// than the one we are closed,
			// then the expression is wrong
			if (expression[i] == '}' && (stackChar.IsEmpty() || stackChar.Top() != '{'))
				return false;
			else if (expression[i] == ']' && (stackChar.IsEmpty() || stackChar.Top() != '['))
				return false;
			else if (expression[i] == ')' && (stackChar.IsEmpty() || stackChar.Top() != '('))
				return false;
			else
				stackChar.Pop();
		}
	}

	// If the stack is empty,
	// the expression is valid
	// otherwise it's invalid
	if (stackChar.IsEmpty())
		return true; //
	else
		return false;
}

int main() {
	// Prepare array for storing the expression
	char expr[1000];

	// Ask user to input the expression
	std::cout << "Please type the parenthesis expression ";
	std::cout << "then press ENTER!" << std::endl;
	std::cin >> expr;

	// Check the validity
	bool res = IsValid(expr);

	// Notify the user
	std::cout << std::endl << "The " << expr << " expression is ";
	std::cout << (res ? "valid" : "invalid") << std::endl;

	return 0;
}
