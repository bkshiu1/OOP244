/***********************************************************************
// OOP244 Project, Ordering Module
//
// Final Project Milestone 4
// Module: Ordering
// Filename: Ordering.cpp
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
#include <fstream>
#include <iostream>
#include <iomanip>
#include "Ordering.h"
#include "Utils.h"

using namespace std;

namespace seneca {

    Ordering::Ordering(const char* drinkFile, const char* foodFile) {
        ifstream dfile(drinkFile);
        ifstream ffile(foodFile);

        if (!dfile || !ffile) return;

        size_t dcount = countRecords(drinkFile);
        size_t fcount = countRecords(foodFile);

        m_drinks = new(nothrow) Drink[dcount];
        m_foods = new(nothrow) Food[fcount];

        m_cntDrinks = 0;
        m_cntFoods = 0;

        if (m_drinks && m_foods) {
            for (size_t i = 0; i < dcount && dfile; ++i) {
                if (m_drinks[i].read(dfile)) {
                    m_cntDrinks++;
                }
            }

            for (size_t i = 0; i < fcount && ffile; ++i) {
                if (m_foods[i].read(ffile)) {
                    m_cntFoods++;
                }
            }

            if (m_cntDrinks != dcount || m_cntFoods != fcount) {
                delete[] m_drinks;
                delete[] m_foods;
                m_drinks = nullptr;
                m_foods = nullptr;
                m_cntDrinks = 0;
                m_cntFoods = 0;
            }
        }
    }

    Ordering::~Ordering() {
        delete[] m_drinks;
        delete[] m_foods;
        for (size_t i = 0; i < m_cntItems; ++i) {
            delete m_items[i];
        }
    }

    Ordering::operator bool() const {
        return m_drinks != nullptr && m_foods != nullptr;
    }

    size_t Ordering::noOfBillItems() const {
        return m_cntItems;
    }

    bool Ordering::hasUnsavedBill() const {
        return m_cntItems > 0;
    }

    void Ordering::listFoods() const {
        cout << "List Of Avaiable Meals" << endl;
        cout << "========================================" << endl;
        for (size_t i = 0; i < m_cntFoods; ++i) {
            m_foods[i].print(cout) << endl;
        }
        cout << "========================================" << endl;
    }

    void Ordering::listDrinks() const {
        cout << "List Of Avaiable Drinks" << endl;
        cout << "========================================" << endl;
        for (size_t i = 0; i < m_cntDrinks; ++i) {
            m_drinks[i].print(cout) << endl;
        }
        cout << "========================================" << endl;
    }

    void Ordering::orderDrink() {
        Menu drinkMenu("Drink Menu", "Back to Order", 2, 2);
        for (size_t i = 0; i < m_cntDrinks; ++i) {
            drinkMenu << (const char*)m_drinks[i];
        }

        size_t sel = drinkMenu.select();
        if (sel > 0 && m_cntItems < MaximumNumberOfBillItems) {
            Drink* d = dynamic_cast<Drink*>(m_drinks[sel - 1].clone());
            if (d->order()) {
                m_items[m_cntItems++] = d;
            }
            else {
                delete d;
            }
        }
    }

    void Ordering::orderFood() {
        Menu foodMenu("Food Menu", "Back to Order", 2, 2);
        for (size_t i = 0; i < m_cntFoods; ++i) {
            foodMenu << (const char*)m_foods[i];
        }

        size_t sel = foodMenu.select();
        if (sel > 0 && m_cntItems < MaximumNumberOfBillItems) {
            Food* f = dynamic_cast<Food*>(m_foods[sel - 1].clone());
            if (f->order()) {
                m_items[m_cntItems++] = f;
            }
            else {
                delete f;
            }
        }
    }
        
    void Ordering::printBillTitle(ostream& os) const {
        os << "Bill # ";
        os << setw(3) << setfill('0') << m_billNo;
        os << " =============================" << endl;
    }

    void Ordering::printTotals(ostream& os, double total) const {
        double tax = total * Tax;
        double totalWithTax = total + tax;
        os << right << setw(26) << setfill(' ') << "Total:" << setw(10) << fixed << setprecision(2) << total << endl;
        os << right << setw(26) << "Tax:" << setw(10) << tax << endl;
        os << right << setw(26) << "Total+Tax:" << setw(10) << totalWithTax << endl;
        os << "========================================" << endl;
    }

    void Ordering::printBill(ostream& os) const {
        double total = 0.0;
        printBillTitle(os);
        for (size_t i = 0; i < m_cntItems; ++i) {
            m_items[i]->print(os) << endl;
            total += m_items[i]->price();
        }
        printTotals(os, total);
    }

    void Ordering::resetBill() {
        char filename[100]{};
        ut.makeBillFileName(filename, m_billNo);
        ofstream file(filename);
        printBill(file);
        cout << "Saved bill number " << m_billNo << endl;
        cout << "Starting bill number " << m_billNo + 1 << endl;

        for (size_t i = 0; i < m_cntItems; ++i) {
            delete m_items[i];
            m_items[i] = nullptr;
        }

        m_cntItems = 0;
        m_billNo++;
    }

    size_t Ordering::countRecords(const char* filename) const {
        size_t count = 0;
        ifstream file(filename);
        char ch;
        while (file.get(ch)) {
            if (ch == '\n') ++count;
        }
        return count;
    }

}

