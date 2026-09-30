/********************************************************************************
 * Author: [Your Name]
 * Date: [Date of Creation or Last Update]
 * Purpose: 
 ********************************************************************************/

// Polynomial.h
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>
#include <iostream>

class Polynomial {
public:
    Polynomial(const std::vector<double>& coefficients);

    Polynomial operator+(const Polynomial& other) const;
    Polynomial operator-(const Polynomial& other) const;
    Polynomial operator*(const Polynomial& other) const;
    Polynomial operator-() const;
    Polynomial operator/(const Polynomial& other) const;
    
    friend std::ostream& operator<<(std::ostream& os, const Polynomial& p);

private:

    std::vector<double> _coeff;
    int _degree;
};

#endif // POLYNOMIAL_H
