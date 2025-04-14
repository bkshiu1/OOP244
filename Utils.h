/***********************************************************************
// OOP244 Project, Utils Module
//
// Final Project Milestone 3
// Module: Utils
// Filename: Utils.h
// Version 1.0
// Author: Karl Shiu, 131531246, bkshiu1@myseneca.ca
// Revision History
// -----------------------------------------------------------
// Date      Reason
// 2025/04/13  Added getlineInput for robust blank line capture
// 2025/04/13  Implemented ms3 requirements
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
        char* alocpy(const char* str) const;
        char* alocpy(char*& destination, const char* source) const;
        int getInt(int min, int max) const;
        bool isspace(const char* str) const;
        void getlineInput(char* buffer, int length) const;
    };
    extern Utils ut;
}
#endif