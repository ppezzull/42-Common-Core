#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <cstddef> // For size_t

template <typename T>
class Array {
private:
    T* _data;
    size_t _size;

public:
    // Default constructor: creates an empty array
    Array() : _data(NULL), _size(0) {}

    // Parameterized constructor: creates an array of given size
    Array(size_t size) : _data(new T[size]), _size(size) {
        for (size_t i = 0; i < _size; ++i) {
            _data[i] = T(); // Initialize with default value
        }
    }

    // Copy constructor
    Array(const Array& other) : _data(NULL), _size(0) {
        *this = other;
    }

    // Destructor
    ~Array() {
        delete[] _data;
    }

    // Assignment operator
    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] _data;
            _size = other._size;
            _data = new T[_size];
            for (size_t i = 0; i < _size; ++i) {
                _data[i] = other._data[i];
            }
        }
        return *this;
    }

    // Access operator[] for reading and writing
    T& operator[](size_t index) {
        if (index >= _size) {
            throw std::out_of_range("Index out of range");
        }
        return _data[index];
    }

    // Const version of operator[] for reading
    const T& operator[](size_t index) const {
        if (index >= _size) {
            throw std::out_of_range("Index out of range");
        }
        return _data[index];
    }

    // Get the size of the array
    size_t size() const {
        return _size;
    }
};

#endif
