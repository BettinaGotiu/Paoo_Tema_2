#ifndef AVION_HPP
#define AVION_HPP

#include <string>
#include <iostream>

class Avion {
public:
    // Constructor implicit
    Avion();

    // Constructor general
    Avion(const std::string& nume, int capacitate_locuri, int viteza_maxima, const std::string& proprietar);

    // Move constructor
    Avion(Avion&& other) noexcept;

    // Move assignment operator
    Avion& operator=(Avion&& other) noexcept;

    // Destructor
    ~Avion();

    // Metoda de afisare a informatiilor
    void afiseazaInformatii() const;

    // Dezactivarea constructorului de copiere si operatorului de copiere
    Avion(const Avion& other) = delete;
    Avion& operator=(const Avion& other) = delete;

private:
    std::string nume = "Necunoscut";
    int capacitate_locuri = 0;
    int viteza_maxima = 0;
    std::string proprietar = "Necunoscut";
};

#endif // AVION_HPP
