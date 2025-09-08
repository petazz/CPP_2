#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>

template<typename T>
class Array {
private:
    T *array;
    unsigned int size;

public:
    Array();
    Array(unsigned int n);
    Array(const Array &other);
    Array &operator=(const Array &other);
    ~Array();

    T &operator[](unsigned int index);
    const T &operator[](unsigned int index) const;
    unsigned int getSize() const;

    class OutOfBounds : public std::exception {
        public:
            const char* what() const throw() {
                return "Array index out of bounds";
            }
    };
};

#include "Array.tpp"

#endif