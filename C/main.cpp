#include <iostream>
#include "complexnumber.h"
#include "complexvector.h"
#include <vector>




int main()
{
    

    ComplexNumber c1(3.0, -5);   
    ComplexNumber c2(-7, 2); 
    ComplexNumber cConj = c1.conjugate(); 
    ComplexNumber cDiv = c1 * c2;

    std::vector<ComplexNumber> rawVec = {c1, c2}; 
    ComplexVector v1(rawVec);

    std::cout << "vector v1: " << v1 << std::endl;
    std::cout << "Original: " << c1 << std::endl;
    std::cout << "Conjugate: " << cConj << std::endl;
    std::cout << "c1 / c2: " << cDiv << std::endl;

    return 0;
}


