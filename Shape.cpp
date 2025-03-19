//Karl Shiu, bkshiu1@myseneca.ca, 131531246
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "Shape.h"

namespace seneca {

    std::ostream& operator<<(std::ostream& os, const Shape& shape) {
        shape.draw(os);
        return os;
    }

    std::istream& operator>>(std::istream& is, Shape& shape) {
        shape.getSpecs(is);
        return is;
    }
}