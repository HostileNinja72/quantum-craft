#ifndef complexnumber_h
#define complexnumber_h

#include <cmath> 
#include <iostream>
#include <string>

class ComplexNumber
{
private:
    double real_;
    double imag_; 

    double magnitude_;
    double phase_;

    void updatePolar();
    void updateCartesian();

public:
    ComplexNumber(double magnitude, double phase, bool isPolar=0);
    ComplexNumber(const std::string &str);
    ComplexNumber(const char *str);

    double getReal() const;
    double getImag() const;
    double getModulus() const;
    double getMagnitude() const;
    double getPhase() const;

    void setReal(double real);
    void setImag(double imag);

    ComplexNumber operator+(const ComplexNumber& other) const;
    ComplexNumber operator-(const ComplexNumber& other) const;
    ComplexNumber operator*(const ComplexNumber& other) const;
    ComplexNumber operator/(const ComplexNumber& other) const;


    

    ComplexNumber conjugate() const;
    friend std::ostream &operator<<(std::ostream &os, const ComplexNumber &c);
};

#endif
