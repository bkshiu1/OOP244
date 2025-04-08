/***********************************************************************
// OOP244 Project, Food Module
//
// Final Project Milestone 3
// Module: Food
// Filename: Food.cpp
// Version 1.0
// Author: Karl Shiu, 131531246, bkshiu1@myseneca.ca
// Revision History
// -----------------------------------------------------------
// Date      Reason
// 2025/04/08  Implemented Food module logic
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
***********************************************************************/

#include "Food.h"
#include "Utils.h"
#include "Menu.h"
#include <iomanip>
#include <cstring>
#include <string>


using namespace std;

namespace seneca {

    Food::Food() = default;

    Food::Food(const Food& src) {
        *this = src;
    }

    Food& Food::operator=(const Food& src) {
        if (this != &src) {
            Billable::operator=(src);
            m_ordered = src.m_ordered;
            m_child = src.m_child;
            delete[] m_customize;
            if (src.m_customize) {
                m_customize = ut.alocpy(src.m_customize);
            }
            else {
                m_customize = nullptr;
            }
        }
        return *this;
    }

    Food::~Food() {
        delete[] m_customize;
    }

    ostream& Food::print(ostream& ostr) const {
        ostr << left << setw(28) << setfill('.') << (const char*)(*this);

        if (!ordered()) {
            ostr << ".....";
        }
        else {
            ostr << (m_child ? "Child" : "Adult");
        }

        ostr << right << setw(7) << setfill(' ') << fixed << setprecision(2) << price();

        if (ostr.rdbuf() == cout.rdbuf() && m_customize && *m_customize) {
            ostr << " >> ";
            for (int i = 0; m_customize[i] && i < 30; i++) ostr << m_customize[i];
        }
        return ostr;
    }

    bool Food::order() {
        Menu sizeMenu("Food Size Selection");
        sizeMenu << "Adult" << "Child";
        size_t selection = sizeMenu.select();

        if (selection == 1 || selection == 2) {
            m_child = (selection == 2);
            m_ordered = true;
            cout << "Special instructions\n> ";
            char buffer[1024]{};
            cin.ignore(1000, '\n');
            cin.getline(buffer, 1024);
            delete[] m_customize;
            m_customize = (*buffer) ? ut.alocpy(buffer) : nullptr;
        }
        else {
            m_ordered = false;
            m_child = false;
            delete[] m_customize;
            m_customize = nullptr;
        }
        return m_ordered;
    }

    bool Food::ordered() const {
        return m_ordered;
    }

    ifstream& Food::read(ifstream& file) {
        string name;
        double pr = 0.0;

        if (getline(file, name, ',') && file >> pr) {
            file.ignore(1000, '\n');
            this->name(name.c_str());
            this->Billable::price(pr);
            m_child = false;
            m_ordered = false;
            delete[] m_customize;
            m_customize = nullptr;
        }
        return file;
    }

    double Food::price() const {
        return (m_ordered && m_child) ? Billable::price() * 0.5 : Billable::price();
    }

} // namespace seneca