/***********************************************************************
// OOP244 workshop 9, Transcript module
//
// File	Transcript.cpp
// Version 1.0
// started by Fardad
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include "Transcript.h"
#include "Utils.h"

using namespace std;

namespace seneca {

    Transcript::Transcript(const char* name, unsigned int number)
        : m_studentName(nullptr), m_studentNumber(number) {
        ut.alocpy(m_studentName, name);
    }

    Transcript::Transcript(const Transcript& other)
        : Marks(other), m_studentName(nullptr), m_studentNumber(other.m_studentNumber) {
        ut.alocpy(m_studentName, other.m_studentName);
    }

    Transcript& Transcript::operator=(const Transcript& other) {
        if (this != &other) {
            Marks::operator=(other); // Base class copy
            delete[] m_studentName;
            m_studentName = nullptr;
            ut.alocpy(m_studentName, other.m_studentName);
            m_studentNumber = other.m_studentNumber;
        }
        return *this;
    }

    Transcript::~Transcript() {
        delete[] m_studentName;
    }

    std::ostream& Transcript::display(std::ostream& os) const {
        os << m_studentName << " (" << m_studentNumber << ")" << endl;
        os << "--------------------------------------------------------------------------" << endl;
        Marks::display(os);
        return os;
    }

}
