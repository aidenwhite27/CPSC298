// @file leibnitz_pi.cpp
// @brief This program approximates the value of pi (with user-defiend accuracy) using a series
// @author Aiden White aiwhite@chapman.edu

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cfloat>
using namespace std;

int main()
{
    double pi = 0.0;

    cout << "Please enter a non-negative integer upper limit of summation for the Leibnitz " <<
        "formula for computing pi:" << endl;

    int upperLimit;
    cin >> upperLimit;
    const int n = upperLimit;

    for (int k = 0; k <= n; k++) {
        pi += 4 * ((pow(-1, k) / (2.0 * k + 1)));
    }
    
    cout << "PI (approx): " << fixed << setprecision(DBL_DIG) << pi << "; n: " << setw(7) << n << endl;
    cout << "PI (actual): " << "3.141592653589793" << endl;
    cout << "Decimal digits of precision: " << DBL_DIG << endl;
    cout << "Number of base 2 mantissa digits of double precision floating point value: " <<
        DBL_MANT_DIG << endl;
    cout << "Next representable number from 3.141592653589793: " <<
        nextafter(3.141592653589793, 3.14) << endl;
}

