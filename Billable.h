/***********************************************************************
// OOP244 Project, Billable Module
//
// Final Project Milestone 4
// Module: Billable
// Filename: Billable.h
// Version 1.0
// Author: Karl Shiu, 131531246, bkshiu1@myseneca.ca
// Revision History
// -----------------------------------------------------------
// Date      Reason
// 2025/04/08  Implemented interface for billable items
// 2025/04/14  Updated for milestone 4
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
***********************************************************************/
#ifndef SENECA_BILLABLE_H
#define SENECA_BILLABLE_H

#include <iostream>
#include <fstream>
#include "Utils.h"

namespace seneca {

    class Billable {
        double m_price{};
        char* m_name{};

    public:
        Billable();
        Billable(const Billable& other);
        Billable& operator=(const Billable& other);
        virtual ~Billable();

        virtual std::ostream& print(std::ostream& os) const = 0;
        operator const char* () const;

        virtual std::ifstream& read(std::ifstream& file) = 0;
        virtual bool order() = 0;
        virtual bool ordered() const = 0;
        virtual double price() const = 0;
        virtual Billable* clone() const = 0;
        double getBasePrice() const;

    protected:
        void setName(const char* name);
        void setPrice(double price);



    };


}

#endif
