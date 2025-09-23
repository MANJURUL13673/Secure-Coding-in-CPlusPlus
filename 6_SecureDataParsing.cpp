// Description: Take input key and value from user and differentiate between key and value

#include<iostream>
#include<string>
#include <map>
#include <sstream>

bool isValidKey(const std::string& key) {
	// Example validation: key must be alphanumeric and non-empty
	if (key.empty()) return false;
	for (char c : key) {
		// check if c is alphanumeric or underscore
		if (!isalnum(c) && c != '_') return false;
	}
	return true;
}

bool isValidValue(const std::string& value) {
	// Example validation: value must be non-empty
	if (value.empty()) return false;
	for (char c : value) {
		if (!std::isdigit(c)) return false; // only digits allowed
	}
	return true;
}

std::map<std::string, std::string> parseSettings(const std::string& input)
{
	std::map<std::string, std::string> result;
	std::istringstream ss(input);
	std::string pair;

	while (std::getline(ss, pair, ',')) {
		size_t eq = pair.find('=');

		//1. Unsafe: no check for missing '=', empty key, or empty value
		// duplicate keys, spaces, or non-numeric values
		
		//1. Safe: validate equal sign at the beginning
		if (eq == std::string::npos || eq == 0 || eq == pair.length() - 1) {
			continue; // skip invalid pairs
		}

		std::string key = pair.substr(0, eq);
		std::string value = pair.substr(eq + 1);

		// 1. Safe: Validate key and value
		if (!isValidKey(key)) continue;
		if (!isValidValue(value)) continue;
		if (result.count(key) > 0) continue; // skip duplicates

		result[key] = value; 
	}
	return result;
}

int main()
{
	std::string rawInput;
	std::cout << "Enter settings (key=value,key=value,...): ";
	std::getline(std::cin, rawInput);

	auto settings = parseSettings(rawInput);

	std::cout << "Parsed Settings:\n";
	for(const auto& [key, value] : settings) {
		std::cout << key << ": " << value << "\n";
	}

	std::cout << std::endl << std::endl;
}