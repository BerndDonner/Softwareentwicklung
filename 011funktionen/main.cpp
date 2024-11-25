#include <iostream>
#include <cmath> // für die exp-Funktion
#include <string>
#include <cassert>

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

void unicodetest0()
{
    cout << "Sein oder nicht sein\ndas ist hier die Frage\nDas ist ein Backslash: \\\n";
    cout << "Das sind zwei Backslashes: \\\\\n";
    cout << "Dieter Nuhr: \"Wenn man keine Ahnung hat, einfach mal Fresse halten.\" \n";
    cout << "Das ist eine Übung\0 zu Escape Sequenzen.\n";
    cout << "\nWas bist Du fuer ein Zeichen: \x5e\n";
    char x = 'a';
    char z[] = u8"\u00ef";
    char y[] = u8"ß";

    cout << y << "\n";
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
    cout << "UTF-8: " << "\U0001FACE" << '\n';
}

void unicodetest2()
{
    char zeichen0 = 'a';
    char zeichen1[] = "\u00E9";
    char zeichen2[] = "\u03A9";
    char zeichen3[] = "\u213E";
    char zeichen4[] = "\U0001F609";

    cout << "Unicode Test 2\n";

    cout << "ASCII character: " << zeichen0 << endl;
    cout << "2Byte character: " << zeichen1 << endl;
    cout << "2Byte character: " << zeichen2 << endl;
    cout << "3Byte character: " << zeichen3 << endl;
    cout << "4Byte character: " << zeichen4 << endl;
}

void unicodetest3()
{
    string a = "ß";
    string b = R"(Drei Chinesen mit dem Kontrabass
saßen auf der Straße und erzählten sich was.
Da kam die Polizei, fragt[2] ‚Was ist denn das?‘
Drei Chinesen mit dem Kontrabass.)";
    string c = "Drei Chinesen mit dem Kontrabass\nsaßen auf der Straße und erzählten sich was.\nDa kam die Polizei, fragt[2] ‚Was ist denn das?‘\nDrei Chinesen mit dem Kontrabass.";

    cout << a << endl;
    cout << b << endl;
    cout << "\U0001f601\U0001f622" << endl;
    cout << "L'État c'est à moi" << endl;
    cout << "Πυθαγρας" << endl;
}


void string_test()
{
    string text = "Ich bin so toll!";
    string ins = "schön, ich bin so ";

    cout << text << endl;
    text.insert(11, ins);
    cout << text << endl;

    cout << sizeof(text) << endl;
    cout << text.size() << endl;
    cout << text[34] << endl;
}


unsigned int count_substring(const std::string& text, const std::string& substring)
{
    size_t idx = text.find(substring);
    unsigned int treffer = 0;

    while(idx != string::npos)
    {
        treffer +=1;
        std::cout << "gefundener Index: " << idx << endl;
        idx = text.find(substring, idx+1);
    }

    return treffer;
}

bool isVokal(const std::string& zeichen)
{
    string vokal = "AEIOUaeiouÄÖÜäöü";
    size_t idx = vokal.find(zeichen);

 //   return (idx != string::npos); Die kurze Variante

    if (idx == string::npos)
    {
        return false;
    } else {
        return true;
    }
}

int main()
{

/*
    funktionstest1();
    unicodetest0();
    unicodetest1();
    unicodetest2();
    unicodetest3();
    string_test();

    string zeichen = "D";
    unsigned int treffer = count_substring(china, zeichen);
    std::cout << "gefundener Treffer: " << treffer << endl;
*/
    assert(isVokal("a") == true );
    assert(isVokal("b") == false );

    string china[] = {"D", "r", "e", "i", " ", "C", "h", "i", "n", "e", "s", "e", "n", " ", "m", "i", "t", " ", "d", "e", "m", " ",
        "K", "o", "n", "t", "r", "a", "b", "a", "s", "s", "\n", "s", "a", "ß", "e", "n", " ", "a", "u", "f", " ", "d", "e", "r", " ",
        "S", "t", "r", "a", "ß", "e", " ", "u", "n", "d", " ", "e", "r", "z", "ä", "h", "l", "t", "e", "n", " ", "s", "i", "c", "h",
        " ", "w", "a", "s", ".", "\n", "D", "a", " ", "k", "a", "m", " ", "d", "i", "e", " ", "P", "o", "l", "i", "z", "i", ",", " ",
        "f", "r", "a", "g", "t", "[", "2", "]", " ", "‘", "W", "a", "s", " ", "i", "s", "t", " ", "d", "e", "n", "n", " ",
        "d", "a", "s", "?", "’", "\n", "D", "r", "e", "i", " ", "C", "h", "i", "n", "e", "s", "e", "n", " ", "m", "i", "t", " ",
        "d", "e", "m", " ", "K", "o", "n", "t", "r", "a", "b", "a", "s", "s", "."};
    string china_neu = "";

    for(size_t i=0; i < sizeof(china)/sizeof(string); i++)
    {
        string zeichen = china[i];
        if (isVokal(zeichen) == false) china_neu.append(zeichen);
        else china_neu.append("ä");
    }

    cout << china_neu << endl;


    return 0;
}
