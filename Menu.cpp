/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.cpp
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
#include "Menu.h"
#include <cstring>
#include <iomanip>

using namespace seneca;

void MenuItem::setEmpty() {
    delete[] m_content;
    m_content = nullptr;
    m_indent = 0;
    m_indentSZ = 0;
    m_rowNumber = -1;
}

MenuItem::MenuItem(const char* content, unsigned indent, unsigned indentSZ, int rowNumber)
    : m_content(nullptr), m_indent(indent), m_indentSZ(indentSZ), m_rowNumber(rowNumber) {

    if (!content || ut.isspace(content) || indent > 4 || indentSZ > 4 || rowNumber > MaximumNumberOfMenuItems) {
        setEmpty();
    }
    else {
        while (*content && ut.isspace(*content)) {
            content++;
        }
        m_content = ut.alocpy(content);
    }
}

MenuItem::~MenuItem() {
    delete[] m_content;
}

MenuItem::operator bool() const {
    return m_content != nullptr && m_content[0] != '\0' && !ut.isspace(m_content);
}

std::ostream& MenuItem::display() const {
    if (m_content && m_content[0] != '\0' && !ut.isspace(m_content)) {
        if (m_rowNumber >= 0) {
            std::cout << std::setw(m_indent * m_indentSZ) << "" << std::setw(2) << m_rowNumber << "- ";
        }
        std::cout << m_content;
    }
    else {
        std::cout << "??????????";
    }
    return std::cout;
}




