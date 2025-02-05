#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <cmath>
#include <sstream>

class ScalarConverter {
private:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter&);
    ScalarConverter& operator=(const ScalarConverter&);

    static bool isChar(const std::string& literal);
    static bool isInt(const std::string& literal);
    static bool isFloat(const std::string& literal);
    static bool isDouble(const std::string& literal);

public:
    static void convert(const std::string& literal);
};

#endif
