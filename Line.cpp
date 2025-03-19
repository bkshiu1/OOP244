#include "Line.h"

namespace seneca {
    Line::Line() : LblShape(), m_length(0) {}
    Line::Line(const char* label, int length) : LblShape(label) {
        m_length = (length < ut.strlen(label)) ? ut.strlen(label) : length;
    }
    void Line::getSpecs(std::istream& is) {
        LblShape::getSpecs(is);
        is >> m_length;
        is.ignore(1000, '\n');
    }
    void Line::draw(std::ostream& os) const {
        if (label() && label()[0] != '\0') {
            os << label() << std::endl;
        }
        if (m_length > 0) {
            for (int i = 0; i < m_length; i++) os << "=";
            os << std::endl;
        }
    }
}