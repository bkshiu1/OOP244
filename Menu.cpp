/***********************************************************************
// OOP244 Project, Menu Module
//
// Final Project Milestone 2
// Module: Menu
// Filename: Menu.cpp
// Version 1.0
// Author: Karl Shiu, 131531246, bkshiu1@myseneca.ca
// Revision History
// -----------------------------------------------------------
// Date      Reason
// 2025/04/08  Completed Milestone 2 implementation
// 2025/04/13  Implemented ms3 requirements
// 2025/04/14  Updated for ms4 requirments
// 2025/04/15  Updated function select() to ms51 requirments
// -----------------------------------------------------------
***********************************************************************/
#include "Menu.h"
#include "Utils.h"
#include <iomanip>
#include <cstring>

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
    if (!content || ut.isspace(content)) {
        setEmpty();
    }
    else {
        while (*content && ut.isspace(content)) {
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
            int indent = m_indent * m_indentSZ;
            if (m_rowNumber < 10 || m_rowNumber == 0) indent += 1;
            std::cout << std::string(indent, ' ') << m_rowNumber << "- ";
        }
        else {
            std::cout << std::string(m_indent * m_indentSZ, ' ');
        }
        std::cout << m_content;
    }
    else {
        std::cout << "??????????";
    }
    return std::cout;
}

Menu::Menu(const char* title, const char* exitOption, unsigned indent, unsigned indentSZ)
    : m_indent(indent), m_indentSZ(indentSZ), m_numItems(0),
    m_title(title, indent, indentSZ, -1),
    m_exitOption(exitOption, indent, indentSZ, 0),
    m_prompt("> ", indent, indentSZ, -1) {
    for (unsigned i = 0; i < MaximumNumberOfMenuItems; ++i)
        m_items[i] = nullptr;
}

Menu::~Menu() {
    for (unsigned i = 0; i < m_numItems; ++i) {
        delete m_items[i];
        m_items[i] = nullptr;
    }
}

Menu& Menu::operator<<(const char* menuItemContent) {
    if (m_numItems < MaximumNumberOfMenuItems) {
        m_items[m_numItems] = new MenuItem(menuItemContent, m_indent, m_indentSZ, static_cast<int>(m_numItems + 1));
        m_numItems++;
    }
    return *this;
}

size_t Menu::select() const {
    if (m_title) {
        m_title.display();
        std::cout << " " << std::endl;
    }
    for (unsigned i = 0; i < m_numItems; ++i)
        if (m_items[i]) m_items[i]->display() << std::endl;
    m_exitOption.display() << std::endl;
    m_prompt.display();
    return static_cast<size_t>(ut.getInt(0, static_cast<int>(m_numItems)));
}

size_t operator<<(std::ostream& ostr, const Menu& m) {
    if (&ostr == &std::cout) {
        return m.select();
    }
    return 0;
}
