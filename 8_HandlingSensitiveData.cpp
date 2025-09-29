#include <iostream>
#include <string>

// Suggestion:
// 1. Don't use std::string for secrets
// 2. Wipe memory right after use
// 3. Use platform-safe erase function

int main()
{
    std::string password = getInput();  // risky pattern, data still stores in the memory, maybe keep data after destruction
    char password[64];              // not clearing buffers

    std::fill(std::begin(password), std::end(password), '\0'); // zeroing the buffer by overwritten
    return 0;
}