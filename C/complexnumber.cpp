#include "complexnumber.h"
#include <stdexcept>
#include <math.h>
#include <sstream> 
#include <iostream>
#include <regex>

ComplexNumber::ComplexNumber(double magnitude, double phase, bool isPolar)
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

ComplexNumber::ComplexNumber(const char *str) : ComplexNumber(std::string(str)) {}

ComplexNumber::ComplexNumber(const std::string &str)
{
    real_ = 0;
    imag_ = 0;



    std::string cleaned;
    for (char c : str)
    {
        if (!std::isspace(c))
        {
            cleaned += c;
        }
    }

    static const std::regex full_complex(R"(^([-+]?\d*\.?\d+)([-+]\d*\.?\d+)i$)");
    static const std::regex pure_real(R"(^([-+]?\d*\.?\d+)$)");
    static const std::regex pure_imag(R"(^([-+]?\d*\.?\d+)i$)");

    std::smatch match;
    if (std::regex_match(cleaned, match, full_complex))
    {
        real_ = std::stod(match[1]);
        imag_ = std::stod(match[2]);
    }
    else if (std::regex_match(cleaned, match, pure_real))
    {
        real_ = std::stod(match[1]);
        imag_ = 0;
    }
    else if (std::regex_match(cleaned, match, pure_imag))
    {
        real_ = 0;
        imag_ = std::stod(match[1]);
    }
    else
    {
        throw std::invalid_argument("Invalid complex number format: " + str);
    }

    updatePolar();
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

std::ostream &operator<<(std::ostream &os, const ComplexNumber &c)
{
    os << c.getReal();
    if (c.getImag() != 0)
        os << (c.getImag() > 0 ? " + " : " - ") << std::abs(c.getImag()) << "i";
    return os;
}
