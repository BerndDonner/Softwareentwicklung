#include <iostream>
#include <cmath>

using namespace std;

struct Rechteck {
    double a;
    double b;
    double flaeche() const;
    double umfang() const;
    bool isQuadrat() const;
};


double Rechteck::flaeche() const
{
    return a*b;
}


double Rechteck::umfang() const
{
    return 2*(a+b);
}


bool Rechteck::isQuadrat() const
{
    return (abs(a - b) < __DBL_EPSILON__);
    //return (a==b);
}


void unittestRechteck(const Rechteck& r)
{
    cout << "a: " << r.a << endl;
    cout << "b: " << r.b << endl;
    cout << "Fläche: " << r.flaeche() << endl;
    cout << "Umfang: " << r.umfang() << endl;
    if (r.isQuadrat()) {
        cout << "Du bist ein Quadrat!" << endl;
    } else {
        cout << "Du bist ein echtes Rechteck!" << endl;
    }

}


string pdfAnhaengen(const string& d)
{
    return d + ".pdf";
}


int main()
{
    string d{"Dokument"};
    cout << "Neue Dateiendung pdf: " << pdfAnhaengen(d) << endl;


    Rechteck r{1., 3.};
    unittestRechteck(r);

    Rechteck r1{0.3, 0.2+0.1};
    unittestRechteck(r1);

    return 0;
}
