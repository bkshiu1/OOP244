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
// 2025/04/14  Updated for ms4: added clone(), fixed display
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include "Drink.h"
#include "Menu.h"
#include "Utils.h"

using namespace std;

namespace seneca {

    Drink::Drink() : m_ordered(false), m_size(0) {}

    Drink::Drink(const Drink& src) : Billable(src), m_ordered(src.m_ordered), m_size(src.m_size) {}


    Drink& Drink::operator=(const Drink& src) {
        if (this != &src) {
            Billable::operator=(src);
            m_size = src.m_size;
            m_ordered = src.m_ordered;
        }
        return *this;
    }

    Drink::~Drink() {}

    std::ostream& Drink::print(std::ostream& os) const {
        os << left << setw(28) << setfill('.') << (const char*)*this;

        if (!m_ordered) {
            os << ".....";
        }
        else {
            switch (m_size) {
            case 'S':
                os << "SML..";
                break;
            case 'M':
                os << "MED..";
                break;
            case 'L':
                os << "LRG..";
                break;
            case 'X':
                os << "XLRG.";
                break;
            default:
                os << ".....";
            }
        }

        os << right << setw(7) << setfill(' ') << fixed << setprecision(2) << price();
        return os;
    }

    bool Drink::order() {
        Menu sizeMenu("Drink Size Selection", "Back", 5, 1);
        sizeMenu << "Small" << "Medium" << "Large" << "Extra Large";
        int selection = sizeMenu.select();

        switch (selection) {
        case 1:
            m_size = 'S';
            break;
        case 2:
            m_size = 'M';
            break;
        case 3:
            m_size = 'L';
            break;
        case 4:
            m_size = 'X';
            break;
        default:
            m_size = 0;
        }

        m_ordered = (m_size != 0);
        return m_ordered;
    }

    bool Drink::ordered() const {
        return m_ordered;
    }

    std::ifstream& Drink::read(std::ifstream& file) {
        std::string name;
        double price;

        if (std::getline(file, name, ',') && file >> price) {
            file.ignore(1000, '\n');
            setName(name.c_str());        // Make sure this is correctly implemented in Billable
            setPrice(price);              // This stores the base price in m_price
            m_ordered = false;
            m_size = 0;
        }
        return file;
    }


    double Drink::price() const {
        const double sizeFactors[] = { 0.0, 1.5, 2.0, 2.5, 3.0 };
        return m_ordered ? getBasePrice() * sizeFactors[m_size] : 0.0;
    }


    Billable* Drink::clone() const {
        return new Drink(*this);
    }

}
