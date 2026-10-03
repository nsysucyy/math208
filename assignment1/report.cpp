/********************************************************************************
 * Author: 陳宥宇
 * Date: Oct.3.2026
 * Purpose: Assignment 1 for MATH208, implementing a Polynomial class with basic operations.
 ********************************************************************************/
#include <iostream>
#include <vector>
#include <ctime>
#include "Polynomial.h" 
int benchmark();
int test();
int main() {
    using namespace std;
    cout << R"(
            [PROG ./as/as1 IS COMPILED FROM ./report.cpp, THE OUTPUT IS COPIED TO ./as/as1.txt]
                    ###"as1" is the abbreviation of "Assignment 1"###
 * Author: 陳宥宇
 * Last Updated: Oct.3.2026
 * Purpose: Assignment 1 for MATH208, implementing a Polynomial class with basic operations.

                    --- Assignment 1: Designing a Polynomial Calculator ---

## Chapter 0: AI Usage Disclaimer
In the process of completing this assignment,
I utilized Generative AI (e.g., Google Gemini) as an interactive learning assistant.
The AI was used to help troubleshoot compiler warnings (such as type casting between size_t and int),
brainstorm optimization strategies (Time Complexity / Big O analysis), and format the structure of this report.
The core algorithmic logic, data structure design, and final code implementation were thoroughly 
reviewed, modified, and tested by me to ensure complete understanding and correctness. 
I take full responsibility for the final output.

## Chapter 1: Environment Description
My programming environment utilizes a remote development setup focused on C++ development. 
I write code on my local machine using Visual Studio Code (VS Code) with the "Remote - SSH" extension,
which connects seamlessly to a remote server running Debian GNU/Linux 13 (Trixie).
Primary compiler on the server is G++, specifically version g++ (Debian 14.2.0-19) 14.2.0.

## Chapter 2: Abstract
This assignment focuses on using teachers templates to design and implementing a Polynomial class with basic operations 
such as addition, subtraction, multiplication, and negation.
At this file, I will provide a detailed description of each operation and explain the optimization strategies used in the implementation, 
after that, I will present the results of the benchmark tests and analyze the performance of the implemented operations.

## Chapter 3: Design and Implementation

 * Initialize
In this part, the function processes the input coefficients, removing leading zeros and determining the polynomial's degree.
So I stated a flag to skip leading coefficients that are effectively zero (i.e., their absolute value is less than 1e-9).
And then, I packed the remaining coefficients into the polynomial's internal representation.
Finally, I set the _degree of the polynomial based on the number of non-zero coefficients.

 * Addition
In the addition operation, I stated the result degree as the maximum of the two polynomial degrees.
Then, I created a result coefficients vector initialized to zero, with a size of result_degree + 1.
I calculated the offsets for both polynomials to align their coefficients correctly in the result vector
and then iterated through the coefficients of both polynomials, adding them to the appropriate positions in the result coefficients vector.
There is a alternative approach to addition, which is share the same degree then decide whether to add into the result degree by checking the offset,
but this approach requires more complex handling of different degrees and is less efficient.
This approach is taught by AI, AI suggested this approach.

 * Subtraction
In the subtraction operation, I found that it is the same as addition, 
but I just need to negate the coefficients of the second polynomial before adding them to the result.
So, I can reuse the addition logic by negating the coefficients of the second polynomial and then performing addition.

 * Multiplication
In the multiplication operation, I stated the result degree as the sum of the two polynomial degrees.
Then, I created a result coefficients vector initialized to 0.0, with a size of result_degree + 1.
The reason I initialized the result coefficients vector to 0.0 not 0 is to avoid integer division issues when multiplying coefficients that are floating-point numbers.
Which is also suggested by AI, It is a good practice to use floating-point numbers for coefficients in polynomial operations to maintain precision.
I used a nested loop to iterate through the coefficients of both polynomials, multiplying them
and adding the results to the appropriate positions in the result coefficients vector.
Simply, the coefficient of the resulting polynomial at degree i + j is the sum of the products of the coefficients of the two polynomials at degrees i and j.

 * Negation
In the negation operation, I created a new coefficients vector with the same size as the current polynomial's coefficients vector.
Then, I iterated through the coefficients of the current polynomial, negating each coefficient and storing it in the new coefficients vector.
Finally, I returned a new Polynomial object constructed with the negated coefficients vector.

## Chapter 4: Time Complexity (Big O) and Benchmark Analysis

1. Time Complexity Analysis (Big O Notation)

 * Addition and Subtraction
Both operations align the arrays and iterate through the coefficients sequentially without any nested loops. 
Therefore, the time complexity is strictly linear, denoted as O(N), where N is the maximum degree of the two polynomials (max(degree1, degree2)).

 * Multiplication
This operation requires every term of the first polynomial to be multiplied by every term of the second polynomial using a double nested loop. 
Therefore, the time complexity is quadratic, denoted as O(N * M) (where N and M are the degrees of the respective polynomials). 
Assuming both polynomials have a similar degree N, it simplifies to O(N^2).

 * Negation
This operation iterates through the coefficients of a single polynomial exactly once to invert their signs. 
Therefore, its time complexity is strictly linear, denoted as O(N), where N is the degree of the polynomial.

2. The results of the benchmark tests are as follows:
)" << endl;
    benchmark();
    cout << R"(

## Chapter 5: Compile Report.cpp and Text based Output
Due to the memory leaking bug in my previous version there are three version of report.
All files are stored in the "as" folder.

#1.With AddressSanitizer (ASan) enabled, which can detect memory leaks and other memory-related issues. 
/usr/bin/g++ -fdiagnostics-color=always -std=c++17 -Wall -Wextra -I. -g -fsanitize=address /home/math/math208/assignment1/*.cpp -o /home/math/math208/assignment1/as/slowas1
#2.Without AddressSanitizer (ASan) enabled, the program will execute faster.
/usr/bin/g++ -fdiagnostics-color=always -std=c++17 -Wall -Wextra -I. -g /home/math/math208/assignment1/*.cpp -o /home/math/math208/assignment1/as/as1
#3.Text based output, txt.
Copy the output of the program to a text file, which can be done by redirecting the output when running the program in the terminal.

## Appendix 1: Test Cases
The following test cases were used to validate the correctness of the Polynomial class operations:
)" << endl;
    test();
    return 0;
}   
