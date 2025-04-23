#include "complexvector.h"
#include <stdexcept>
 


ComplexVector::ComplexVector(const std::vector<ComplexNumber>& elements) : elements(elements) {}


int ComplexVector::size() const {
    return elements.size();
}


ComplexVector ComplexVector::operator+(const ComplexVector& other) const {
    if (size() != other.size()) {
        throw std::invalid_argument("Vectors must be of the same size for addition.");
    }
    std::vector<ComplexNumber> result;
    for (int i = 0; i < size(); ++i) {
        result.push_back(elements[i] + other.elements[i]);
    }
    return ComplexVector(result);
}

ComplexVector ComplexVector::operator-() const {
    std::vector<ComplexNumber> result;
    for (const auto& element : elements) {
        result.push_back(element.conjugate());
    }
    return ComplexVector(result);
}

ComplexVector ComplexVector::operator-(const ComplexVector& other) const {
    if (size() != other.size()) {
        throw std::invalid_argument("Vectors must be of the same size for subtraction.");
    }
    std::vector<ComplexNumber> result;
    for (int i = 0; i < size(); ++i) {
        result.push_back(elements[i] - other.elements[i]);
    }
    return ComplexVector(result);
}

ComplexVector ComplexVector::operator*(const ComplexNumber& scalar) const {
    std::vector<ComplexNumber> result;
    for (const auto& element : elements) {
        result.push_back(element * scalar);
    }
    return ComplexVector(result);
}


ComplexNumber& ComplexVector::operator[](int index) {
    if (index < 0 || index >= size()) {
        throw std::out_of_range("Index out of range.");
    }
    return elements[index];
}

const ComplexNumber& ComplexVector::operator[](int index) const {
    if (index < 0 || index >= size()) {
        throw std::out_of_range("Index out of range.");
    }
    return elements[index];
}


std::ostream& operator<<(std::ostream& os, const ComplexVector& vec) {
    os << "[";
    for (size_t i = 0; i < vec.elements.size(); ++i) {
        os << vec.elements[i];
        if (i != vec.elements.size() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}