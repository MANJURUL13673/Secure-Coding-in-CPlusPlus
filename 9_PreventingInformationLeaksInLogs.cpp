#include <iostream>
#include <string>

void log(const std::string& message) {
    // Simulate logging to a file or console
    std::cout << "[LOG]: " << message << std::endl;
}

int main()
{
    std::string username, password;
    std::cout<<"Username: ";
    std::getline(std::cin, username);

    std::cout<<"Password: ";
    std::getline(std::cin, password);

    log("User '" + username + "' attempted login with password: " + password); // risky pattern, may leak sensitive information in logs
    
    // Simulate auth result
    bool success = (username == "admin" && password == "1234");
    log("Auth success: " + std::string(success ? "true" : "false")); // safer pattern, no sensitive information logged
    
    std::cout << std::endl << std::endl;
    return 0;
}