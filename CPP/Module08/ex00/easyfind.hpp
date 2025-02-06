#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <iterator>

// Exception class for when the integer is not found
class NotFoundException : public std::exception {
public:
    const char* what() const throw() {
        return "Element not found in the container";
    }
};

// Template function to find an integer in a container
template <typename T>
typename T::iterator easyfind(T& container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw NotFoundException();
    }
    return it;
}

#endif
