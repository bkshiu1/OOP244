/***********************************************************************
// OOP244 Project, Billable Module
//
// Final Project Milestone 3
// Module: Billable
// Filename: Billable.h
// Version 1.0
// Author: Karl Shiu, 131531246, bkshiu1@myseneca.ca
// Revision History
// -----------------------------------------------------------
// Date      Reason
// 2025/04/08  Created Billable module
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
***********************************************************************/

#ifndef SENECA_BILLABLE_H
#define SENECA_BILLABLE_H

#include <iostream>
#include <fstream>

namespace seneca {

    class Billable {
        char* m_name{};
        double m_price{};
    protected:
        void name(const char* name);
        void price(double value);
    public:
        Billable();
        Billable(const Billable& src);
        Billable& operator=(const Billable& src);
        virtual ~Billable();

        virtual double price() const;
        virtual std::ostream& print(std::ostream& ostr = std::cout) const = 0;
        virtual bool order() = 0;
        virtual bool ordered() const = 0;
        virtual std::ifstream& read(std::ifstream& file) = 0;

        operator const char* () const;
    };

    double operator+(double money, const Billable& B);
    double& operator+=(double& money, const Billable& B);

} // namespace seneca

#endif // SENECA_BILLABLE_H