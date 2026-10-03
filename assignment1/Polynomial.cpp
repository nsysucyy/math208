/********************************************************************************
 * Author: 陳宥宇
 * Date: Oct.3.2026
 * Purpose: Assignment 1 for MATH208, implementing a Polynomial class with basic operations.
 ********************************************************************************/

#include "Polynomial.h"
#include <sstream>
#include <cmath>

/**
 * Constructor for Polynomial class.
 * 
 * Args:
 *     coefficients (const std::vector<double>&): A vector of coefficients for the polynomial.
 */

Polynomial::Polynomial(const std::vector<double>& coefficients) {
    // Skip leading coefficients that are effectively zero
    bool flag = true;
    for (size_t i = 0; i < coefficients.size(); ++i) {
        // Skip coefficients that are effectively zero
        if (std::fabs(coefficients[i]) < 1e-9 && flag) continue;
        //found a non-zero coefficient, set flag to true
        flag = false;
        //define _coeff
        _coeff.push_back(coefficients[i]);
    }
    // define _degree
    _degree = _coeff.size() - 1;
}

/**
 * Overload addition operator for adding two polynomials.
 * 
 * Args:
 *     other (const Polynomial&): The polynomial to add.
 * 
 * Return:
 *     Polynomial: The result of adding the current polynomial and the other polynomial.
 */
Polynomial Polynomial::operator+(const Polynomial& other) const {
    int result_degree = std::max(_degree, other._degree);
    int offset_self = result_degree - _degree;
    int offset_other = result_degree - other._degree;
    std::vector<double> result_coeffs(result_degree + 1, 0.0);
    //self{1, -1} + other{-2, 1, -1, 0} = result{-2, 2, -2, 0}
    //result_degree = 3

    // Loop through the coefficients of the current polynomial and add them to the result

    for (size_t i = 0; i <= static_cast<size_t>(_degree); ++i) {
        result_coeffs[i + offset_self] += _coeff[i];
        //i=0, offset_self=1, i+offset_self=1, result_coeffs[1] += _coeff[0] = 0
        //i=1, offset_self=1, i+offset_self=2, result_coeffs[2] += _coeff[1] = 1
        //i=2, offset_self=1, i+offset_self=3, result_coeffs[3] += _coeff[2] = -1
        
    }

    for (size_t i = 0; i <= static_cast<size_t>(other._degree); ++i) {
        result_coeffs[i + offset_other] += other._coeff[i];
        //i=0, offset_other=0, i+offset_other=0, result_coeffs[0] += other._coeff[0] = -2
        //i=1, offset_other=0, i+offset_other=1, result_coeffs[1] += other._coeff[1] = 1
        //i=2, offset_other=0, i+offset_other=2, result_coeffs[2] += other._coeff[2] = -1
        //i=3, offset_other=0, i+offset_other=3, result_coeffs[3] += other._coeff[3] = 0
    }
    
    /*
    // Alternative implementation using a single loop and if statements
    // Check if the current index is within the bounds of the coefficients of both polynomials

    for (int i = 0; i <= result_degree; ++i) {
        if (i >= offset_self) {
            result_coeffs[i] += _coeff[i - offset_self];
            //i = 0, offset_self = 1, i < offset_self, skip
            //i = 1, offset_self = 1, i >= offset_self, result_coeffs[1] += _coeff[1 - 1] = _coeff[0] = 0
            //i = 2, offset_self = 1, i >= offset_self, result_coeffs[2] += _coeff[2 - 1] = _coeff[1] = 1
            //i = 3, offset_self = 1, i >= offset_self, result_coeffs[3] += _coeff[3 - 1] = _coeff[2] = -1
        }
        if (i >= offset_other) {
            result_coeffs[i] += other._coeff[i - offset_other];
            //i = 0, offset_other = 0, i >= offset_other, result_coeffs[0] += other._coeff[0 - 0] = other._coeff[0] = -2
            //i = 1, offset_other = 0, i >= offset_other, result_coeffs[1] += other._coeff[1 - 0] = other._coeff[1] = 1
            //i = 2, offset_other = 0, i >= offset_other, result_coeffs[2] += other._coeff[2 - 0] = other._coeff[2] = -1
            //i = 3, offset_other = 0, i >= offset_other, result_coeffs[3] += other._coeff[3 - 0] = other._coeff[3] = 0
        }
    }
     
    */
    
    return Polynomial(result_coeffs);
}

