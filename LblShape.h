#ifndef SENECA_LBLSHAPE_H
#define SENECA_LBLSHAPE_H

#include "Shape.h"
#include "Utils.h"

namespace seneca {
    class LblShape : public Shape {
        char* m_label;
    protected:
        const char* label() const;
    public:
        LblShape();
        LblShape(const char* label);
        ~LblShape();
        LblShape(const LblShape&) = delete;
        LblShape& operator=(const LblShape&) = delete;
        void getSpecs(std::istream& is) override;
    };
}

#endif // SENECA_LBLSHAPE_H