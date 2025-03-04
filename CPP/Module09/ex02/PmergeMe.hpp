#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

class PmergeMe {
public:
    PmergeMe();
    ~PmergeMe();

    // Parses the command-line arguments.
    // Returns false if any argument is not a positive integer or if duplicates are detected.
    bool parseInput(int argc, char **argv);

    // Displays the unsorted sequence (using the vector container).
    void display() const;

    // Sorts the vector container using the Ford–Johnson merge-insert algorithm.
    // Returns the processing time in microseconds.
    double sortVector();

    // Sorts the deque container using the Ford–Johnson merge-insert algorithm.
    // Returns the processing time in microseconds.
    double sortDeque();

private:
    std::vector<int> vec;
    std::deque<int> deq;

    // Recursive merge-insert sort for a vector.
    void fordJohnsonVector(std::vector<int>& container);

    // Recursive merge-insert sort for a deque.
    void fordJohnsonDeque(std::deque<int>& container);

    // Helper: binary search insertion index for vector.
    int binarySearchVector(const std::vector<int>& sorted, int value);

    // Helper: binary search insertion index for deque.
    int binarySearchDeque(const std::deque<int>& sorted, int value);
};

#endif
