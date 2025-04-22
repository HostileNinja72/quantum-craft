#ifndef complexvector.hpp 
#define complexvector.hpp

#include <complexnumber.h>
#include <vector>



class ComplexVector {
    private:
        std::vector<ComplexNumber> elements;
        int n = elements.size();

    public:
        ComplexVector(std::vector<ComplexNumber> elements, int n);
        

        ComplexVector operator+(const ComplexVector& other) const;
        ComplexVector operator-() const;
        ComplexVector operator*(const ComplexNumber& scalar) const;
};










#endif

