# Secure-Coding-in-CPlusPlus

This repository demonstrates common security pitfalls in C++ programming and provides safer alternatives for each scenario. Each example is self-contained in its own file, with clear comments highlighting both insecure and secure coding practices.

## Contents

- **1_MemoryAllocationSecureAlt.cpp**  
  Shows the dangers of raw pointers, manual memory management, array bounds, resource leaks, pointer arithmetic, and implicit conversions. Demonstrates safer alternatives using `std::string`, `std::array`, and RAII.

- **2_MacroDefinationSecure.cpp**  
  Illustrates macro pitfalls, such as operator precedence issues, and how to write safer macros using parentheses.

- **3_SafeNumericConversion.cpp**  
  Explains the risks of unsafe numeric conversions and input parsing. Shows how to use `std::from_chars` for robust, exception-free string-to-integer conversion and proper bounds checking.

- **4_StringVulnerabilities.cpp**  
  Highlights format string vulnerabilities in C++ I/O functions and demonstrates how to avoid them by always using fixed format strings.

- **5_SafetyInFileInput.cpp**  
  Discusses secure file input handling, including file existence checks, safe parsing, buffer overflow prevention, and the dangers of trusting file names or paths from user input.

- **6_SecureDataParsing.cpp**  
  Demonstrates secure parsing of key-value input from users, including validation of keys and values, duplicate detection, and robust error handling.

- **AvoidCStyleString.cpp**  
  Explores the risks of using C-style strings, such as buffer overflows, lack of automatic memory management, and unsafe string manipulation functions. Shows how to use `std::string` and other modern C++ features to write safer and more reliable code.