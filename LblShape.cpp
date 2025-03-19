//Karl Shiu, bkshiu1@myseneca.ca, 131531246, 19/3/2025
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "LblShape.h"
#include "Utils.h"

using namespace seneca;

LblShape::LblShape() : m_label(nullptr) {}

LblShape::LblShape(const char* label) : m_label(nullptr) {
    ut.alocpy(m_label, label);
}

LblShape::~LblShape() {
    delete[] m_label;
}

const char* LblShape::label() const {
    return m_label;
}

void LblShape::getSpecs(std::istream& is) {
    char temp[81];
    is.getline(temp, 81, ',');
    ut.alocpy(m_label, temp);
}
