#include <iostream>
#include <cmath> // für die exp-Funktion

using namespace std;

double linear(double, double, double );
int linear(int x, int m, int t);

void funktionstest1()
{
    double x = -1.0;
    double steigung = 3.0;
    double y_achsenabschnitt = 100.0;

    int x_int = 3;
    int m_int = 4;
    int t_int = 5;
    double r1 = exp(x);
    double r2 = linear(x, steigung, y_achsenabschnitt);
    int r3 = linear(x_int, m_int, t_int);

    cout << "                e(" << x << ") = " << r1 << endl;
    cout << "x = " << x << " ---> " << steigung << "*x + " << y_achsenabschnitt <<" = " << r2 << endl;
    cout << "x = " << x_int << " ---> " << m_int << "*x + " << t_int <<" = " << r3 << endl;
}

double linear(double x, double m, double t)
{
    cout << "Double Version wird verwendet\n";
    double y = m*x + t;
    return y;
    //    return m*x + t;
}

int linear(int x, int m, int t)
{
    cout << "Int Version wird verwendet\n";
    int y = m*x + t;
    return y;
}

int main()
{
//    funktionstest1();
    cout << "Sein oder nicht sein\ndas ist hier die Frage\nDas ist ein Backslash: \\\n";
    cout << "Das sind zwei Backslashes: \\\\\n";
    cout << "Dieter Nuhr: \"Wer keine Ahnung hat sollte einfach mal die Fresse halten.\" \n";
    cout << "Das ist eine Übung\0 zu Escape Sequenzen.\n";
    cout << "\nWas bist Du fuer ein Zeichen: \x5e\n";
    char x = 'a';
    char z[] = u8"\u00ef";
    char y[] = u8"ß";

    cout << y << "\n";
    return 0;
}
