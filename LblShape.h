//Karl Shiu, bkshiu1@myseneca.ca, 131531246
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SENECA_LBLSHAPE_H
#define SENECA_LBLSHAPE_H
#include "Shape.h"

namespace seneca {
    class LblShape : public Shape {
        char* m_label;

    protected:
        const char* label() const;

    public:
        LblShape();
        LblShape(const char* label);
        ~LblShape();
        void getSpecs(std::istream& is);
        LblShape(const LblShape&) = delete;
        LblShape& operator=(const LblShape&) = delete;
    };
}

#endif