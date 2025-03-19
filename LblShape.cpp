#include "LblShape.h"
#include <cstring>

namespace seneca {
    LblShape::LblShape() : m_label(nullptr) {}
    LblShape::LblShape(const char* label) { m_label = ut.alocpy(label); }
    LblShape::~LblShape() { delete[] m_label; }
    const char* LblShape::label() const { return m_label; }
    void LblShape::getSpecs(std::istream& is) {
        char temp[81];
        is.getline(temp, 81, ',');
        delete[] m_label;
        m_label = ut.alocpy(temp);
    }
}