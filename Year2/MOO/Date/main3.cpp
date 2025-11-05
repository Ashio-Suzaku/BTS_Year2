/*----------------------------------------------------------------------------
| BTS CIEL-IR Lycée La Fayette - 0770920G
+ ----------------------------------------------------------------------------
|
| Nom : main3.cpp
|
| Projet : C to POO
| Sujet : ???
|
| Auteur : OULD CADI-RAVILY Sacha
| Version : 0.1
| Création : 10/010/2025
| Mise à jour : 10/10/2025
|
| Contraintes : ???
| Fabrication : ???
+------------------------------------------------------------------------- */

#include "cdate.h"
#include <iostream>

int main(int argc, char** argv) {

    CDate cdate1;
    cdate1.set(14, JUL, 1789);

    CDate cdate2;
    cdate2.set(11, SEP, 2001);

    CDate cdate3;
    cdate3.set(1, AVR, 2011);

//Affichage direct
    std::cout << "Date 1                   :     " << cdate1.getDay() << '/' << cdate1.getMonth() << '/' << cdate1.getYear() << std::endl;
    std::cout << "Date 2 (avant modif)     :     " << cdate2.getDay() << '/' << cdate2.getMonth() << '/' << cdate2.getYear() << std::endl;
    cdate2.setMonth(OCT);
    cdate2.setYear(2011);
    std::cout << "Date 2 (après modif)     :     " << cdate2.getDay() << '/' << cdate2.getMonth() << '/' << cdate2.getYear() << std::endl;

//Affichage simple (print)
    std::cout << "Date 1 (méthode print())     : " << cdate1.print() << std::endl;
    std::cout << "Date 2 (méthode print())     : " << cdate2.print() << std::endl;
    std::cout << "Date 3 (méthode print())     : " << cdate3.print() << std::endl;

//Affichage long (printLong)
    std::cout << "Date 1 (méthode printLong()) : " << cdate1.printLong() << std::endl;
    std::cout << "Date 2 (méthode printLong()) : " << cdate2.printLong() << std::endl;
    std::cout << "Date 3 (méthode printLong()) : " << cdate3.printLong() << std::endl;

//Affichage simple (osstream)
    std::cout << "Date 1 (osstream&)           : " << cdate1 << std::endl;

    return 0;

}
