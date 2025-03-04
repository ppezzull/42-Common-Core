#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange {
public:
    BitcoinExchange();
    ~BitcoinExchange();

    bool loadData(const std::string &filename);

    // Process an input file with date | amount lines.
    void processInput(const std::string &filename);

private:
    std::map<std::string, double> exchangeRates;
};

#endif
