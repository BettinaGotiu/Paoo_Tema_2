#ifndef AVION_HPP
#define AVION_HPP

#include <string>
#include <iostream>

class Avion {
public:
    // Default constructor
    Avion();

    // General constructor
    Avion(const std::string& nume, int capacitate_locuri, int viteza_maxima, const std::string& proprietar);

    // Move constructor (Item 11: Implemented move constructor)
    Avion(Avion&& other) noexcept;

    // Move assignment operator (Item 10: Return *this for chained assignments; Item 11: Self-assignment check)
    Avion& operator=(Avion&& other) noexcept;

    // Destructor
    ~Avion();

    // Method to display information
    void afiseazaInformatii() const;

    // Disabling copy constructor and copy assignment operator
    Avion(const Avion& other) = delete;
    Avion& operator=(const Avion& other) = delete;

private:
    std::string nume = "Necunoscut";
    int capacitate_locuri = 0;
    int viteza_maxima = 0;
    std::string proprietar = "Necunoscut";
};

#endif // AVION_HPP
