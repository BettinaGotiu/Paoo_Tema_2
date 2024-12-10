#include "Avion.hpp"

// Constructor implicit
Avion::Avion()
    : nume("Necunoscut"), capacitate_locuri(0), viteza_maxima(0), proprietar("Necunoscut") {
    std::cout << "Constructor implicit apelat pentru avionul: " << nume << std::endl;
}

// Constructor general
Avion::Avion(const std::string& nume, int capacitate_locuri, int viteza_maxima, const std::string& proprietar)
    : nume(nume), capacitate_locuri(capacitate_locuri), viteza_maxima(viteza_maxima), proprietar(proprietar) {
    std::cout << "Constructor general apelat pentru avionul: " << this->nume << std::endl;
}

// Move constructor
Avion::Avion(Avion&& other) noexcept
    : nume(std::move(other.nume)), capacitate_locuri(other.capacitate_locuri),
      viteza_maxima(other.viteza_maxima), proprietar(std::move(other.proprietar)) {
    std::cout << "Move constructor apelat pentru avionul: " << nume << std::endl;
}

// Move assignment operator
Avion& Avion::operator=(Avion&& other) noexcept {

    // Mutam resursele din `other` in obiectul curent
    nume = std::move(other.nume);
    capacitate_locuri = other.capacitate_locuri;
    viteza_maxima = other.viteza_maxima;
    proprietar = std::move(other.proprietar);

    std::cout << "Move assignment operator apelat pentru avionul: " << nume << std::endl;

    return *this; // Returnam o referinta la obiectul curent
    /*asigura ca putem lantui operatorul =, astfel incat atribuirea multipla devine posibila si corecta.*/

}

// Destructor
Avion::~Avion() {
    std::cout << "Destructor apelat pentru avionul: " << nume << std::endl;
}

// Metoda de afisare a informatiilor
void Avion::afiseazaInformatii() const {
    std::cout << "Avion: " << nume << ", Capacitate locuri: " << capacitate_locuri
              << ", Viteza maxima: " << viteza_maxima << " km/h, Proprietar: " << proprietar << std::endl;
}
