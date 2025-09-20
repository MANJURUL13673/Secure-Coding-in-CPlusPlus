#include<iostream>
#include<string>

int main()
{
	std::string userInput;
	std::cout << "Enter a message: ";
	std::getline(std::cin, userInput);

	// Vulnerable to format string attacks
	//1. if user provides format specifiers like %s, %x, etc. it will show stack data
	std::printf(userInput.c_str());

	// Alnernative safe way
	//1. Always use fixed format strings
	std::printf("%s\n", userInput.c_str());

	std::cout << std::endl << std::endl;
	return 0;
}