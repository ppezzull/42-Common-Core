#include "Span.hpp"

Span::Span(unsigned int n) : maxSize(n) {}

Span::Span(const Span& other) : numbers(other.numbers), maxSize(other.maxSize) {}

Span::~Span() {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        numbers = other.numbers;
        maxSize = other.maxSize;
    }
    return *this;
}

void Span::addNumber(int number) {
    if (numbers.size() >= maxSize) {
        throw std::out_of_range("Span is full");
    }
    numbers.push_back(number);
}

unsigned int Span::shortestSpan() const {
    if (numbers.size() < 2) {
        throw std::logic_error("Not enough numbers to calculate span");
    }

    std::vector<int> sortedNumbers = numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    unsigned int shortest = static_cast<unsigned int>(-1);
    for (size_t i = 1; i < sortedNumbers.size(); ++i) {
        unsigned int diff = sortedNumbers[i] - sortedNumbers[i - 1];
        if (diff < shortest) {
            shortest = diff;
        }
    }

    return shortest;
}

unsigned int Span::longestSpan() const {
    if (numbers.size() < 2) {
        throw std::logic_error("Not enough numbers to calculate span");
    }

    int min = *std::min_element(numbers.begin(), numbers.end());
    int max = *std::max_element(numbers.begin(), numbers.end());
    return max - min;
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (std::distance(begin, end) + numbers.size() > maxSize) {
        throw std::out_of_range("Adding this range exceeds the Span's capacity");
    }
    numbers.insert(numbers.end(), begin, end);
}
