#include <iostream>
#include "Span.hpp"

int main() {
    try {
        Span sp(20);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);


        // int arr[] = {1, 2, 3, 4, 5};
        // std::vector<int> additionalNumbers(arr, arr + sizeof(arr) / sizeof(int));
        // sp.addRange(additionalNumbers.begin(), additionalNumbers.end());

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

        Span largeSpan(10000);
        std::vector<int> range;
        for (int i = 0; i < 10000; ++i) {
            range.push_back(i);
        }

        largeSpan.addRange(range.begin(), range.end());
        std::cout << "Large Span - Shortest Span: " << largeSpan.shortestSpan() << std::endl;
        std::cout << "Large Span - Longest Span: " << largeSpan.longestSpan() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
