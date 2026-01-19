/*----------------------------------------------------------------------------
| BTS CIEL-IR Lycée La Fayette - 0770920G
+ ----------------------------------------------------------------------------
|
| Nom : main.cpp
|
| Projet : C to POO
| Sujet : ???
|
| Auteur : OULD CADI-RAVILY Sacha
| Version : 0.1
| Création : 08/010/2025
| Mise à jour : 10/10/2025
|
| Contraintes : ???
| Fabrication : ???
+------------------------------------------------------------------------- */

#include "tdate.h"

#include <iostream>
using namespace std;

int main(int argc, char** argv) {

    //Test TMonth
    for(TMonth m = JAN; m <= DEC; m = (TMonth)(m + 1)) cout << strMonth(m) << endl;

    //Test TDate
    TDate tdate0 = {11, NOV, 1918};
    TDate tdate1;

    setDate(&tdate1, 7, JUL, 2000);
    setDay(&tdate1, 14);
    setYear(&tdate1, 1789);

    cout << "Date 0 avec méthodes : " << getDay(&tdate0) << '/' << getMonth(&tdate0) << '/' << getYear(&tdate0) << endl;
    cout << "Date 1 avec méthodes : " << getDay(&tdate1) << '/' << getMonth(&tdate1) << '/' << getYear(&tdate1) << endl;

    TDate tdate2;
    unsigned j, m, a;
    cout << "jour, mois et année (séparés par espaces) ? : ";
    cin >> j >> m >> a;

    tdate2.day = j;
    tdate2.month = (TMonth)m;       // Accès direct aux champs de TDate, CÉPABIEN !
    tdate2.year = a;

    cout << "Date 2 (CÉPABIEN) : " << tdate2.day << '/' << strMonth(tdate2.month) << '/' << tdate2.year << endl;

    //Tdate vers vue "human readable"
    cout << "Date 1 courte : " << printDate(&tdate1) << endl;
    cout << "Date 1 longue : " << printLongDate(&tdate1) << endl;
    cout << "Date 2 courte : " << printDate(&tdate2) << endl;
    cout << "Date 2 longue : " << printLongDate(&tdate2) << endl;

    return 0;
    

}