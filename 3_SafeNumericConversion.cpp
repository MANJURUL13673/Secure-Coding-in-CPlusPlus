#include <iostream>
#include <string>
#include <vector>
#include <charconv> // for std::from_chars

int main() {
	std::string input;
	std::cout << "Enter index: ";
	std::cin >> input;

	//1. Unsafe: assumes input is clean decimal and fully numeric
	int index = std::stoi(input);	// may throw, or misinterpret input

	// Alternative safer conversion (C++17 and later)
	// 1. Check if the entire string is numeric and convert
	int indexAlt;
	auto result = std::from_chars(input.data(), input.data() + input.size(), indexAlt);

	if (result.ec != std::errc() || result.ptr != input.data() + input.size()) {
		std::cerr << "Invalid input. Please enter a valid integer." << std::endl;
		return 1; // exit or handle error
	}

	std::vector<std::string> options = { "Option1", "Option2", "Option3", "Option4"};

	//2. Unsafe: no bounds checking
	//std::cout << "You selected: " << options[index] << std::endl; // may access out of bounds

	// Alternative
	// 2. Safer: valid index check
	if (indexAlt < 0 || indexAlt >= static_cast<int>(options.size())) {
		std::cerr << "Index out of bounds. Please select a valid option." << std::endl;
		return 1; // exit or handle error
	}
	std::cout << "You selected: " << options[indexAlt] << std::endl;

	std::cout << std::endl << std::endl;
	return 0;
}