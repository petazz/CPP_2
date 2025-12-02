#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./btc <filename>" << std::endl;
        return 1;
    }
    
    BitcoinExchange exchange;
    
    if (!exchange.loadDatabase("data.csv"))
        return 1;
    
    exchange.processFile(argv[1]);
    
    return 0;
}
