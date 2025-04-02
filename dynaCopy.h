//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//Carl shiu, 127456192, 2/4/2025
#ifndef SENECA_DYNACOPY_H
#define SENECA_DYNACOPY_H

#include <iostream>

namespace seneca {

    // 1. Two-Argument dynaCopy
    template <typename T>
    T* dynaCopy(const T* sourceArray, int length) {
        T* newArray = new T[length];
        for (int i = 0; i < length; ++i) {
            newArray[i] = sourceArray[i];
        }
        return newArray;
    }

    // 2. Three-Argument dynaCopy
    template <typename T>
    T* dynaCopy(T*& destinationArray, const T* sourceArray, int length) {
        delete[] destinationArray;    
        destinationArray = new T[length];  
        for (int i = 0; i < length; ++i) {
            destinationArray[i] = sourceArray[i]; 
        }
        return destinationArray;
    }

    // 3. prnArray
    template <typename T>
    void prnArray(const T* array, int length) {
        for (int i = 0; i < length; ++i) {
            std::cout << array[i];
            if (i < length - 1) std::cout << ", ";
        }
        std::cout << std::endl;
    }
}

#endif // SENECA_DYNACOPY_H
