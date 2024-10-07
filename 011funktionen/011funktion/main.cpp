#include <iostream>
#include <cmath> // für die exp-Funktion

using namespace std;

double linear(double x, double m, double t)
{
    double y = m*x + t;
    return y;
//    return m*x + t;
}

int main()
{
    double x = -1.0;
    double r1 = exp(x);
    double r2 = linear(x, 3.0, 100.0);

    cout << "     e(" << x << ") = " << r1 << endl;
    cout << "linear(" << x << ") = " << r2 << endl;
    return 0;
}
