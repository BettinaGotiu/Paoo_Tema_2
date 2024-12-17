#include <iostream>
#include "Avion.hpp"

// Factory function that creates an Avion object and returns it using move semantics
Avion fabricaAvion(std::string nume, int capacitate_locuri, int viteza_maxima, std::string proprietar) {
    Avion nouAvion(nume, capacitate_locuri, viteza_maxima, proprietar);
    // Return an object using move constructor to avoid copying
    return std::move(nouAvion); 
    /* Item 13: Resource Management - By using std::move(), we ensure that the returned object
       is not copied but instead transferred to the caller using move semantics, 
       which avoids unnecessary resource duplication. */
}

int main() {
    // Create the first airplane using the general constructor
    Avion avion1("Diamond DA42", 4, 356, "EFA");
    avion1.afiseazaInformatii();

    // Create a second airplane using move constructor via fabricaAvion function
    Avion avion2 = fabricaAvion("Cirrus SR20", 5, 287, "Lufthansa");
    avion2.afiseazaInformatii();

    // Demonstration for self-assignment (Item 11: Self-assignment check)
    // The move assignment operator ensures that we handle self-assignment correctly
    avion2 = std::move(avion2);  // Self-assignment will trigger the check in the move assignment operator

    // Demonstrating move assignment operator (Item 10: Return *this for chained assignments)
    Avion temp = fabricaAvion("Piper PA-28", 4, 230, "Air Club");
    temp = Avion("Cessna 172", 4, 225, "Private Owner");  // Move assignment of a temporary object
    avion2 = std::move(temp);  // Move the temporary object to avion2

    avion2.afiseazaInformatii();

    return 0; 
}
