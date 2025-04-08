/***********************************************************************
// OOP244 Project, Utils Module
//
// Final Project Milestone 2
// Module: Utils
// Filename: Utils.cpp
// Version 1.0
// Author: Karl Shiu, 131531246, bkshiu1@myseneca.ca
// Revision History
// -----------------------------------------------------------
// Date      Reason
// 2025/04/08  Completed Milestone 2 implementation
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
***********************************************************************/
#include <iostream>
#include <limits>
#include "Utils.h"
using namespace std;

namespace seneca {
    Utils ut;

    char* Utils::alocpy(const char* src) const {
        char* des{};
        return alocpy(des, src);
    }

    char* Utils::alocpy(char*& des, const char* src) const {
        delete[] des;
        des = nullptr;
        if (src) {
            des = new char[strlen(src) + 1];
            strcpy(des, src);
        }
        return des;
    }

    char* Utils::strcpy(char* des, const char* src) const {
        int i;
        for (i = 0; src[i]; i++) des[i] = src[i];
        des[i] = char(0);
        return des;
    }

    int Utils::strlen(const char* str) const {
        int len;
        for (len = 0; str[len]; len++);
        return len;
    }

    bool Utils::isspace(char ch) const {
        return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f' || ch == '\r';
    }

    bool Utils::isspace(const char* cstring) const {
        while (cstring && isspace(*cstring)) {
            cstring++;
        }
        return cstring && *cstring == 0;
    }

    int Utils::getInt() const {
        int value;
        bool valid = false;
        while (!valid) {
            cin.clear();
            cin >> ws;
            if (cin.peek() == '\n') {
                cout << "You must enter a value: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if (!(cin >> value)) {
                cout << "Invalid integer: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if (cin.get() != '\n') {
                cout << "Only an integer please: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                valid = true;
            }
        }
        return value;
    }

    int Utils::getInt(int min, int max) const {
        int val;
        bool valid = false;
        while (!valid) {
            val = getInt();
            if (val < min || val > max) {
                cout << "Invalid value: [" << min << " <= value <= " << max << "], try again: ";
            }
            else {
                valid = true;
            }
        }
        return val;
    }
}
