#include <iostream>
#include <cmath> // für die exp-Funktion

using namespace std;

double linear(double, double, double );
int linear(int x, int m, int t);

int main()
{
    double x = -1.0;
    double steigung = 3.0;
    double y_achsenabschnitt = 100.0;
    double r1 = exp(x);
    double r2 = linear(x, steigung, y_achsenabschnitt);
    int r3 = linear(3, 4, 5);

    cout << "                e(" << x << ") = " << r1 << endl;
    cout << "x = " << x << " ---> " << steigung << "*x + " << y_achsenabschnitt <<" = " << r2 << endl;
    return 0;
}

double linear(double x, double m, double t)
{
    double y = m*x + t;
    return y;
    //    return m*x + t;
}

int linear(int x, int m, int t)
{
    int y = m*x + t;
    return y;
}
