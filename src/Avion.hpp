#ifndef AVION_HPP
#define AVION_HPP

#include <string>
#include <iostream>

// Clasa de baza Avion
class Avion {
public:
    // Constructor implicit
    Avion();

    // Constructor general
    Avion(const std::string& nume, int capacitate_locuri, int viteza_maxima, const std::string& proprietar);

    // Copy constructor
    Avion(const Avion& other); // Item 12: Copy constructor

    // Copy assignment operator
    Avion& operator=(const Avion& other); // Item 12: Copy assignment operator

    // Destructor
    virtual ~Avion();

    // Metoda de afisare a informatiilor
    virtual void afiseazaInformatii() const;

protected:
    void init(const Avion& other); // Functie auxiliara pentru copiere

private:
    std::string nume;
    int capacitate_locuri;
    int viteza_maxima;
    std::string proprietar;
};

// Clasa derivata AvionSpecial
class AvionSpecial : public Avion {
public:
    // Constructor implicit
    AvionSpecial();

    // Constructor general
    AvionSpecial(const std::string& nume, int capacitate_locuri, int viteza_maxima, const std::string& proprietar,
                 int armament);

    // Copy constructor
    AvionSpecial(const AvionSpecial& other);

    // Copy assignment operator
    AvionSpecial& operator=(const AvionSpecial& other);

    // Destructor
    ~AvionSpecial();

    // Metoda de afisare
    void afiseazaInformatii() const override;

private:
    int armament; // Numarul de sisteme de armament
};

#endif // AVION_HPP
