// @file leibnitz_pi_converge.cpp
// @brief This program shows how the Leibnitz Formula converges to the value of pi as terms are added
// @author Aiden White aiwhite@chapman.edu

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cfloat>
using namespace std;

int main()
{
    double pi = 0.0;

    for (int n = 2; n <= pow(2, 20); n *= 2) {

        pi = 0.0;

        for (int k = 0; k <= n; k++) {
            pi += 4 * ((pow(-1, k) / (2.0 * k + 1)));
        }

        cout << "PI: " << fixed << setprecision(DBL_DIG) << pi << "; n: " << setw(7) << n << endl;
    }

    return 0;
}