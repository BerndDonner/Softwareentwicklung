#include <iostream>

struct Koordinate {       //Koordinate ist jetzt ein neuer Datentyp
    double x;
    double y;
};

struct Auto {
    std::string marke;
    std::string modell;
    int         baujahr;
};

struct MyString {
    size_t laenge;
    char* daten;
};


int main() {
    double Nullstelle = 1.5;
    double Viele_Nullstellen[] = {-2.0, -1.0, 3.0};


    std::cout << "---------- Runde eins ----------" << std::endl;
    std::cout << Nullstelle << std::endl;
    for (int i{0}; i < 3; ++i)
    {
        std::cout << Viele_Nullstellen[i] << std::endl;
    }

    std::cout << "---------- Runde zwei ----------" << std::endl;
    //Aber das geht auch
    double Nullstelle1 = {1.5};

    std::cout << Nullstelle1 << std::endl;


    std::cout << "---------- Runde drei ----------" << std::endl;
    //Und hier zum ersten Mal die bevorzugte Schreibweise in modernen C++
    double Nullstelle3{1.5};
    double Viele_Nullstellen3[]{-2.0, -1.0, 3.0};

    std::cout << Nullstelle3 << std::endl;
    for (int i{0}; i < 3; ++i)
    {
        std::cout << Viele_Nullstellen3[i] << std::endl;
    }

    std::cout << "---------- Runde vier ----------" << std::endl;
    // Definition von Ursprung:
    Koordinate Ursprung{0.0, 0.0};
    // Definition von Schnittpunkt
    Koordinate Schnittpunkt{-1.0, 3.0};

    std::cout << "x: " << Ursprung.x     << "\ty: " << Ursprung.y     << std::endl;
    std::cout << "x: " << Schnittpunkt.x << "\ty: " << Schnittpunkt.y << std::endl;

    std::cout << "---------- Runde fünf ----------" << std::endl;

    Auto meins{"VW", "Caddy", 2018};

    std::cout << "Marke: " << meins.marke << "\tModell: " << meins.modell << "\tBaujahr: " << meins.baujahr << std::endl;

    std::cout << "---------- Runde sechs ----------" << std::endl;

    char storage[1000]{"Hallo Welt!!"}; //das wird jetzt gleich der Speicherplatz, den wir
                                        //MyString geben.

    MyString str1{12, &storage[0]}; //so jetzt hat er den Speicherplatz
    MyString str2{0, nullptr};  //nullptr ist der Zeiger ins Nirgendwo

    //str1 hat also richtig viel Speicherplatz: nämlich 1000bytes
    //str2 hat gar nix, sein Datenzeiger zeigt auf eine ungültige Adresse

    //Preisfage, wer ist laut sizeof größer?

    std::cout << sizeof(str1) << std::endl;
    std::cout << sizeof(str2) << std::endl;

    std::cout << str1.daten << std::endl;


    return 0;
}
