#include "Rectangle.h"

namespace seneca {
    Rectangle::Rectangle() : LblShape(), m_width(0), m_height(0) {}
    Rectangle::Rectangle(const char* label, int width, int height) : LblShape(label) {
        m_width = (width < ut.strlen(label) + 2) ? ut.strlen(label) + 2 : width;
        m_height = (height < 3) ? 3 : height;
    }
    void Rectangle::getSpecs(std::istream& is) {
        LblShape::getSpecs(is);
        is >> m_width;
        is.ignore();
        is >> m_height;
        is.ignore(1000, '\n');
    }
    void Rectangle::draw(std::ostream& os) const {
        if (m_width > 0 && m_height > 0) {
            os << "+";
            for (int i = 0; i < m_width - 2; i++) os << "-";
            os << "+" << std::endl;
            os << "|";
            os.width(m_width - 2);
            os.setf(std::ios::left);
            os << label();
            os.unsetf(std::ios::left);
            os << "|" << std::endl;
            for (int i = 0; i < m_height - 3; i++) {
                os << "|";
                os.width(m_width - 2);
                os << " ";
                os << "|" << std::endl;
            }
            os << "+";
            for (int i = 0; i < m_width - 2; i++) os << "-";
            os << "+";
        }
    }
}
