/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.h
Version 1.0
Author: Karl Shiu
Revision History
-----------------------------------------------------------
Date      Reason
2024/03/18  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SENECA_MENU_H
#define SENECA_MENU_H

#include <iostream>
#include "Utils.h"
#include "constants.h"

namespace seneca {
    class MenuItem {
        char* m_content;
        unsigned m_indent;
        unsigned m_indentSZ;
        int m_rowNumber;

        void setEmpty();

    public:
        MenuItem(const char* content, unsigned indent, unsigned indentSZ, int rowNumber);
        ~MenuItem();
        MenuItem(const MenuItem& other) = delete;
        MenuItem& operator=(const MenuItem& other) = delete;
        operator bool() const;
        std::ostream& display() const;
    };
}

#endif

