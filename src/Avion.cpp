#include "avion.hpp"

// Clasa Avion

// Constructor implicit
Avion::Avion()
    : nume("Necunoscut"), capacitate_locuri(0), viteza_maxima(0), proprietar("Necunoscut") {
    std::cout << "Constructor implicit Avion apelat\n";
}

// Constructor general
Avion::Avion(const std::string& nume, int capacitate_locuri, int viteza_maxima, const std::string& proprietar)
    : nume(nume), capacitate_locuri(capacitate_locuri), viteza_maxima(viteza_maxima), proprietar(proprietar) {
    std::cout << "Constructor general Avion apelat\n";
}

// Copy constructor
Avion::Avion(const Avion& other) {
    init(other); // Apelam functia auxiliara
    std::cout << "Copy constructor Avion apelat\n";
}

// Copy assignment operator
Avion& Avion::operator=(const Avion& other) {
    if (this == &other) {
        std::cout << "Self-assignment detectat Avion\n";
        return *this;
    }

    init(other); // Copierea datelor
    std::cout << "Copy assignment operator Avion apelat\n";
    return *this;
}

// Destructor
Avion::~Avion() {
    std::cout << "Destructor Avion apelat\n";
}

// Functie auxiliara pentru copiere
void Avion::init(const Avion& other) {
    nume = other.nume;
    capacitate_locuri = other.capacitate_locuri;
    viteza_maxima = other.viteza_maxima;
    proprietar = other.proprietar;
}

// Metoda de afisare
void Avion::afiseazaInformatii() const {
    std::cout << "Avion: " << nume << ", Capacitate: " << capacitate_locuri
              << ", Viteza: " << viteza_maxima << " km/h, Proprietar: " << proprietar << "\n";
}

// Clasa AvionSpecial 
// Constructor implicit
AvionSpecial::AvionSpecial()
    : Avion(), armament(0) {
    std::cout << "Constructor implicit AvionSpecial apelat\n";
}

// Constructor general
AvionSpecial::AvionSpecial(const std::string& nume, int capacitate_locuri, int viteza_maxima,
                           const std::string& proprietar, int armament)
    : Avion(nume, capacitate_locuri, viteza_maxima, proprietar), armament(armament) {
    std::cout << "Constructor general AvionSpecial apelat\n";
}

// Copy constructor
AvionSpecial::AvionSpecial(const AvionSpecial& other)
    : Avion(other), armament(other.armament) { // Copiem partea clasei de baza
    std::cout << "Copy constructor AvionSpecial apelat\n";
}

// Copy assignment operator
AvionSpecial& AvionSpecial::operator=(const AvionSpecial& other) {
    if (this == &other) {
        std::cout << "Self-assignment detectat AvionSpecial\n";
        return *this;
    }

    Avion::operator=(other); // Copierea partii din clasa de baza
    armament = other.armament; // Copierea membrului local
    std::cout << "Copy assignment operator AvionSpecial apelat\n";
    return *this;
}

// Destructor
AvionSpecial::~AvionSpecial() {
    std::cout << "Destructor AvionSpecial apelat\n";
}

// Metoda de afisare
void AvionSpecial::afiseazaInformatii() const {
    Avion::afiseazaInformatii();
    std::cout << "Armament: " << armament << "\n";
}
