#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>

// Constructor & Destructor
PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

// parseInput: Convert argv arguments into positive integers,
// and check for errors (non-number, non-positive, or duplicate values).
bool PmergeMe::parseInput(int argc, char **argv) {
    std::vector<int> temp;
    for (int i = 1; i < argc; i++) {
        std::istringstream iss(argv[i]);
        int num;
        // Check if conversion succeeded and no extra characters remain.
        if (!(iss >> num) || !(iss.eof())) {
            std::cerr << "Error: invalid input '" << argv[i] << "'." << std::endl;
            return false;
        }
        if (num <= 0) {
            std::cerr << "Error: non-positive integer '" << num << "' is not allowed." << std::endl;
            return false;
        }
        // Check for duplicates.
        for (size_t j = 0; j < temp.size(); j++) {
            if (temp[j] == num) {
                std::cerr << "Error: duplicate value '" << num << "' detected." << std::endl;
                return false;
            }
        }
        temp.push_back(num);
    }
    // Fill both containers.
    for (size_t i = 0; i < temp.size(); i++) {
        vec.push_back(temp[i]);
        deq.push_back(temp[i]);
    }
    return true;
}

// Display unsorted sequence.
void PmergeMe::display() const {
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

// Binary search for vector.
int PmergeMe::binarySearchVector(const std::vector<int>& sorted, int value) {
    int low = 0;
    int high = sorted.size();
    while (low < high) {
        int mid = (low + high) / 2;
        if (sorted[mid] < value)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

// Binary search for deque.
int PmergeMe::binarySearchDeque(const std::deque<int>& sorted, int value) {
    int low = 0;
    int high = sorted.size();
    while (low < high) {
        int mid = (low + high) / 2;
        if (sorted[mid] < value)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

// Ford–Johnson merge-insert sort for vector.
void PmergeMe::fordJohnsonVector(std::vector<int>& container) {
    if (container.size() <= 1)
        return;
    if (container.size() == 2) {
        if (container[0] > container[1])
            std::swap(container[0], container[1]);
        return;
    }
    std::vector<int> winners;
    std::vector<int> losers;
    size_t i = 0;
    while (i + 1 < container.size()) {
        if (container[i] < container[i+1]) {
            winners.push_back(container[i+1]);
            losers.push_back(container[i]);
        } else {
            winners.push_back(container[i]);
            losers.push_back(container[i+1]);
        }
        i += 2;
    }
    if (i < container.size()) {
        winners.push_back(container[i]);
    }
    // Recursively sort the winners.
    fordJohnsonVector(winners);
    // Insert each loser into the sorted winners using binary insertion.
    for (size_t j = 0; j < losers.size(); j++) {
        int pos = binarySearchVector(winners, losers[j]);
        winners.insert(winners.begin() + pos, losers[j]);
    }
    container = winners;
}

// Ford–Johnson merge-insert sort for deque.
void PmergeMe::fordJohnsonDeque(std::deque<int>& container) {
    if (container.size() <= 1)
        return;
    if (container.size() == 2) {
        if (container[0] > container[1])
            std::swap(container[0], container[1]);
        return;
    }
    std::deque<int> winners;
    std::deque<int> losers;
    size_t i = 0;
    while (i + 1 < container.size()) {
        if (container[i] < container[i+1]) {
            winners.push_back(container[i+1]);
            losers.push_back(container[i]);
        } else {
            winners.push_back(container[i]);
            losers.push_back(container[i+1]);
        }
        i += 2;
    }
    if (i < container.size()) {
        winners.push_back(container[i]);
    }
    // Recursively sort the winners.
    fordJohnsonDeque(winners);
    // Insert each loser into the sorted winners using binary insertion.
    for (size_t j = 0; j < losers.size(); j++) {
        int pos = binarySearchDeque(winners, losers[j]);
        winners.insert(winners.begin() + pos, losers[j]);
    }
    container = winners;
}

// sortVector: Sorts the vector container and returns the processing time in microseconds.
double PmergeMe::sortVector() {
    clock_t start = clock();
    fordJohnsonVector(vec);
    clock_t end = clock();
    return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;
}

// sortDeque: Sorts the deque container and returns the processing time in microseconds.
double PmergeMe::sortDeque() {
    clock_t start = clock();
    fordJohnsonDeque(deq);
    clock_t end = clock();
    return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;
}
