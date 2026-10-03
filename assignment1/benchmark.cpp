/********************************************************************************
 * Author: 陳宥宇
 * Date: Oct.3.2026
 * Purpose: Assignment 1 for MATH208, implementing a Polynomial class with basic operations.
 ********************************************************************************/

#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#include "Polynomial.h" 

int benchmark() {

    std::random_device rd;  
    std::mt19937 gen(rd()); //mersenne twister engine seeded with rd()
    std::uniform_real_distribution<double> dis(-10.0, 10.0); 

    //state the coefficients vectors for two polynomials of 50 coefficients
    std::vector<double> c1(50);
    std::vector<double> c2(50);

    //insert random numbers into c1 and c2
    for (int i = 0; i < 50; ++i) {
        c1[i] = dis(gen);
        c2[i] = dis(gen);
    }

    Polynomial p1(c1);
    Polynomial p2(c2);

    const int ITERATIONS = 10000;
    
    std::cout << "--- Benchmark Results (" << ITERATIONS << " iterations) ---\n";

    // Addition
    clock_t start_add = clock();
    for (int i = 0; i < ITERATIONS; ++i) {
        Polynomial p_add = p1 + p2;
    }
    clock_t end_add = clock(); 
    double time_add = static_cast<double>(end_add - start_add) / CLOCKS_PER_SEC;
    std::cout << "Addition (+) Time      : " << time_add << " seconds\n";

    // Subtraction
    clock_t start_sub = clock();
    for (int i = 0; i < ITERATIONS; ++i) {
        Polynomial p_sub = p1 - p2;
    }
    clock_t end_sub = clock();
    double time_sub = static_cast<double>(end_sub - start_sub) / CLOCKS_PER_SEC;
    std::cout << "Subtraction (-) Time   : " << time_sub << " seconds\n";

    // Multiplication
    clock_t start_mul = clock();
    for (int i = 0; i < ITERATIONS; ++i) { 
        Polynomial p_mul = p1 * p2;
    }
    clock_t end_mul = clock();
    
    double time_mul = (static_cast<double>(end_mul - start_mul) / CLOCKS_PER_SEC) * 100;
    std::cout << "Multiplication (*) Time: " << time_mul << " seconds\n";

    // Negation
    clock_t start_neg = clock();
    for (int i = 0; i < ITERATIONS; ++i) {
        Polynomial p_neg = -p1;
    }
    clock_t end_neg = clock();
    double time_neg = static_cast<double>(end_neg - start_neg) / CLOCKS_PER_SEC;
    std::cout << "Negation (-p) Time     : " << time_neg << " seconds\n";

    return 0;
}

