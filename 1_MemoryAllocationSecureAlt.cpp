#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <fstream>	// for file streams
#include <limits>	// for input validation

//4. Dangling references -> returns a destroyed object///////////////////
std::string& getName() {
	std::string name = "admin";
	return name;	// danger: returning reference to local
}

// 4. Safer option to return value instead 
std::string getNameAlt() {
	return "admin";
}
/// //////////////////////////////////////////////////////


int main()
{
	//1. Raw pointers for dynamic memory allocation
	char* name = (char*)malloc(100);

	// 1a. dange: no bouds checking on strcpy////
	//strcpy(name, "Eduardo");

	// 1a. alternatives: safer functions////
	strncpy(name, "Eduardo", sizeof(name) - 1); // safer, but must ensure null-termination
	name[sizeof(name) - 1] = '\0'; // ensure null-termination
	////////////////////////////////////

	std::cout << "Name: " << name << std::endl;
	free(name);	// must remember to free

	// alternative secure implementations://////////////////////////////////////
	// 1. Use std::string instead of raw char* and malloc/free
	std::string nameAlt = "Eduardo";
	std::cout << "Name: " << nameAlt << std::endl;
	////////////////////////////////////////////////////////////////////////////

	//2. C-Style arrays with fixed size
	int scores[5] = { 10, 20, 30, 40, 50 };
	std::cout << "Accessing 6th score (out of bounds): " << scores[5] << std::endl; // Undefined behavior

	// alternative secure implementations://////////////////////////////////////
	// 2. Use std::array with bounds-checked access
	std::array<int, 5> scoresAlt = { 95, 88, 76, 100, 67 };
	try {
		std::cout << "Accessing 6th score safely: " << scoresAlt.at(5) << std::endl; // This will throw an exception
	
	}
	catch (const std::out_of_range& e) {
		std::cerr << "Caught out_of_range error: " << e.what() << std::endl;
	}
	////////////////////////////////////////////////////////////////////////////

	//3. Manual resource management (FILE*)
	FILE* f = fopen("sample.txt", "w");
	if (f) {
		fputs("Hello, World!\n", f);
		fclose(f); // must remember to close
	}

	// alternative secure implementation:///////////////////////////////////////////////
	//3. Use RAII with std::ofstream for file handling
	{
		std::ofstream ofs("sample.txt");
		if (ofs) {
			ofs << "This is a test.\n";
		}
		else {
			std::cerr << "Error opening file for writing." << std::endl;
		}
	}	// file is automatically closed here
	////////////////////////////////////////////////////////////////////////////////////

	// 5. Pointer arithmetic outside bounds/////
	int arr[4] = { 1, 2, 3, 4 };
	int* p = arr + 5;	// danger: out-of-bounds pointer
	////////////////////////////////////////////

	// 6. implicit narrowing conversions////
	char c = 300;	// danger: truncation, value becomes 44

	// alternatives:
	//6. static analysis or explicit casting to make intent clear:
	c = static_cast<char>(300 & 0xFF);
	std::cout << c << std::endl;
	//////////////////////////////////////////////////

	// 7. signed and unsigned mismatch////////////
	int i = -1;
	size_t s = i;	// danger: implicit conversion
	//////////////////////////////////////////////

	std::cout << std::endl << std::endl;
	return 0;
}