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
#include "Menu.h"
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
    if (!content || ut.isspace(content) || indent > 4 || indentSZ > 4 || rowNumber > static_cast<int>(MaximumNumberOfMenuItems)) {
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
            std::cout << std::string(m_indent * m_indentSZ, ' ');
            if (m_rowNumber < 10) {
                std::cout << " " << m_rowNumber << "- ";
            }
            else {
                std::cout << m_rowNumber << "- ";
            }
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
    m_prompt("> ", indent + 1, indentSZ, -1) {
    for (unsigned i = 0; i < MaximumNumberOfMenuItems; ++i) {
        m_items[i] = nullptr;
    }
}

Menu::~Menu() {
    for (unsigned i = 0; i < m_numItems; ++i) {
        delete m_items[i];
        m_items[i] = nullptr;
    }
}

Menu& Menu::operator<<(const char* menuItemContent) {
    if (m_numItems < MaximumNumberOfMenuItems) {
        unsigned itemIndent = (m_indent == 0) ? 0 : m_indent + 1;
        m_items[m_numItems] = new MenuItem(menuItemContent, itemIndent, m_indentSZ, static_cast<int>(m_numItems + 1));
        m_numItems++;
    }
    return *this;
}

size_t Menu::select() const {
    if (m_title) m_title.display() << std::endl;

    for (unsigned i = 0; i < m_numItems; ++i) {
        if (m_items[i]) {
            m_items[i]->display() << std::endl;
        }
    }

    m_exitOption.display() << std::endl;
    m_prompt.display();

    return static_cast<size_t>(ut.getInt(0, static_cast<int>(m_numItems)));
}

namespace seneca {
    size_t operator<<(std::ostream& ostr, const Menu& m) {
        if (&ostr == &std::cout) {
            return m.select();
        }
        return 0;
    }
}
