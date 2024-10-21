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

void unicodetest1()
{
    cout << "Unicode Test 1\n";

    // griechisches pi
    cout << "Unicode: " << "\u03C0" << '\n';
    // smiley
    cout << "Beyond BMP: " << "\U0001F600" << '\n';
    // griechisches Lambda
    cout << "UTF-8: " << "\u03BB" << '\n';
    // Wenn u8 verwendet werden muss
    cout << "UTF-8: " << reinterpret_cast<const char *>(
        u8"\U0001FACE") << '\n';
}

void unicodetest2()
{
    char zeichen0 = 'a';
    char zeichen1[] = u8"\u00E9";
    char zeichen2[] = u8"\u03A9";
    char zeichen3[] = u8"\u213E";
    char zeichen4[] = u8"\U0001F609";

    cout << "Unicode Test 2\n";

    cout << "ASCII character: " << zeichen0 << endl;
    cout << "2Byte character: " << zeichen1 << endl;
    cout << "2Byte character: " << zeichen2 << endl;
    cout << "3Byte character: " << zeichen3 << endl;
    cout << "4Byte character: " << zeichen4 << endl;
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

    unicodetest1();
    unicodetest2();

    return 0;
}
