/********************************************************************************
 * Author: 陳宥宇
 * Date: Oct.3.2026
 * Purpose: Assignment 1 for MATH208, implementing a Polynomial class with basic operations.
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
