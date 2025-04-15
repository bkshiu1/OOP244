/***********************************************************************
// OOP244 Project, Food Module
//
// Final Project Milestone 5 part 5
// Module: Food
// Filename: Food.cpp
// Version 1.1
// Author: Karl Shiu, 131531246, bkshiu1@myseneca.ca
// Revision History
// -----------------------------------------------------------
// Date      Reason
// 2025/04/08  Implemented Food module logic
// 2025/04/13  Implemented ms3 requirements
// 2025/04/14  Updated for ms4: added clone()
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include "Food.h"
#include "Menu.h"

using namespace std;

namespace seneca {

    Food::Food() : m_ordered(false), m_child(false), m_customize(nullptr) {}

    Food::Food(const Food& src) : Billable(src), m_ordered(src.m_ordered), m_child(src.m_child), m_customize(nullptr) {
        if (src.m_customize) {
            m_customize = new char[strlen(src.m_customize) + 1];
            strcpy(m_customize, src.m_customize);
        }
    }

    Food& Food::operator=(const Food& src) {
        if (this != &src) {
            Billable::operator=(src);
            m_ordered = src.m_ordered;
            m_child = src.m_child;
            delete[] m_customize;
            m_customize = nullptr;
            if (src.m_customize) {
                m_customize = new char[strlen(src.m_customize) + 1];
                strcpy(m_customize, src.m_customize);
            }
        }
        return *this;
    }

    Food::~Food() {
        delete[] m_customize;
    }

    ostream& Food::print(std::ostream& ostr) const {
        ostr << left << setw(28) << setfill('.') << (const char*)*this;
        ostr << (m_child ? "Child " : "Adult ");
        ostr << right << setw(6) << setfill(' ') << fixed << setprecision(2) << price();

        if (&ostr == &std::cout && m_customize && m_customize[0]) {
            ostr << " >> " << m_customize;
        }

        return ostr;
    }


    bool Food::order() {
        Menu sizeMenu("Food Size Selection", "Back", 3, 3);
        sizeMenu << "Adult" << "Child";
        size_t selection = sizeMenu.select();

        if (selection == 1 || selection == 2) {
            m_child = (selection == 2);
            m_ordered = true;

            cout << "Special instructions\n> ";
            char buffer[1024]{};
            ut.getlineInput(buffer, 1024);

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
        double price;

        if (getline(file, name, ',') && file >> price) {
            file.ignore(1000, '\n');
            this->setName(name.c_str());
            setPrice(price);
            m_ordered = false;
            m_child = false;
            delete[] m_customize;
            m_customize = nullptr;
        }
        return file;
    }

    double Food::price() const {
        return m_child ? getBasePrice() / 2.0 : getBasePrice();
    }

    Billable* Food::clone() const {
        return new Food(*this);
    }

}
