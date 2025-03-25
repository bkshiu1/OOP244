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

    Transcript::Transcript(const char* studentName, unsigned int studentNo)
        : m_name(nullptr), m_stuNum(studentNo) {
        ut.alocpy(m_name, studentName);
    }

    Transcript::Transcript(const Transcript& source)
        : Marks(source), m_name(nullptr), m_stuNum(source.m_stuNum) {
        ut.alocpy(m_name, source.m_name);
    }

    Transcript& Transcript::operator=(const Transcript& source) {
        if (this != &source) {
            Marks::operator=(source); // Base copy
            delete[] m_name;
            m_name = nullptr;
            ut.alocpy(m_name, source.m_name);
            m_stuNum = source.m_stuNum;
        }
        return *this;
    }

    Transcript::~Transcript() {
        delete[] m_name;
    }

    std::ostream& Transcript::display(std::ostream& os) const {
        os << m_name << " (" << m_stuNum << ")" << endl;
        os << "--------------------------------------------------------------------------" << endl;
        Marks::display(os);
        return os;
    }

}
