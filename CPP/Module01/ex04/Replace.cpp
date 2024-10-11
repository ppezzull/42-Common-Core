#include "Replace.hpp"
#include <iostream>
#include <fstream>

std::string Replace::replaceOccurrences(const std::string &content, const std::string &s1, const std::string &s2)
{
    std::string result;
    size_t pos = 0;
    size_t startPos = 0;

    if (s1.empty())
    {
        return content;
    }

    while ((pos = content.find(s1, startPos)) != std::string::npos)
    {
        result.append(content, startPos, pos - startPos);
        result.append(s2);
        startPos = pos + s1.length();
    }

    result.append(content, startPos, content.length() - startPos);
    return result;
}

bool Replace::performReplacement(const std::string &filename, const std::string &s1, const std::string &s2)
{
    // Convert std::string to const char* using c_str() for C++98 compatibility
    std::ifstream inputFile(filename.c_str());  
    if (!inputFile)
    {
        std::cerr << "Error: Could not open file '" << filename << "'." << std::endl;
        return false;
    }

    std::ofstream outputFile((filename + ".replace").c_str());  // Use c_str() here too
    if (!outputFile)
    {
        std::cerr << "Error: Could not create output file '" << filename << ".replace'." << std::endl;
        return false;
    }

    // Read the entire content of the input file
    std::string content((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    // Replace the occurrences of s1 with s2 in the content
    std::string replacedContent = replaceOccurrences(content, s1, s2);

    // Write the replaced content to the output file
    outputFile << replacedContent;

    inputFile.close();
    outputFile.close();
    return true;
}
