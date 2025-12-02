#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange {
    private:
        std::map<std::string, float> _database;
        
        bool isValidDate(const std::string& date);
        bool isValidValue(const std::string& value);
        float stringToFloat(const std::string& str);
        
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        
        bool loadDatabase(const std::string& filename);
        void processFile(const std::string& filename);
};

#endif
