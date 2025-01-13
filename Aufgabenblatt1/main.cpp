#include <iostream>
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

std::string pdfAnhaengen(const std::string& s) {
    std::string r{s};
    return r.append(".pdf");
}

/*
 Verstädnisfrage: Warum compiliert diese Funktion nicht?

std::string pdfAnhaengen(const std::string& s) {
    return s.append(".pdf");
}
*/

void unittestPdfAnhaengen()
{
    std::string s{"Präsentation"};
    std::cout << "Neuer Dateiname: " << pdfAnhaengen(s) << endl;
}

/* Viele alternativen möglich: z.B:
 * - string_view
 * - Vergleich selber durchführen
 * - ...
 */
 bool jpgAnpassen(std::string& s) {
     const std::string e{".jpeg"};
     const std::string n{".jpg"};
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

 void unittestJpgAnpassen(std::string& s)
{
    if (jpgAnpassen(s)) {
        cout << "Dateiname musste angepasst werden!" << endl;
        cout << "Neuer Dateiname: " << s << endl;
    } else {
        cout << "Dateiname musste nicht angepasst werden!" << endl;
        cout << "Alter Dateiname: " << s << endl;
    }
}

int main()
{
    unittestPdfAnhaengen();

    Rechteck r1{1.0, 1.0/3.0};
    unittestRechteck(r1);
    Rechteck r2{0.3, 0.1 + 0.2};
    unittestRechteck(r2);

    std::string s1{"Präsentation.jpeg"};
    unittestJpgAnpassen(s1);
    std::string s2{"SoEinDreck"};
    unittestJpgAnpassen(s2);
    std::string s3{"WasHast.jepgDuGeraucht"};
    unittestJpgAnpassen(s3);

    return 0;
}
