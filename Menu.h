/***********************************************************************
// OOP244 Project, Menu Module
//
// Final Project Milestone 2
// Module: Menu
// Filename: Menu.cpp / Menu.h
// Version 1.0
// Author: Karl Shiu, 131531246, bkshiu1@myseneca.ca
// Revision History
// -----------------------------------------------------------
// Date      Reason
// 2025/04/08  Completed Milestone 2 implementation
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
***********************************************************************/
#ifndef SENECA_MENU_H
#define SENECA_MENU_H

#include <iostream>
#include "Utils.h"
#include "constants.h"

namespace seneca {

    class Menu;

    class MenuItem {
        char* m_content{};
        unsigned m_indent{};
        unsigned m_indentSZ{};
        int m_rowNumber{};

        void setEmpty();
        MenuItem(const char* content, unsigned indent, unsigned indentSZ, int rowNumber);
        ~MenuItem();

        MenuItem(const MenuItem& other) = delete;
        MenuItem& operator=(const MenuItem& other) = delete;

        operator bool() const;
        std::ostream& display() const;

        friend class Menu;
    };

    class Menu {
        unsigned m_indent{};
        unsigned m_indentSZ{};
        unsigned m_numItems{};

        MenuItem m_title;
        MenuItem m_exitOption;
        MenuItem m_prompt;

        MenuItem* m_items[MaximumNumberOfMenuItems]{};

    public:
        Menu(const char* title, const char* exitOption = "Exit", unsigned indent = 0, unsigned indentSZ = 3);
        ~Menu();

        Menu(const Menu&) = delete;
        Menu& operator=(const Menu&) = delete;

        Menu& operator<<(const char* menuItemContent);
        size_t select() const;
        size_t run() const;
        void displayOnly() const;

        friend size_t operator<<(std::ostream& ostr, const Menu& m);
    };
}

#endif
