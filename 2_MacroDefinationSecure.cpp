#include <iostream>

#define SQUARE(x) x * x
#define SQUAREALT(x) ((x) * (x))

int main() {
	int input;
	std::cout << "Enter a number: ";
	std::cin >> input;

	int result = SQUARE(input + 1);	// expands to: input + 1 * input + 1

	std::cout << "Result: " << result << std::endl;	// completely wrong result

	result = SQUAREALT(input + 1);	// expands to: input + 1 * input + 1

	std::cout << "Result: " << result << std::endl; // now this one is correct

	return 0;
}