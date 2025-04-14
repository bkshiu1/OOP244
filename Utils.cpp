/***********************************************************************
// OOP244 Project, Utils Module
//
// Final Project Milestone 3
// Module: Utils
// Filename: Utils.cpp
// Version 1.0
// Author: Karl Shiu, 131531246, bkshiu1@myseneca.ca
// Revision History
// -----------------------------------------------------------
// Date      Reason
// 2025/04/13  Added getlineInput for safe <ENTER> handling
// 2025/04/13  Implemented ms3 requirements
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <limits>
#include <cctype>  // for std::isspace
#include "Utils.h"



using namespace std;

namespace seneca {

    Utils ut;

    char* Utils::alocpy(const char* str) const {
        if (!str) return nullptr;
        char* copy = new char[strlen(str) + 1];
        strcpy(copy, str);
        return copy;
    }

    char* Utils::alocpy(char*& destination, const char* source) const {
        delete[] destination;
        return destination = alocpy(source);
    }

    int Utils::getInt(int min, int max) const {
        int value;
        bool done = false;
        while (!done) {
            cin >> value;
            if (cin.fail() || value < min || value > max) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid value, try again: ";
            }
            else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                done = true;
            }
        }
        return value;
    }

    bool Utils::isspace(const char* str) const {
        if (str == nullptr) return true;
        while (*str) {
            if (!std::isspace(static_cast<unsigned char>(*str))) return false;
            ++str;
        }
        return true;
    }


    void Utils::getlineInput(char* buffer, int length) const {
        cin.getline(buffer, length);
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            buffer[0] = '\0';
        }
    }
}
