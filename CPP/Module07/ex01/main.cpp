#include <iostream>
#include "iter.hpp"

// Function to increment an integer
void increment(int& x) {
    x += 1;
}

// Function to print an integer
void print(int& x) {
    std::cout << x << " ";
}

// Function to append "!" to a string
void appendExclamation(std::string& str) {
    str += "!";
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    size_t numLength = sizeof(numbers) / sizeof(numbers[0]);

    std::cout << "Original array: ";
    iter(numbers, numLength, print);
    std::cout << std::endl;

    iter(numbers, numLength, increment);

    std::cout << "After increment: ";
    iter(numbers, numLength, print);
    std::cout << std::endl;

    std::string strings[] = {"hello", "world", "iter"};
    size_t strLength = sizeof(strings) / sizeof(strings[0]);

    std::cout << "Original strings: ";
    for (size_t i = 0; i < strLength; ++i) {
        std::cout << strings[i] << " ";
    }
    std::cout << std::endl;

    iter(strings, strLength, appendExclamation);

    std::cout << "After modification: ";
    for (size_t i = 0; i < strLength; ++i) {
        std::cout << strings[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
