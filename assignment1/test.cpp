/********************************************************************************
 * Author: 陳宥宇
 * Date: Oct.3.2026
 * Purpose: Assignment 1 for MATH208, implementing a Polynomial class with basic operations.
 ********************************************************************************/

#include "Polynomial.h"
#include <iostream>

int test() {
    // Create polynomial p1: x - 1
    Polynomial p1({1, -1});
    std::cout << "p1: " << p1 << std::endl;

    // Create polynomial p2: -2x^3 + x^2 - x
    Polynomial p2({-2, 1, -1, 0});
    std::cout << "p2: " << p2 << std::endl;

    // Create polynomial p3: x^4 - 6x - 1
    Polynomial p3({0, 1, 0, 0, -6, -1});
    std::cout << "p3: " << p3 << std::endl;

    // Create polynomial p4: 0.5
    Polynomial p4({0.5});
    std::cout << "p4: " << p4 << std::endl;

    // Negate p2 and assign to p5
    Polynomial p5 = -p2;
    std::cout << "p5  (-p2): " << p5 << std::endl;

    // Add p1 and p2
    Polynomial p6 = p1 + p2;
    std::cout << "p6  (p1 + p2): " << p6 << std::endl;

    // Subtract p2 from p1
    Polynomial p7 = p1 - p2;
    std::cout << "p7  (p1 - p2): " << p7 << std::endl;

    // Multiply p1 and p2
    Polynomial p8 = p1 * p2;
    std::cout << "p8  (p1 * p2): " << p8 << std::endl;

    // Multiply p1 and p3
    Polynomial p9 = p1 * p3;
    std::cout << "p9  (p1 * p3): " << p9 << std::endl;

    // Subtract p3 from p6
    Polynomial p10 = p6 - p3;
    std::cout << "p10 (p6 - p3): " << p10 << std::endl;

    // Add p8 and p1
    Polynomial p11 = p8 + p1;
    std::cout << "p11 (p8 + p1): " << p11 << std::endl;

    // Multiply p9 and p4
    Polynomial p12 = p9 * p4;
    std::cout << "p12 (p9 * p4): " << p12 << std::endl;

    // Multiply p11 and p1
    Polynomial p13 = p11 * p1;
    std::cout << "p13 (p11 * p1): " << p13 << std::endl;

    // Add p12 and p4
    Polynomial p14 = p12 + p4;
    std::cout << "p14 (p12 + p4): " << p14 << std::endl;

    // Add negated p4 and p5
    Polynomial p15 = -p4 + p5;
    std::cout << "p15 (-p4 + p5): " << p15 << std::endl;

    return 0;
}
/*
p1: x - 1 
p2: - 2x^3 + x^2 - x 
p3: x^4 - 6x - 1 
p4: 0.5 
p5  (-p2): 2x^3 - x^2 + x 
p6  (p1 + p2): - 2x^3 + x^2 - 1 
p7  (p1 - p2): 2x^3 - x^2 + 2x - 1 
p8  (p1 * p2): - 2x^4 + 3x^3 - 2x^2 + x 
p9  (p1 * p3): x^5 - x^4 - 6x^2 + 5x + 1 
p10 (p6 - p3): - x^4 - 2x^3 + x^2 + 6x 
p11 (p8 + p1): - 2x^4 + 3x^3 - 2x^2 + 2x - 1 
p12 (p9 * p4): 0.5x^5 - 0.5x^4 - 3x^2 + 2.5x + 0.5 
p13 (p11 * p1): - 2x^5 + 5x^4 - 5x^3 + 4x^2 - 3x + 1 
p14 (p12 + p4): 0.5x^5 - 0.5x^4 - 3x^2 + 2.5x + 1 
p15 (-p4 + p5): 2x^3 - x^2 + x - 0.5 
*/