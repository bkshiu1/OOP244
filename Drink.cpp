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
// 2025/04/08  Implemented Drink module logic
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
***********************************************************************/
#include "Drink.h"
#include "Menu.h"
#include <iomanip>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

namespace seneca {

    ostream& Drink::print(ostream& ostr) const {
        ostr << left << setw(28) << setfill('.') << (const char*)(*this);

        const char* sizes[] = { "SML..", "MID..", "LRG..", "XLR.." };
        switch (m_size) {
        case 'S': ostr << sizes[0]; break;
        case 'M': ostr << sizes[1]; break;
        case 'L': ostr << sizes[2]; break;
        case 'X': ostr << sizes[3]; break;
        default: ostr << "....."; break;
        }

        ostr << right << setw(7) << setfill(' ') << fixed << setprecision(2) << price();
        return ostr;
    }

    Drink::Drink() {
        m_size = '\0';
    }
    bool Drink::order() {
        Menu sizeMenu("Drink Size Selection", "Back", 3, 3);
        sizeMenu << "Small" << "Medium" << "Larg" << "Extra Large";
        size_t sel = sizeMenu.select();

        const char codes[] = "SMLX";
        if (sel >= 1 && sel <= 4) {
            m_size = codes[sel - 1];
        }
        else {
            m_size = '\0';
        }

        return ordered();
    }


    bool Drink::ordered() const {
        return m_size == 'S' || m_size == 'M' || m_size == 'L' || m_size == 'X';
    }

    ifstream& Drink::read(ifstream& file) {
        string name;
        double price;

        if (getline(file, name, ',') && file >> price) {
            file.ignore(1000, '\n');
            this->name(name.c_str());
            this->Billable::price(price);
            m_size = '\0';
        }

        return file;
    }

    double Drink::price() const {
        double base = Billable::price();
        switch (m_size) {
        case 'S': return base * 0.5;
        case 'M': return base * 0.75;
        case 'L': return base;
        case 'X': return base * 1.5;
        default: return base;
        }
    }
}
