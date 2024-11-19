#include <iostream>
#include "Avion.hpp"

// Functie de fabrica pentru crearea unui avion
Avion fabricaAvion(std::string nume, int capacitate_locuri, int viteza_maxima, std::string proprietar) {
    Avion nouAvion(nume, capacitate_locuri, viteza_maxima, proprietar);
    return std::move(nouAvion); 
    /* Folosim move constructor-ul pentru a returna obiectul
        nu va fi realizată o copie a obiectului, 
        ci proprietatea acestuia va fi transferată catre apelant
     */
}

int main() {
    //Avion folosind constructorul
    Avion avion1("Diamond DA42", 4, 356, "EFA");

    avion1.afiseazaInformatii();

    // Crearea unui nou avion folosind copy constructorul
    Avion avion2 = avion1;

    avion2.afiseazaInformatii();

    // Crearea unui nou avion folosind move constructorul
    Avion avion3 = fabricaAvion("Cirrus SR20", 5, 287, "Lufthansa");

    avion3.afiseazaInformatii();

    return 0; 
}
