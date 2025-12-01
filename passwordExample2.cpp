#include <iostream>
#include <regex>
#include <string>

bool isValidPassword(const std::string& password) {
    // Fixed regex:
    //  - (?=.*[a-z])  lowercase
    //  - (?=.*[A-Z])  uppercase
    //  - (?=.*\d)     digit
    //  - (?=.*[\W_])  special char
    //  - .{8,}        length >= 8
    std::regex pattern("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[\\W_]).{8,}$");
    return std::regex_match(password, pattern);
}

int main() {
    std::string password;

    std::cout << "Enter a password to validate: ";
    std::getline(std::cin, password);

    if (isValidPassword(password)) {
        std::cout << "Password is VALID\n";
    } else {
        std::cout << "Password is INVALID\n";
        std::cout << "Requirements:\n";
        std::cout << "  - At least 8 characters\n";
        std::cout << "  - At least one lowercase letter\n";
        std::cout << "  - At least one uppercase letter\n";
        std::cout << "  - At least one digit\n";
        std::cout << "  - At least one special character\n";
    }

    return 0;
}
