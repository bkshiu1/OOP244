//Karl Shiu, bkshiu1@myseneca.ca, 131531246, 19/3/2025
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SENECA_RECTANGLE_H
#define SENECA_RECTANGLE_H
#include "LblShape.h"

namespace seneca {
    class Rectangle : public LblShape {
        int rectWidth;
        int rectHeight;

    public:
        Rectangle();
        Rectangle(const char* label, int width, int height);
        void getSpecs(std::istream& is);
        void draw(std::ostream& os) const;
    };
}

#endif
