#include <iostream>
#include <fstream>
#include <regex>
#include <string>

//  This searches within a separate text document

int main() {
    std::string filename = "searchDoc.txt";
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Unable to open file.\n";
        return 1;
    }

    std::string word;
    std::cout << "Enter a word to search for: ";
    std::cin >> word;

    std::regex pattern(word);
    std::string line;

    bool found = false;

    while (std::getline(file, line)) {
        if (std::regex_search(line, pattern)) {
            found = true;
            break;
        }
    }

    if (found)
        std::cout << "Word found in file!\n";
    else
        std::cout << "Word NOT found.\n";

    return 0;
}