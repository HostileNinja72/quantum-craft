#include "complexnumber.h"
#include <stdexcept>
#include <math.h>


ComplexNumber::ComplexNumber(double magnitude, double phase, bool isPolar=0)
{
    if (isPolar)
    {
        magnitude_ = magnitude;
        phase_ = phase;
        updateCartesian();
    }
    else
    {
        real_ = magnitude;
        imag_ = phase;
        updatePolar();
    }
}
double ComplexNumber::getReal() const
{
    return real_;
}

double ComplexNumber::getImag() const
{
    return imag_;
}

double ComplexNumber::getModulus() const
{
    return sqrt(real_ * real_ + imag_ * imag_);
}

void ComplexNumber::setReal(double real)
{
    real_ = real;
    updatePolar();
}

void ComplexNumber::setImag(double imag)
{
    imag_ = imag;
    updatePolar();
}

void ComplexNumber::updatePolar()
{
    magnitude_ = getModulus();
    phase_ = atan2(imag_, real_);
}

void ComplexNumber::updateCartesian()
{
    real_ = magnitude_ * cos(phase_);
    imag_ = magnitude_ * sin(phase_);
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &other) const
{
    return ComplexNumber(real_ + other.real_, imag_ + other.imag_);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &other) const
{
    return ComplexNumber(real_ - other.real_, imag_ - other.imag_);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &other) const
{
    return ComplexNumber(real_ * other.real_ - imag_ * other.imag_, real_ * other.imag_ + imag_ * other.real_);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &other) const
{
    double denominator = other.real_ * other.real_ + other.imag_ * other.imag_;
    if (denominator == 0)
    {
        throw std::invalid_argument("Division by zero");
    }
    double realPart = (real_ * other.real_ + imag_ * other.imag_) / denominator;
    double imagPart = (imag_ * other.real_ - real_ * other.imag_) / denominator;
    return ComplexNumber(realPart, imagPart);
}


ComplexNumber ComplexNumber::conjugate() const
{
    return ComplexNumber(real_, -imag_);
}