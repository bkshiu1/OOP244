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
#include "Billable.h"
#include "Utils.h"
#include <cstring>
#include <iostream>

using namespace std;

namespace seneca {

    Billable::Billable() : m_name(nullptr), m_price(0.0) {}

    Billable::Billable(const Billable& other) {
        *this = other;
    }

    Billable& Billable::operator=(const Billable& other) {
        if (this != &other) {
            delete[] m_name;
            m_name = ut.alocpy(other.m_name);
            m_price = other.m_price;
        }
        return *this;
    }

    Billable::~Billable() {
        delete[] m_name;
    }

    void Billable::price(double value) {
        m_price = value;
    }

    void Billable::name(const char* name) {
        delete[] m_name;
        m_name = ut.alocpy(name);
    }

    double Billable::price() const {
        return m_price;
    }

    Billable::operator const char* () const {
        return m_name;
    }

    double operator+(double money, const Billable& B) {
        if (B.ordered()) money += B.price();
        return money;
    }

    double& operator+=(double& money, const Billable& B) {
        if (B.ordered()) money += B.price();
        return money;
    }
}