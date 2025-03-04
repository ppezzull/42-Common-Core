#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::loadData(const std::string &filename) {
    std::ifstream file(filename.c_str());
    if (!file)
        return false;

    std::string line;

    std::getline(file, line);

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date;
        std::string rateStr;
        if (!std::getline(ss, date, ','))
            continue;
        if (!std::getline(ss, rateStr))
            continue;
        double rate = atof(rateStr.c_str());
        exchangeRates[date] = rate;
    }
    return true;
}

void BitcoinExchange::processInput(const std::string &filename) {
    std::ifstream file(filename.c_str());
    if (!file) {
        std::cerr << "Error: cannot open file " << filename << std::endl;
        return;
    }

    std::string line;

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date;
        std::string amountStr;
        if (!std::getline(ss, date, '|'))
            continue;
        if (!std::getline(ss, amountStr))
            continue;

        date.erase(0, date.find_first_not_of(" \t"));
        date.erase(date.find_last_not_of(" \t") + 1);
        amountStr.erase(0, amountStr.find_first_not_of(" \t"));
        amountStr.erase(amountStr.find_last_not_of(" \t") + 1);

        double amount = atof(amountStr.c_str());

        std::map<std::string, double>::iterator it = exchangeRates.find(date);
        if (it != exchangeRates.end()) {
            double result = amount * it->second;
            std::cout << date << " => " << amount << " = " << result << std::endl;
        } else {
            std::cout << "No rate available for date: " << date << std::endl;
        }
    }
}
