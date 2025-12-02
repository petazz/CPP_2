#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <iomanip>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        _database = other._database;
    }
    return *this;
}

bool BitcoinExchange::isValidDate(const std::string& date) {
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            return false;
    }
    
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    
    if (year < 2009 || year > 2023) 
        return false;

    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    
    return true;
}


bool BitcoinExchange::isValidValue(const std::string& value) {
    std::istringstream iss(value);
    float f;
    char c;
    
    if (!(iss >> f) || (iss >> c))
        return false;
    if (f < 0 || f > 1000)
        return false;
    
    return true;
}

float BitcoinExchange::stringToFloat(const std::string& str) {
    return std::atof(str.c_str());
}

bool BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return false;
    }
    
    std::string line;
    std::getline(file, line); // Skip header
    
    while (std::getline(file, line)) {
        if (line.empty())
            continue;
        
        std::istringstream iss(line);
        std::string date, priceStr;
        
        if (!std::getline(iss, date, ',') || !std::getline(iss, priceStr, ','))
            continue;
        
        // Trim spaces
        date.erase(date.find_last_not_of(" \n\r\t") + 1);
        priceStr.erase(0, priceStr.find_first_not_of(" \n\r\t"));
        priceStr.erase(priceStr.find_last_not_of(" \n\r\t") + 1);
        
        _database[date] = stringToFloat(priceStr);
    }
    
    file.close();
    return true;
}

void BitcoinExchange::processFile(const std::string& filename) {
    std::ifstream file(filename.c_str());
    
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    
    std::string line;
    std::getline(file, line); // Skip header
    
    while (std::getline(file, line)) {
        if (line.empty())
            continue;
        
        std::istringstream iss(line);
        std::string date, valueStr;
        
        if (!std::getline(iss, date, ' ') || !std::getline(iss, valueStr, ' ')) {
            std::cerr << "Error: bad input" << std::endl;
            continue;
        }
        
        // Trim spaces
        date.erase(date.find_last_not_of(" \n\r\t") + 1);
        valueStr.erase(0, valueStr.find_first_not_of(" \n\r\t"));
        valueStr.erase(valueStr.find_last_not_of(" \n\r\t") + 1);
        
        if (!isValidDate(date)) {
            std::cerr << "Error: bad input =>" << date << std::endl;
            continue;
        }
        
        if (!isValidValue(valueStr)) {
            if (stringToFloat(valueStr) < 0)
                std::cerr << "Error: not a positive number." << std::endl;
            else
                std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        
        float value = stringToFloat(valueStr);
        
        // Find the closest date in the database
        std::map<std::string, float>::iterator it = _database.lower_bound(date);
        
        if (it == _database.end() || it->first != date) {
            if (it == _database.begin()) {
                std::cerr << "Error: date not found" << std::endl;
                continue;
            }
            --it;
        }
        
        float btcPrice = it->second;
        float result = value * btcPrice;
        
        std::cout << date << " => " << value << " = " << std::fixed << std::setprecision(2) << result << std::endl;
    }
    
    file.close();
}
