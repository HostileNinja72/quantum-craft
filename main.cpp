#include <iostream>
#include "complexnumber.h" 


std::ostream &operator<<(std::ostream &os, const ComplexNumber &c)
{
    os << c.getReal();
    if (c.getImag() >= 0)
        os << " + " << c.getImag() << "i";
    else
        os << " - " << -c.getImag() << "i";
    return os;
}

int main()
{
    ComplexNumber c1(3.0, 4.0);   
    ComplexNumber c2(-7, 2); 
    ComplexNumber cConj = c1.conjugate(); 
    ComplexNumber cDiv = c1 * c2;

    std::cout << "Original: " << c1 << std::endl;
    std::cout << "Conjugate: " << cConj << std::endl;
    std::cout << "c1 / c2: " << cDiv << std::endl;

    return 0;
}
