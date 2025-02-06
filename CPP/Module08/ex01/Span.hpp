#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

class Span {
private:
    std::vector<int> numbers;
    unsigned int maxSize;

public:
    Span(unsigned int n);
    Span(const Span& other);
    ~Span();
    Span& operator=(const Span& other);

    void addNumber(int number);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

    void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};

#endif
