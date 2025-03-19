//Karl Shiu, bkshiu1@myseneca.ca, 131531246, 19/3/2025
// //I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "Rectangle.h"
#include "Utils.h"

using namespace seneca;

Rectangle::Rectangle() : LblShape(), rectWidth(0), rectHeight(0) {}

Rectangle::Rectangle(const char* label, int width, int height) : LblShape(label) {
    rectWidth = (width < ut.strlen(label) + 2) ? ut.strlen(label) + 2 : width;
    rectHeight = (height < 3) ? 3 : height;
}

void Rectangle::getSpecs(std::istream& is) {
    LblShape::getSpecs(is);
    is >> rectWidth;
    is.ignore();
    is >> rectHeight;
    is.ignore(1000, '\n');
}

void Rectangle::draw(std::ostream& os) const {
    if (rectWidth > 0 && rectHeight > 0) {
        os << "+";
        for (int i = 0; i < rectWidth - 2; i++) os << "-";
        os << "+" << std::endl;
        os << "|";
        os.width(rectWidth - 2);
        os.setf(std::ios::left);
        os << label();
        os.unsetf(std::ios::left);
        os << "|" << std::endl;
        for (int i = 0; i < rectHeight - 3; i++) {
            os << "|";
            os.width(rectWidth - 2);
            os << " ";
            os << "|" << std::endl;
        }
        os << "+";
        for (int i = 0; i < rectWidth - 2; i++) os << "-";
        os << "+"; // Ensures no extra newline
    }
}
