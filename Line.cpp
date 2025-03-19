//Karl Shiu, bkshiu1@myseneca.ca, 131531246
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "Line.h"
#include "Utils.h"

using namespace seneca;

Line::Line() : LblShape(), lineLength(0) {}

Line::Line(const char* label, int length) : LblShape(label) {
    lineLength = (length < ut.strlen(label)) ? ut.strlen(label) : length;
}

void Line::getSpecs(std::istream& is) {
    LblShape::getSpecs(is);
    is >> lineLength;
    is.ignore(1000, '\n');
}

void Line::draw(std::ostream& os) const {
    if (label() && label()[0] != '\0') {
        os << label() << std::endl;
    }
    if (lineLength > 0) {
        for (int i = 0; i < lineLength; i++) os << "=";
    }
}
