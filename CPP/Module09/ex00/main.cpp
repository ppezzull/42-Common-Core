#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    BitcoinExchange exchange;

    if (!exchange.loadData("data.csv")) {
        std::cerr << "Error: could not load exchange data from data.csv" << std::endl;
        return 1;
    }

    exchange.processInput(argv[1]);
    return 0;
}