/**
 * Overload subtraction operator for subtracting two polynomials.
 * 
 * Args:
 *     other (const Polynomial&): The polynomial to subtract.
 * 
 * Return:
 *     Polynomial: The result of subtracting the other polynomial from the current polynomial.
 */
Polynomial Polynomial::operator-(const Polynomial& other) const {
    int result_degree = std::max(_degree, other._degree);
    int offset_self = result_degree - _degree;
    int offset_other = result_degree - other._degree;
    std::vector<double> result_coeffs(result_degree + 1, 0.0);

    for (size_t i = 0; i <= static_cast<size_t>(_degree); ++i) {
        result_coeffs[i + offset_self] += _coeff[i];
    }
   
    for (size_t i = 0; i <= static_cast<size_t>(other._degree); ++i) {
        result_coeffs[i + offset_other] -= other._coeff[i];
         //decrease the coefficients of the other polynomial from the result
    }
    
    return Polynomial(result_coeffs);

}

/**
 * Overload multiplication operator for multiplying two polynomials.
 * 
 * Args:
 *     other (const Polynomial&): The polynomial to multiply with.
 * 
 * Return:
 *     Polynomial: The product of the current polynomial and the other polynomial.
 */
Polynomial Polynomial::operator*(const Polynomial& other) const {
    //self{1, -1} * other{-2, 1, -1, 0} = result{-2, 3, -1, 0, 0}

    int result_degree = _degree + other._degree;
    std::vector<double> result_coeffs(result_degree + 1, 0.0);
    // Loop through the coefficients of both polynomials and multiply them
    // adding the results to the degree added index in the result coefficients vector
    for (size_t i = 0; i <= static_cast<size_t>(_degree); ++i) {
        for (size_t j = 0; j <= static_cast<size_t>(other._degree); ++j) {
            result_coeffs[i + j] += _coeff[i] * other._coeff[j];
        }
    }

    return Polynomial(result_coeffs);

}

/**
 * Overload negation operator for negating a polynomial.
 * 
 * Return:
 *     Polynomial: The negated polynomial.
 */
Polynomial Polynomial::operator-() const {
    std::vector<double> negated_coeffs(_coeff.size());
    // Loop through the coefficients of the current polynomial and negate them
    for (size_t i = 0; i < _coeff.size(); ++i) {
        negated_coeffs[i] = -_coeff[i];
    }
    return Polynomial(negated_coeffs);
}


// Do not modify the code below

/**
 * Overload the stream insertion operator for printing a polynomial.
 * 
 * Args:
 *     os (std::ostream&): Output stream to which the polynomial is written.
 *     p (const Polynomial&): The polynomial to be printed.
 * 
 * Return:
 *     std::ostream&: Reference to the output stream.
 */
std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
    bool first_term = true;
    for (size_t i = 0; i < p._coeff.size(); ++i) {
        int power = p._degree - i;

        // Skip coefficients that are effectively zero
        if (std::fabs(p._coeff[i]) < 1e-9) continue;

        std::ostringstream coeff_stream;
        coeff_stream << std::fabs(p._coeff[i]);
        std::string coeff_str = coeff_stream.str();

        // Remove trailing zeros and decimal point if necessary
        if (coeff_str.find('.') != std::string::npos) {
            coeff_str.erase(coeff_str.find_last_not_of('0') + 1, std::string::npos);
            if (coeff_str.back() == '.') {
                coeff_str.pop_back();
            }
        }

        // Adjust coeff_str for coefficients of 1 or -1 for non-constant terms
        if ((std::fabs(p._coeff[i]) == 1) && power != 0) {
            coeff_str = "";
        } else if (std::floor(std::fabs(p._coeff[i])) == std::fabs(p._coeff[i])) {
            coeff_str = std::to_string(static_cast<int>(std::fabs(p._coeff[i])));
        }

        std::string term;
        if (power == 0) {
            term = coeff_str;
        } else if (power == 1) {
            term = coeff_str + "x";
        } else {
            term = coeff_str + "x^" + std::to_string(power);
        }

        if (p._coeff[i] > 0 && !first_term) {
            term = "+ " + term;
        } else if (p._coeff[i] < 0) {
            term = "- " + term;
        }
        os << term << " ";
        first_term = false;
    }

    if (first_term) {
        os << "0";
    }

    return os;
}

// Do not modify the code above
