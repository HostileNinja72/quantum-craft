#ifndef COMPLEXVECTOR_H
#define COMPLEXVECTOR_H

#include "complexnumber.h"
#include <vector>
#include <ostream>

class ComplexVector {
private:
    std::vector<ComplexNumber> elements;

public:
   
    ComplexVector(const std::vector<ComplexNumber>& elements);

    int size() const;

    
    ComplexVector operator+(const ComplexVector& other) const;
    ComplexVector operator-() const;
    ComplexVector operator-(const ComplexVector& other) const;
    ComplexVector operator*(const ComplexNumber& scalar) const;


    ComplexNumber& operator[](int index);
    const ComplexNumber& operator[](int index) const;

   
    friend std::ostream& operator<<(std::ostream& os, const ComplexVector& vec);
};

#endif
