#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"

// Define uintptr_t manually for C++98 compatibility
typedef unsigned long uintptr_t;

class Serializer {
private:
    Serializer();
    ~Serializer();
    Serializer(const Serializer&);
    Serializer& operator=(const Serializer&);

public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif
