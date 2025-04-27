#ifndef COMPLEXMATRIX_h
#define COMPLEXMATRIX_h

#include <vector>
#include "complexvector.h"
#include <iostream>




class ComplexMatrix{
    private:
    std::vector<ComplexVector> elements;


    public:
    ComplexMatrix(const std::vector<ComplexVector>& elements);
    int size_rows() const;
    int size_cols() const;


    ComplexMatrix operator+(const ComplexMatrix& other) const;
    ComplexMatrix operator-() const;
    ComplexMatrix operator-(const ComplexMatrix& other) const;
    ComplexMatrix operator*(const ComplexMatrix& other) const;
    ComplexMatrix operator*(const ComplexNumber& scalar) const;

    friend std::ostream& operator <<(std::ostream& os, const ComplexMatrix& matrix);





};




#endif