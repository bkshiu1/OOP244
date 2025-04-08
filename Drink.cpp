/***********************************************************************
// OOP244 Project, Drink Module
//
// Final Project Milestone 3
// Module: Drink
// Filename: Drink.cpp
// Version 1.0
// Author: Karl Shiu, 131531246, bkshiu1@myseneca.ca
// Revision History
// -----------------------------------------------------------
// Date      Reason
// 2025/04/08  Created Drink module
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
***********************************************************************/

#include "Drink.h"
#include "Menu.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>

using namespace std;

namespace seneca {

    Drink::Drink() : m_size('\0') {}

    ostream& Drink::print(ostream& ostr) const {
        ostr << left << setw(28) << setfill('.') << (const char*)(*this);

        if (!ordered()) {
            ostr << ".....";
        }
        else {
            switch (m_size) {
            case 'S': ostr << "SML.."; break;
            case 'M': ostr << "MID.."; break;
            case 'L': ostr << "LRG.."; break;
            case 'X': ostr << "XLR.."; break;
            }
        }

        ostr << right << setw(7) << setfill(' ') << fixed << setprecision(2) << price();
        return ostr;
    }

    bool Drink::order() {
        Menu sizeMenu("Drink Size Selection", "Exit", 1, 4);
        sizeMenu << "Small" << "Medium" << "Large" << "Extra Large";

        size_t selection = sizeMenu.select();
        m_size = '\0';

        switch (selection) {
        case 1: m_size = 'S'; break;
        case 2: m_size = 'M'; break;
        case 3: m_size = 'L'; break;
        case 4: m_size = 'X'; break;
        default: return false;
        }

        return true;
    }

    bool Drink::ordered() const {
        return m_size != '\0';
    }

    ifstream& Drink::read(ifstream& file) {
        string name;
        double price = 0.0;

        if (getline(file, name, ',') && file >> price) {
            file.ignore(1000, '\n');
            this->name(name.c_str());
            this->price(price);
            m_size = '\0';
        }
        return file;
    }

    double Drink::price() const {
        double base = Billable::price();
        if (!ordered() || m_size == 'L') return base;
        if (m_size == 'S') return base * 0.5;
        if (m_size == 'M') return base * 0.75;
        if (m_size == 'X') return base * 1.5;
        return base;
    }

} // namespace seneca