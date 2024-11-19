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

    void afiseazaInformatii() const;

private:
    std::string nume = " ";          // Initializare implicita
    int capacitate_locuri = 0;       // Initializare implicita
    int viteza_maxima = 0;           // Initializare implicita
    std::string proprietar = " ";    // Initializare implicita

    // Declararea constructorului de copiere si operatorului de atribuire de copiere -> private 
    Avion(const Avion& other);  // Declarare constructor de copiere
    Avion& operator=(const Avion& other); // Declarare operator de atribuire de copiere 
};

#endif
