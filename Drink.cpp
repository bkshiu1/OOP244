/***********************************************************************
// OOP244 Project, Drink Module
//
// Final Project Milestone 4
// Module: Drink
// Filename: Drink.cpp
// Version 1.1
// Author: Karl Shiu, 131531246, bkshiu1@myseneca.ca
// Revision History
// -----------------------------------------------------------
// Date      Reason
// 2025/04/08  Implemented Drink module logic
// 2025/04/13  Implemented ms3 requirements
// 2025/04/14  Updated for ms4: added clone()
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
***********************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include "Drink.h"
#include "Menu.h"

using namespace std;

namespace seneca {

    Drink::Drink() : m_ordered(false), m_size('\0') {}
    Drink::~Drink() {}
    Drink::Drink(const Drink& src)
        : Billable(src), m_ordered(src.m_ordered), m_size(src.m_size) {
    }
    Drink& Drink::operator=(const Drink& src) {
        if (this != &src) {
            Billable::operator=(src);
            m_ordered = src.m_ordered;
            m_size = src.m_size;
        }
        return *this;
    }

    ostream& Drink::print(ostream& ostr) const {
        ostr << left << setw(28) << setfill('.') << (const char*)*this;

        switch (m_size) {
        case 'S': ostr << "SML.."; break;
        case 'M': ostr << "MID.."; break;
        case 'L': ostr << "LRG.."; break;
        case 'X': ostr << "XLR.."; break;
        default:  ostr << "????."; break;
        }

        ostr << right << setw(7) << setfill(' ') << fixed << setprecision(2) << price();
        return ostr;
    }

    bool Drink::order() {
        Menu sizeMenu("Drink Size Selection", "Back", 1, 5);
        sizeMenu << "Small" << "Medium" << "Large" << "Extra Large";
        int sel = sizeMenu.select();

        const char codes[] = { 'S', 'M', 'L', 'X' };
        if (sel >= 1 && sel <= 4) {
            m_size = codes[sel - 1];
            m_ordered = true;
        }
        else {
            m_ordered = false;
        }

        return m_ordered;
    }

    bool Drink::ordered() const {
        return m_size == 'S' || m_size == 'M' || m_size == 'L' || m_size == 'X';
    }

    std::ifstream& Drink::read(std::ifstream& file) {
        std::string name;
        double price;

        if (getline(file, name, ',') && file >> price) {
            file.ignore(1000, '\n');
            setName(name.c_str());  // <-- Make sure this sets the Billable name
            setPrice(price);
            m_size = '\0';
        }

        return file;
    }

    double Drink::price() const {
        double multiplier = 0.0;
        switch (m_size) {
        case 'S': multiplier = 0.5; break;
        case 'M': multiplier = 0.75; break;
        case 'L': multiplier = 1.0; break;
        case 'X': multiplier = 1.5; break;
        }
        return getBasePrice() * multiplier;
    }


    Billable* Drink::clone() const {
        return new Drink(*this);
    }

}
