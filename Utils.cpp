/***********************************************************************
// OOP244 Project, Utils Module
//
// Final Project Milestone 5 part 5
// Module: Utils
// Filename: Utils.cpp
// Version 1.0
// Author: Karl Shiu, 131531246, bkshiu1@myseneca.ca
// Revision History
// -----------------------------------------------------------
// Date      Reason
// 2025/04/13  Added getlineInput for safe <ENTER> handling
// 2025/04/13  Implemented ms3 requirements
// 2025/04/14  Refined input or formatting behavior for MS4
// 2025/04/15  Updated function getInt() for ms56 requirements
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include "Utils.h"
#include <cctype>
#include <cstring>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

using namespace std;

namespace seneca {


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

    int Utils::getInt(int min, int max) const{
        int value;
        bool done = false;
        char next;

        while (!done) {
            std::string line;
            std::getline(std::cin, line);

            if (line.empty()) {
                std::cout << "You must enter a value: ";
                continue;
            }

            std::istringstream input(line);
            if (!(input >> value)) {
                std::cout << "Invalid integer: ";
            }
            else if (input >> next) {
                std::cout << "Only an integer please: ";
            }
            else if (value < min || value > max) {
                std::cout << "Invalid value: [" << min << "<= value <=" << max << "], try again: ";
            }
            else {
                done = true;
            }

            if (!done) std::cout.flush();
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
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            buffer[0] = '\0';
        }
    }

    char* Utils::makeBillFileName(char* filename, size_t billNo) const {
        char temp[21] = "bill_";
        int idx = 5;
        size_t tempNo = billNo;
        do {
            temp[idx++] = (tempNo % 10) + '0';
            tempNo /= 10;
        } while (tempNo > 0);

        temp[idx] = '\0';
        for (int i = 0; ".txt"[i]; ++i) temp[idx++] = ".txt"[i];
        temp[idx] = '\0';
        strcpy(filename, temp);
        return filename;
    }

    Utils ut;
}
