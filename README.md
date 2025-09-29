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

- **7_AvoidCStyleString.cpp**  
  Explores the risks of using C-style strings, such as buffer overflows, lack of automatic memory management, and unsafe string manipulation functions. Shows how to use `std::string` and other modern C++ features to write safer and more reliable code.

- **8_HandlingSensitiveData.cpp**  
  It discuss on handling and clearing sensitive data. It suggests that `std::string` should not use for secret or sensitive data, if use then overwrite the memory after completing the task.

- **9_PreventingInformationLeaksInLogs.cpp**  
  Demonstrates the risks of logging sensitive information, such as passwords or secrets, which can lead to information leaks if logs are exposed. Shows safer logging practices by avoiding the inclusion of confidential data in log messages and only recording non-sensitive events or outcomes.

- **10_HackingTheHardcodedPassword.txt**  
  Highlights the dangers of hardcoding passwords or secrets directly in source code or configuration files. Demonstrates how attackers can easily discover and exploit hardcoded credentials, and emphasizes the importance of using secure methods for credential management, such as environment variables or secure vaults, instead of embedding sensitive information in code.

- **11_SmartPointers.txt**  
  Explains the advantages of using smart pointers in C++ for automatic and safe memory management. Highlights how smart pointers like `std::unique_ptr`, `std::shared_ptr`, and `std::weak_ptr` help prevent memory leaks, dangling pointers, and double-free errors, making code more robust and secure compared to manual memory management with raw pointers.