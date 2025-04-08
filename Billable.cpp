/***********************************************************************
// OOP244 Project, Billable Module
//
// Final Project Milestone 3
// Module: Billable
// Filename: Billable.cpp
// Version 1.0
// Author: Karl Shiu, 131531246, bkshiu1@myseneca.ca
// Revision History
// -----------------------------------------------------------
// Date      Reason
// 2025/04/08  Created Billable module
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include "Billable.h"
#include <cstring>

namespace seneca {

    Billable::Billable() : m_name(nullptr), m_price(0.0) {}

    Billable::Billable(const Billable& src) {
        m_name = nullptr;
        *this = src;
    }

    Billable& Billable::operator=(const Billable& src) {
        if (this != &src) {
            name(src.m_name);
            m_price = src.m_price;
        }
        return *this;
    }

    Billable::~Billable() {
        delete[] m_name;
    }

    void Billable::name(const char* name) {
        delete[] m_name;
        if (name && name[0] != '\0') {
            m_name = new char[strlen(name) + 1];
            std::strcpy(m_name, name);
        }
        else {
            m_name = nullptr;
        }
    }

    void Billable::price(double value) {
        m_price = value;
    }

    double Billable::price() const {
        return m_price;
    }

    Billable::operator const char* () const {
        return m_name;
    }

    double operator+(double money, const Billable& B) {
        return money + B.price();
    }

    double& operator+=(double& money, const Billable& B) {
        return money += B.price();
    }

} // namespace seneca
