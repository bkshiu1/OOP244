/***********************************************************************
// OOP244 Project, Ordering Module
//
// Final Project Milestone 5 part 6
// Module: Ordering
// Filename: Ordering.h
// Version 1.0
// Author: Karl Shiu, 131531246, bkshiu1@myseneca.ca
// Revision History
// -----------------------------------------------------------
// Date      Reason
// 2025/04/14  Initial implementation for Milestone 4
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
***********************************************************************/
#ifndef SENECA_ORDERING_H
#define SENECA_ORDERING_H

#include "Food.h"
#include "Drink.h"
#include "Utils.h"
#include "constants.h"
#include "Menu.h"

namespace seneca {

    class Ordering {
        Food* m_foods{};
        Drink* m_drinks{};
        Billable* m_items[MaximumNumberOfBillItems]{};
        size_t m_cntFoods{};
        size_t m_cntDrinks{};
        size_t m_cntItems{};
        size_t m_billNo{ 1 };

        void printBillTitle(std::ostream& os) const;
        void printTotals(std::ostream& os, double total) const;
        size_t countRecords(const char* filename) const;

    public:
        Ordering(const char* drinkFile, const char* foodFile);
        ~Ordering();

        operator bool() const;
        size_t noOfBillItems() const;
        bool hasUnsavedBill() const;

        void listFoods() const;
        void listDrinks() const;
        void orderFood();
        void orderDrink();
        void printBill(std::ostream& os) const;
        void resetBill();
    };

}

#endif
