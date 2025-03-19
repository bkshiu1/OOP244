//Karl Shiu, bkshiu1@myseneca.ca, 131531246, 19/3/2025
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SENECA_LINE_H
#define SENECA_LINE_H
#include "LblShape.h"

namespace seneca {
    class Line : public LblShape {
        int lineLength;

    public:
        Line();
        Line(const char* label, int length);
        void getSpecs(std::istream& is);
        void draw(std::ostream& os) const;
    };
}

#endif