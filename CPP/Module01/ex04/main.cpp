#include "Replace.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <string1> <string2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty()) {
        std::cerr << "Error: string1 (s1) cannot be empty." << std::endl;
        return 1;
    }

    if (!Replace::performReplacement(filename, s1, s2)) {
        return 1; 
    }

    std::cout << "Replacement complete. Output written to " << filename << ".replace" << std::endl;
    return 0;
}

