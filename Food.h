/***********************************************************************
// OOP244 Project, Food Module
//
// Final Project Milestone 3
// Module: Food
// Filename: Food.h
// Version 1.0
// Author: Karl Shiu, 131531246, bkshiu1@myseneca.ca
// Revision History
// -----------------------------------------------------------
// Date      Reason
// 2025/04/08  Created Food module
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
***********************************************************************/

#ifndef SENECA_FOOD_H
#define SENECA_FOOD_H

#include <iostream>
#include <fstream>
#include "Billable.h"

namespace seneca {

    class Food : public Billable {
        bool m_ordered{};
        bool m_child{};
        char* m_customize{};

    public:
        Food();
        Food(const Food& src);
        Food& operator=(const Food& src);
        ~Food();

        std::ostream& print(std::ostream& ostr = std::cout) const override;
        bool order() override;
        bool ordered() const override;
        std::ifstream& read(std::ifstream& file) override;
        double price() const override;
    };

} // namespace seneca

#endif // SENECA_FOOD_H