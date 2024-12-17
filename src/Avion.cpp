#include "Avion.hpp"

// Default constructor
Avion::Avion()
    : nume("Necunoscut"), capacitate_locuri(0), viteza_maxima(0), proprietar("Necunoscut") {
    std::cout << "Constructor implicit apelat pentru avionul: " << nume << std::endl;
}

// General constructor
Avion::Avion(const std::string& nume, int capacitate_locuri, int viteza_maxima, const std::string& proprietar)
    : nume(nume), capacitate_locuri(capacitate_locuri), viteza_maxima(viteza_maxima), proprietar(proprietar) {
    std::cout << "Constructor general apelat pentru avionul: " << this->nume << std::endl;
}

// Move constructor (Item 11: Implementing move constructor to transfer resources)
Avion::Avion(Avion&& other) noexcept
    : nume(std::move(other.nume)), capacitate_locuri(other.capacitate_locuri),
      viteza_maxima(other.viteza_maxima), proprietar(std::move(other.proprietar)) {
    std::cout << "Move constructor apelat pentru avionul: " << nume << std::endl;
    /* Item 13: Resource Management - The move constructor transfers ownership of the resources
       (like the strings `nume` and `proprietar`) from `other` to the current object. This prevents
       unnecessary copies and ensures efficient resource management. It also leaves the `other` object
       in a valid but unspecified state, as it no longer owns these resources. */
}

// Move assignment operator (Item 10 and Item 11: Return *this for chained assignments; Item 11: Self-assignment check)
Avion& Avion::operator=(Avion&& other) noexcept {
    if (this == &other) {  // Item 11: Self-assignment check
        std::cout << "Self-assignment detectat pentru avionul: " << nume << std::endl;
        return *this;  // Return *this to avoid unnecessary operations in case of self-assignment
    }

    // Move resources from `other` to the current object
    nume = std::move(other.nume);
    capacitate_locuri = other.capacitate_locuri;
    viteza_maxima = other.viteza_maxima;
    proprietar = std::move(other.proprietar);

    std::cout << "Move assignment operator apelat pentru avionul: " << nume << std::endl;

    return *this;  // Item 10: Return *this to allow for chained assignments (e.g., a = b = c)
    /* Item 13: Resource Management - By using move semantics, we ensure that resources are moved,
       not copied. The state of `other` is left in a valid but unspecified state, while the current 
       object now owns its resources. This avoids deep copying and manages memory efficiently. */
}

// Destructor
Avion::~Avion() {
    std::cout << "Destructor apelat pentru avionul: " << nume << std::endl;
    /* Item 13: Resource Management - The destructor is used to clean up resources. 
       Since we don't have dynamic memory allocation in this example, it is responsible for
       cleaning up any potential resources when the object goes out of scope. */
}

// Method to display information about the airplane
void Avion::afiseazaInformatii() const {
    std::cout << "Avion: " << nume << ", Capacitate locuri: " << capacitate_locuri
              << ", Viteza maxima: " << viteza_maxima << " km/h, Proprietar: " << proprietar << std::endl;
}
