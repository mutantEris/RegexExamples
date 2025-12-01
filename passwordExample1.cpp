#include <iostream>
#include <regex>
#include <string>

bool isValidPassword(const std::string& password) {
    std::regex pattern("^.{8,}$");  // At least 8 characters
    return std::regex_match(password, pattern);
}

int main() {
    std::string password;

    std::cout << "Enter a password to validate: ";
    std::getline(std::cin, password);

    if (isValidPassword(password)) {
        std::cout << "Password is VALID\n";
    } else {
        std::cout << "Password is INVALID (must be at least 8 characters)\n";
    }

    return 0;
}
