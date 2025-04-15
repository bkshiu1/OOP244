/***********************************************************************
// OOP244 Project, Drink Module
//
// Final Project Milestone 4
// Module: Drink
// Filename: Drink.h
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
#ifndef SENECA_DRINK_H
#define SENECA_DRINK_H

#include "Billable.h"

namespace seneca {

    class Drink : public Billable {
        bool m_ordered{};
        int m_size{};

    public:
        Drink();
        Drink(const Drink& src);
        Drink& operator=(const Drink& src);
        ~Drink();

        std::ostream& print(std::ostream& ostr = std::cout) const override;
        bool order() override;
        bool ordered() const override;
        std::ifstream& read(std::ifstream& file) override;
        double price() const override; 
        Billable* clone() const override;
    };
}

#endif
