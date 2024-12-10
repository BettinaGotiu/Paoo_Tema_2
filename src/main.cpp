#include <iostream>
#include "avion.hpp"

int main() {
    // Demonstratie Avion
    Avion avion1("Boeing 747", 660, 900, "Qatar Airways");
    Avion avion2 = avion1; // Copy constructor
    avion2.afiseazaInformatii();

    Avion avion3;
    avion3 = avion1; // Copy assignment operator
    avion3.afiseazaInformatii();

    std::cout << "\n";

    // Demonstratie AvionSpecial
    AvionSpecial special1("F-16", 1, 2400, "US Air Force", 8);
    AvionSpecial special2 = special1; // Copy constructor
    special2.afiseazaInformatii();

    AvionSpecial special3;
    special3 = special1; // Copy assignment operator
    special3.afiseazaInformatii();

    return 0;
}
