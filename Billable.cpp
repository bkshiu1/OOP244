/***********************************************************************
// OOP244 Project, Billable Module
//
// Final Project Milestone 5 part 6
// Module: Billable
// Filename: Billable.cpp
// Version 1.0
// Author: Karl Shiu, 131531246, bkshiu1@myseneca.ca
// Revision History
// -----------------------------------------------------------
// Date      Reason
// 2025/04/08  Implemented interface for billable items
// 2025/04/14  Updated for milestone 4
// 2025/04/14  Fixed output formatting with setfill('.') in print()
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iomanip>
#include "Billable.h"

namespace seneca {

    Billable::Billable() {}

    Billable::Billable(const Billable& other) {
        if (other.m_name) {
            m_name = new char[strlen(other.m_name) + 1];
            strcpy(m_name, other.m_name);
        }
        m_price = other.m_price;
    }

    Billable& Billable::operator=(const Billable& other) {
        if (this != &other) {
            delete[] m_name;
            m_name = nullptr;
            if (other.m_name) {
                m_name = new char[strlen(other.m_name) + 1];
                strcpy(m_name, other.m_name);
            }
            m_price = other.m_price;
        }
        return *this;
    }

    Billable::~Billable() {
        delete[] m_name;
    }

    std::ostream& Billable::print(std::ostream& ostr) const {
        ostr << std::left << std::setw(33) << std::setfill('.') << m_name;
        ostr << std::right << std::setw(7) << std::setfill(' ') << std::fixed << std::setprecision(2) << m_price;
        return ostr;
    }

    Billable::operator const char* () const {
        return m_name;
    }

    void Billable::setName(const char* name) {
        delete[] m_name;
        m_name = ut.alocpy(name);
    }

    void Billable::setPrice(double price) {
        m_price = price;
    }

    double Billable::getBasePrice() const {
        return m_price;
    }

}
