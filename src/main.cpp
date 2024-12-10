#include <iostream>
#include "Avion.hpp"

// Functie de fabrica pentru crearea unui avion
Avion fabricaAvion(std::string nume, int capacitate_locuri, int viteza_maxima, std::string proprietar) {
    Avion nouAvion(nume, capacitate_locuri, viteza_maxima, proprietar);
    return std::move(nouAvion); 
    /* Returnam un obiect mutat folosind move constructor-ul
       pentru a evita copierea */
}

int main() {
    // Crearea primului avion folosind constructorul general
    Avion avion1("Diamond DA42", 4, 356, "EFA");
    avion1.afiseazaInformatii();

    // Crearea unui avion folosind move constructorul
    Avion avion2 = fabricaAvion("Cirrus SR20", 5, 287, "Lufthansa");
    avion2.afiseazaInformatii();

    /* Demonstratie pentru move assignment operator
    fabricaAvion(...) = Avion(...) funcționează pentru că operatorul de atribuire 
    returnează o referință către obiectul curent (*this).
    */
    Avion temp = fabricaAvion("Piper PA-28", 4, 230, "Air Club");
    temp = Avion("Cessna 172", 4, 225, "Private Owner");
    avion2 = std::move(temp); 

    avion2.afiseazaInformatii();

    return 0; 
}
