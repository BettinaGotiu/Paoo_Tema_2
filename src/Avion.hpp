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
    
    // Copy constructor
    Avion(const Avion& other);

    // Move constructor
    Avion(Avion&& other) noexcept;

    // Copy assignment operator
    Avion& operator=(const Avion& other);

    // Move assignment operator
    Avion& operator=(Avion&& other) noexcept;

    // Destructor
    ~Avion();

    void afiseazaInformatii() const;

private:
    std::string nume = " ";          
    int capacitate_locuri = 0;       
    int viteza_maxima = 0;           
    std::string proprietar = " ";    
};

#endif
