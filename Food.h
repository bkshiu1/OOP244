/***********************************************************************
// OOP244 Project, Food Module
//
// Final Project Milestone 5 part 6
// Module: Food
// Filename: Food.h
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
#ifndef SENECA_FOOD_H
#define SENECA_FOOD_H

#include "Billable.h"
#include <fstream>

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
        Billable* clone() const override;
    };


}

#endif
