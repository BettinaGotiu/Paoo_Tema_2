#ifndef AVION_HPP
#define AVION_HPP

#include <string>
#include <iostream>

class Avion {
public:
    // Constructor 
    Avion(const std::string& nume, int capacitate_locuri, int viteza_maxima, const std::string& proprietar);
    
    // Copy constructor
    Avion(const Avion& other);

    // Move constructor
    Avion(Avion&& other) noexcept;

    // Destructor
    ~Avion();

    void afiseazaInformatii() const;

private:
    std::string nume = " ";          // Initializare implicita
    int capacitate_locuri = 0;         // Initializare implicita
    int viteza_maxima = 0;             // Initializare implicita
    std::string proprietar = " ";    // Initializare implicita
};

#endif 
