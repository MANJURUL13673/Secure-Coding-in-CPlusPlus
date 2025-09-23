#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main()
{
	std::ifstream file("config.txt");
	std::string line;

	//1. Blind trust in file content
	std::getline(file, line);	// Danger: file may not open

	//1. Security: Check if file opened successfully
	if(!file) {
		throw std::ios_base::failure("Failed to read from file");
	}
	// read and process lines safely
	while(std::getline(file, line)) {
		// validate and parse line
	}
	////////////////////////////////

	//2. unsafe assumptions about file format
	int count;
	file >> count;	// Danger: file may contain non-integer

	//2. Security: use stringstream for validation and parsing
	std::string raw;
	if(std::getline(file, raw)) {
		std::stringstream ss(raw);
		if(!(ss >> count)) {
			throw std::ios_base::failure("Invalid integer format");
		}
	}
	/////////////////////////////////

	// 3. Buffer overflow risk with fixed-size buffers
	char buffer[50];
	file.read(buffer, 100); // Danger: may overflow buffer

	// 3. Security: use .gcount() to limit read size
	file.read(buffer, sizeof(buffer) - 1);
	std::streamsize bytesRead = file.gcount();	// number of bytes actually read
	buffer[bytesRead] = '\0'; // null-terminate
	///////////////////////////////////////////

	// 4. dangerous file names and path traversal
	std::string user_input;
	// something from user input
	std::ifstream file(user_input);	// Danger: may open unintended files. user can do path traversal
	////////////////////////////////////////////////

	return 0;
}