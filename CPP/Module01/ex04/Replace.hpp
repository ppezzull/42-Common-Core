#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <string>

class Replace {
public:
    static bool performReplacement(const std::string &filename, const std::string &s1, const std::string &s2);
private:
    static std::string replaceOccurrences(const std::string &content, const std::string &s1, const std::string &s2);
};

#endif
