#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

// Default constructor: empty array
template<typename T>
Array<T>::Array() : array(nullptr), size(0) {}

// Constructor with size n
template<typename T>
Array<T>::Array(unsigned int n) : array(new T[n]()), size(n) {}

// Copy constructor (deep copy)
template<typename T>
Array<T>::Array(const Array<T>& other) : array(nullptr), size(0) {
    if (other.size) {
        array = new T[other.size];
        size = other.size;
        for (unsigned int i = 0; i < size; ++i) {
            array[i] = other.array[i];
        }
    }
}

// Copy assignment operator (deep copy + self-assignment check)
template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this != &other) {
        delete[] array; // release current memory
        size = other.size;
        array = other.size ? new T[other.size] : nullptr;
        for (unsigned int i = 0; i < size; ++i) {
            array[i] = other.array[i];
        }
    }
    return *this;
}

// Destructor
template<typename T>
Array<T>::~Array() {
    delete[] array;
}

// Non-const element access with bounds checking
template<typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= size) {
        throw OutOfBounds();
    }
    return array[index];
}

// Const element access with bounds checking
template<typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= size) {
        throw OutOfBounds();
    }
    return array[index];
}

// Return current size
template<typename T>
unsigned int Array<T>::getSize() const {
    return size;
}

#endif // ARRAY_TPP
