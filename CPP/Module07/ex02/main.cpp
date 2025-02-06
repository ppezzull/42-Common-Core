#include <iostream>
#include "Array.hpp"

int main() {
    try {
        // Test with int array
        Array<int> intArray(5);
        for (size_t i = 0; i < intArray.size(); ++i) {
            intArray[i] = static_cast<int>(i * 10);
        }

        std::cout << "intArray: ";
        for (size_t i = 0; i < intArray.size(); ++i) {
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;

        // Test with std::string array
        Array<std::string> stringArray(3);
        stringArray[0] = "Hello";
        stringArray[1] = "World";
        stringArray[2] = "C++";

        std::cout << "stringArray: ";
        for (size_t i = 0; i < stringArray.size(); ++i) {
            std::cout << stringArray[i] << " ";
        }
        std::cout << std::endl;

        // Test const array
        const Array<int> constArray = intArray;
        std::cout << "constArray: ";
        for (size_t i = 0; i < constArray.size(); ++i) {
            std::cout << constArray[i] << " ";
        }
        std::cout << std::endl;

        // Test out-of-range access
        std::cout << "Accessing out of range: ";
        std::cout << intArray[10] << std::endl; // This will throw

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
