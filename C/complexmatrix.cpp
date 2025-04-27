#include "complexmatrix.h"
#include <stdexcept>

ComplexMatrix::ComplexMatrix(const std::vector<ComplexVector> &elements) : elements(elements) {}

int ComplexMatrix::size_rows() const {
    return elements.size();
}

int ComplexMatrix::size_cols() const {
    if (elements.empty()) {
        return 0;
    }
    return elements[0].size();
}


ComplexMatrix ComplexMatrix::operator+(const ComplexMatrix& other) const
{
    if (size_rows() != other.size_rows() || size_cols() != other.size_rows()){
        throw std::invalid_argument("Matrixes must be of the same dimension for addition.");
    }
    std::vector<ComplexVector> result;
    for (int i = 0; i < size_rows(); ++i){
        result.push_back(elements[i] + other.elements[i]);
    }
    return ComplexMatrix(result);
}


ComplexMatrix ComplexMatrix::operator-() const{
    std::vector<ComplexVector> result;
    for (const auto& element : elements)
    {
        result.push_back(-element);
    }
    return ComplexMatrix(result);
}






std::ostream &operator<<(std::ostream &os, const ComplexMatrix &matrix)
{
    os << "\n";
    for (const auto &row : matrix.elements)
    {
        os << "["; 
        for (size_t i = 0; i < row.getElements().size(); ++i)
        {
            os << row.getElements()[i]; 
            if (i < row.getElements().size() - 1)
            {
                os << "\t"; 
            }
        }
        os << "]\n"; 
    }
    return os;
}

ComplexMatrix ComplexMatrix::operator-(const ComplexMatrix &other) const
{
    if (size_rows() != other.size_rows() || size_cols() != other.size_cols())
    {
        throw std::invalid_argument("Matrixes must be of the same dimension for addition.");
    }

    std::vector<ComplexVector> result;
    for (size_t i = 0; i < size_rows(); ++i)
    {
        result.push_back(elements[i] - other.elements[i]);
    }
    return ComplexMatrix(result);
}

// ComplexMatrix ComplexMatrix::operator*(const ComplexMatrix& other) const{

//     if (size_cols() != other.size_rows())
//     {
        
//     }
    
// }

