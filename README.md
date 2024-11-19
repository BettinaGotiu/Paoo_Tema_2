# Paoo_Tema_2

*Item 4* 
Trebuie să ne asigurăm că obiectele sunt inițializate înainte de a le folosi. C++ nu face asta întotdeauna singur, așa că trebioe inițializate manual. În constructor folosim lista de inițializare  în loc să atribuim valorile în corpul constructorului. De asemenea, pentru a evita problemele de ordine în inițializare, înlocuim obiectele statice globale cu cele locale.

*Item 5* 
C++ creează automat anumite funcții  cum ar fi destructorul, constructorul de copiere, constructorul de mutare și operatorii de copiere și mutare.

*Item 6*   
Dacă nu vrem ca compilatorul să genereze automat anumite funcții (cum ar fi constructorul de copiere), le putem declara noi și le putem face private, pentru a preveni folosirea lor din alte părți ale codului.