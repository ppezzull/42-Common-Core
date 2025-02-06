#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main() {
    try {
        std::vector<int> numbers;

        numbers.push_back(10);
        numbers.push_back(20);
        numbers.push_back(30);
        numbers.push_back(40);
        numbers.push_back(50);

        std::cout << "Looking for 30 in the container..." << std::endl;
        std::vector<int>::iterator it = easyfind(numbers, 30);
        std::cout << "Found: " << *it << std::endl;

        std::cout << "Looking for 99 in the container..." << std::endl;
        it = easyfind(numbers, 99); // This will throw an exception
        std::cout << "Found: " << *it << std::endl;

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
