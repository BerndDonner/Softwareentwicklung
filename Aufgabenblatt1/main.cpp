#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

struct Rechteck {
    double laenge;
    double breite;
    double flaeche() const;
    double umfang() const;
    bool istQuadrat() const;
};

double Rechteck::flaeche() const {
    return laenge*breite;
}

double Rechteck::umfang() const {
    return 2*(laenge+breite);
}

bool Rechteck::istQuadrat() const {
    //if (laenge == breite) return true; // falsch für Rechteck r2!!!
    if (abs(laenge - breite) < __DBL_EPSILON__) return true;
    return false;
}

void unittestRechteck(const Rechteck& r) {

    cout << "Länge:  " << r.laenge << endl;
    cout << "Breite: " << r.breite << endl;
    cout << "Fläche: " << r.flaeche() << endl;
    cout << "Umfang: " << r.umfang() << endl;
    if (r.istQuadrat() == true) cout << "Dieses Rechteck ist ein Quadrat." << endl;
    else cout << "Dieses Rechteck ist kein Quadrat." << endl;

}

string pdfAnhaengen(const string& s) {
    return s + ".pdf";
}

/*
Verstädnisfrage: Warum compiliert diese Funktion nicht?

string pdfAnhaengen(const string& s) {
    return s.append(".pdf");
}
*/

void unittestPdfAnhaengen()
{
    string s{"Präsentation"};
    cout << "Neuer Dateiname: " << pdfAnhaengen(s) << endl;
}

/* Viele alternativen möglich: z.B:
 * - string_view
 * - Vergleich selber durchführen
 * - ...
 */
 bool jpgAnpassen(string& s) {
     const string e{".jpeg"};
     const string n{".jpg"};
    size_t p = s.rfind(e);
    // TODO nach der SA:
    // Errorhandling
    // entweder: Enum als Rückgabewert für Fehler
    // oder:     throw Exception
    if (p == string::npos) return false;
    if (p != s.length()-e.length()) return false;
    s.replace(p, e.length(), n);
    return true;
}

 void unittestJpgAnpassen(string& s)
{
    if (jpgAnpassen(s)) {
        cout << "Dateiname musste angepasst werden!" << endl;
        cout << "Neuer Dateiname: " << s << endl;
    } else {
        cout << "Dateiname musste nicht angepasst werden!" << endl;
        cout << "Alter Dateiname: " << s << endl;
    }
}


string nurASCII(const string& s)
{
    // TODO nach der SA:
    // über einen String läuft eigentlich man mit Iteratoren
    string r{""};
    for (size_t i = 0; i < s.length(); ++i)
    {
        if (static_cast<unsigned char>(s[i]) <= '\x7f') r += s[i];
        // if (static_cast<unsigned char>(s[i]) <= 127) r += s[i]; // das geht auch
    }
    return r;
}

void unittestNurASCII(const string& s)
{
    cout << "Orginal String:         " << s << endl;
    cout << "ASCII-Teil des Strings: " << nurASCII(s) << endl;
}


string erstelleSmiley(size_t anzahl)
{
    assert(anzahl <= 8);
    string smilies;
    // siehe https://codepoints.net
    string smileyListe[] = {
        "\U0001F60A",
        "\U0001F602",
        "\U0001F60D",
        "\U0001F60E",
        "\U0001F622",
        "\U0001F621",
        "\U0001F44D",
        "\u2764"
    };

    for (size_t i = 0; i < anzahl; ++i)
    {
        smilies += smileyListe[i];
    }

    return smilies;
}


void unittestErstelleSmiley()
{
    cout << "Ein Smiley  : " << erstelleSmiley(1) << endl;
    cout << "Acht Smileys: " << erstelleSmiley(8) << endl;
}

string ruekwaerts(const string& s)
{
    string r{""};
    for (size_t i = s.length(); i > 0; --i)
    {
        if (static_cast<unsigned char>(s[i-1]) > 127)
        {
            //kein ASCII-String wir geben dann den leeren String zurück
            cout << "ERROR: Das ist kein ASCII String!" << endl;
            return "";
        }
        r += s[i-1];
    }
    return r;
}

void unittestRueckwaerts(const string& s)
{
    cout << "Orginal String:     " << s << endl;
    cout << "Rueckwaerts String: " << ruekwaerts(s) << endl;
}


//Groß und Kleinschreibung wird hier berücksichtigt!
bool istPalindrome(const string& s)
{
    // Auch so etwas geht: i startet von vorne im string j von hinten, wenn Sie sich überholen würden wird abgebrochen.
    //for(Startbedingungen; Abbruchbedingung; Was machen beim nächsten Schritt)
    for (size_t i = 0, j = s.length()-1;   i<j;   ++i, --j)
    {
        if (static_cast<unsigned char>(s[i]) > 127) return false; //kein ASCII-String
        if (static_cast<unsigned char>(s[j]) > 127) return false; //kein ASCII-String
        if (s[i] != s[j]) return false; //kein Palindome
    }
    return true;
}

void unittestIstPalindrome(const string s)
{
    if (istPalindrome(s))
    {
        cout << s << " ist ein ASCII-Palindrome!" << endl;
    }
    else
    {
        cout << s << " ist kein Palindrome oder enthält Zeichen, die nicht ASCII sind." << endl;
    }
}


int main()
{
    //Aufgabe 1
    unittestPdfAnhaengen();

    //Aufgabe 2
    string s1{"Präsentation.jpeg"};
    unittestJpgAnpassen(s1);
    string s2{"SoEinDreck"};
    unittestJpgAnpassen(s2);
    string s3{"WasHast.jepgDuGeraucht"};
    unittestJpgAnpassen(s3);

    //Aufgabe 3
    string s4{"Ich bin nur ASCII!"};
    unittestNurASCII(s4);
    string s5{"Öch bün nächt nür ÄßCII."};
    unittestNurASCII(s5);

    //Aufgabe 4
    unittestErstelleSmiley();

    //Aufgabe 5
    string s6{"Softwareentwicklung"};
    unittestRueckwaerts(s6);
    //das darf nicht klappen, da es kein ASCII-String ist.
    string s7{"Änderungsschneiderei"};
    unittestRueckwaerts(s7);


    //Aufgabe 6
    string s8{"otto"};
    unittestIstPalindrome(s8);
    string s9{"ötsttstö"};
    unittestIstPalindrome(s9);
    string s10{"Schokoladentorte"};
    unittestIstPalindrome(s10);

    //Aufgabe 7
    Rechteck r1{1.0, 1.0/3.0};
    unittestRechteck(r1);
    Rechteck r2{0.3, 0.1 + 0.2};
    unittestRechteck(r2);

    return 0;
}
