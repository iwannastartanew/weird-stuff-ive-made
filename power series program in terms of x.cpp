// #include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;

double expression(double x, int terms) {
double result = 0.0, term = 1.0;
    for (int n = 0; n < terms; ++n) {
        result += term;
        term *= x / (n + 1);
    }
    return result;
}

int main()
{
    double x;
    int num_terms;

    cout << "x: ";
    cin >> x;
    cout << "number of terms in the power series: ";
    cin >> num_terms;

    double result = expression(x, num_terms);
    cout << "e^" << x << " ≈ " << result << endl;
    return 0;
}
