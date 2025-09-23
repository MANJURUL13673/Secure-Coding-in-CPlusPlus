// Description: Example of unsafe C-style string handling

#include <iostream>

int main()
{
	char msg[32];
	char name[10];
	std::cout << "Enter your name: ";

	// 1. Unsafe: buffer overflow if input exceeds 9 characters
	std::cin >> name;

	// 2. Unsafe: potential truncation if name is too long
	std::snprintf(msg, sizeof(msg), "Hello, %s!", name);	// Look safe...

	// 1. Safe: use std::string to avoid buffer overflows and truncation

	std::cout << msg << std::endl;

	std::cout << std::endl << std::endl;
	return 0;
}