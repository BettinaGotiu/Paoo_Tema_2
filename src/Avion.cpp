#include "Avion.hpp"

// Constructor implicit
Avion::Avion()
    : nume("Necunoscut"), capacitate_locuri(0), viteza_maxima(0), proprietar("Necunoscut") {
    std::cout << "Constructor implicit apelat pentru avionul: " << nume << std::endl;
}

// Constructor general folosind lista de initalizare
Avion::Avion(const std::string& nume, int capacitate_locuri, int viteza_maxima, const std::string& proprietar)
    : nume(nume), capacitate_locuri(capacitate_locuri), viteza_maxima(viteza_maxima), proprietar(proprietar) {
    std::cout << "Constructorul a fost apelat pentru avionul: " << this->nume << std::endl;
}

// Copy constructor (Comentat pentru Item 5)
// Avion::Avion(const Avion& other)
//     : nume(other.nume), capacitate_locuri(other.capacitate_locuri),
//       viteza_maxima(other.viteza_maxima), proprietar(other.proprietar) {
//     std::cout << "Copy constructorul a fost apelat pentru avionul: " << nume << std::endl;
// }

// Move constructor
Avion::Avion(Avion&& other) noexcept
    : nume(std::move(other.nume)), capacitate_locuri(other.capacitate_locuri),
      viteza_maxima(other.viteza_maxima), proprietar(std::move(other.proprietar)) {
    std::cout << "Move constructor a fost apelat pentru avionul: " << nume << std::endl;
}

// Copy assignment operator (Comentat pentru Item 5)
// Avion& Avion::operator=(const Avion& other) {
//     if (this == &other) return *this; // Protecție împotriva auto-atribuiri
//     nume = other.nume;
//     capacitate_locuri = other.capacitate_locuri;
//     viteza_maxima = other.viteza_maxima;
//     proprietar = other.proprietar;
//     std::cout << "Copy assignment operator apelat pentru avionul: " << nume << std::endl;
//     return *this;
// }

// Move assignment operator
Avion& Avion::operator=(Avion&& other) noexcept {
    if (this == &other) return *this; // Protecție împotriva auto-atribuiri
    nume = std::move(other.nume);
    capacitate_locuri = other.capacitate_locuri;
    viteza_maxima = other.viteza_maxima;
    proprietar = std::move(other.proprietar);
    std::cout << "Move assignment operator apelat pentru avionul: " << nume << std::endl;
    return *this;
}

// Destructor
Avion::~Avion() {
    std::cout << "Destructorul a fost apelat pentru avionul: " << nume << std::endl;
}

// Afisare informatii
void Avion::afiseazaInformatii() const {
    std::cout << "Avion: " << nume << ", Capacitate locuri: " << capacitate_locuri
              << ", Viteza maxima: " << viteza_maxima << " km/h, Proprietar: " << proprietar << std::endl;
}
