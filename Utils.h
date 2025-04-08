/***********************************************************************
// OOP244 Project, Utils Module
//
// Final Project Milestone 2
// Module: Utils
// Filename: Utils.h
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
#ifndef SENECA_UTILS_H
#define SENECA_UTILS_H

namespace seneca {
    class Utils {
    public:
        char* alocpy(const char* src) const;
        char* alocpy(char*& des, const char* src) const;
        char* strcpy(char* des, const char* src) const;
        int strlen(const char* str) const;
        bool isspace(char ch) const;
        bool isspace(const char* cstring) const;

        int getInt() const;
        int getInt(int min, int max) const;
    };

    extern Utils ut;
}
#endif // !SENECA_UTILS_H
