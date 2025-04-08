/***********************************************************************
// OOP244 Project, Drink Module
//
// Final Project Milestone 3
// Module: Drink
// Filename: Drink.h
// Version 1.0
// Author: Karl Shiu, 131531246, bkshiu1@myseneca.ca
// Revision History
// -----------------------------------------------------------
// Date      Reason
// 2025/04/08  Created Drink header
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
***********************************************************************/

#ifndef SENECA_DRINK_H
#define SENECA_DRINK_H

#include "Billable.h"
#include <iostream>
#include <fstream>

namespace seneca {
    class Drink : public Billable {
        char m_size;

    public:
        Drink();
        std::ostream& print(std::ostream& ostr = std::cout) const override;
        bool order() override;
        bool ordered() const override;
        std::ifstream& read(std::ifstream& file) override;
        double price() const override;
    };
}

#endif // SENECA_DRINK_H
