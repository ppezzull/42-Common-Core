#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    
    PmergeMe sorter;
    if (!sorter.parseInput(argc, argv))
        return 1;
    
    std::cout << "Before: ";
    // Display the unsorted sequence.
    sorter.display();
    
    // Sort using the vector container and measure time.
    double vectorTime = sorter.sortVector();
    
    // Sort using the deque container and measure time.
    double dequeTime = sorter.sortDeque();
    
    // Display the sorted sequence.
    std::cout << "After: ";
    sorter.display();
    
    // Display the processing times.
    std::cout << "Time to process a range of " << (argc - 1)
              << " elements with std::vector : " << vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << (argc - 1)
              << " elements with std::deque : " << dequeTime << " us" << std::endl;
    
    return 0;
}
