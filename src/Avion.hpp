#ifndef AVION_HPP
#define AVION_HPP

#include <string>
#include <iostream>
#include <mutex>

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

    // Disabling copy constructor and copy assignment operator (Item 14: Disabling copying)
    Avion(const Avion& other) = delete;  // Item 14: Disable the copy constructor to prevent copying
    Avion& operator=(const Avion& other) = delete;  // Item 14: Disable the copy assignment operator

private:
    std::string nume = "Necunoscut";
    int capacitate_locuri = 0;
    int viteza_maxima = 0;
    std::string proprietar = "Necunoscut";

    // Mutex to protect shared resource
    mutable std::mutex mtx;
    
    // Method to lock and display the information thread-safely
    void afiseazaInformatiiSigur() const {
        std::lock_guard<std::mutex> lock(mtx);  // Lock the mutex to ensure thread-safe access
        afiseazaInformatii();  // Call the original method
    }
};

#endif // AVION_HPP
