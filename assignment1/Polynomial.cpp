/********************************************************************************
 * Author: 陳宥宇
 * Date: Sep30,2026
 * Purpose: Data Structure Assignment 1
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

}

/**
 * Overload negation operator for negating a polynomial.
 * 
 * Return:
 *     Polynomial: The negated polynomial.
 */
Polynomial Polynomial::operator-() const {

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
/*
Environment Description
My programming environment utilizes a remote development setup focused on C++ development. 
I write code on my local machine using Visual Studio Code (VS Code) with the "Remote - SSH" extension, which connects seamlessly to a remote server running Debian GNU/Linux 13 (Trixie).
My primary compiler on the server is G++, specifically version ⁠g++ (Debian 14.2.0-19) 14.2.0⁠.
*/


