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

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Drink.h"
#include "Utils.h"
#include "Menu.h"

using namespace std;

namespace seneca {

    Drink::Drink() {
        m_size = '\0';
    }

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
            default:  ostr << "....."; break;
            }
        }

        ostr << right << setfill(' ') << setw(7) << fixed << setprecision(2) << Billable::price();
        return ostr;
    }

    bool Drink::order() {
        Menu menu("Drink Size Selection");
        menu << "Small" << "Medium" << "Large" << "Extra Large";

        int selection = menu.run();

        switch (selection) {
        case 1: m_size = 'S'; break;
        case 2: m_size = 'M'; break;
        case 3: m_size = 'L'; break;
        case 4: m_size = 'X'; break;
        default: m_size = '\0'; break;
        }

        return m_size != '\0';
    }

    bool Drink::ordered() const {
        return m_size != '\0';
    }

    ifstream& Drink::read(ifstream& file) {
        string name;
        double pr;
        if (getline(file, name, ',') && file >> pr) {
            file.ignore(1000, '\n');
            this->name(name.c_str());
            Billable::price(pr);
            m_size = '\0';
        }
        return file;
    }

    double Drink::price() const {
        double factor = 1.0;
        if (!ordered()) return Billable::price();

        switch (m_size) {
        case 'S': factor = 0.5; break;
        case 'M': factor = 0.75; break;
        case 'L': factor = 1.0; break;
        case 'X': factor = 1.5; break;
        }
        return Billable::price() * factor;
    }
}
