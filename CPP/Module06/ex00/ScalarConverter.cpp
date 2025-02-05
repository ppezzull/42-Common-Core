#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }

bool ScalarConverter::isChar(const std::string& literal) {
    return literal.length() == 1 && !isdigit(literal[0]);
}

bool ScalarConverter::isInt(const std::string& literal) {
    char* end;
    std::strtol(literal.c_str(), &end, 10);
    return *end == '\0';
}

bool ScalarConverter::isFloat(const std::string& literal) {
    return literal.find('f') != std::string::npos && literal.find('.') != std::string::npos;
}

bool ScalarConverter::isDouble(const std::string& literal) {
    return literal.find('.') != std::string::npos && literal.find('f') == std::string::npos;
}

void ScalarConverter::convert(const std::string& literal) {
    std::cout << std::fixed;
    std::cout.precision(1);

    if (isChar(literal)) {
        char c = literal[0];
        std::cout << "char: " << c << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;
    } else if (isInt(literal)) {
        long i = std::strtol(literal.c_str(), NULL, 10);
        if (i < INT_MIN || i > INT_MAX) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
        if (isprint(i)) {
            std::cout << "char: " << static_cast<char>(i) << std::endl;
        } else {
            std::cout << "char: Non displayable" << std::endl;
        }
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(i) << std::endl;
    } else if (isFloat(literal)) {
        float f = std::strtof(literal.c_str(), NULL);
        if (isprint(static_cast<int>(f))) {
            std::cout << "char: " << static_cast<char>(f) << std::endl;
        } else {
            std::cout << "char: Non displayable" << std::endl;
        }
        std::cout << "int: " << static_cast<int>(f) << std::endl;
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(f) << std::endl;
    } else if (isDouble(literal)) {
        double d = std::strtod(literal.c_str(), NULL);
        if (isprint(static_cast<int>(d))) {
            std::cout << "char: " << static_cast<char>(d) << std::endl;
        } else {
            std::cout << "char: Non displayable" << std::endl;
        }
        std::cout << "int: " << static_cast<int>(d) << std::endl;
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    } else {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}
