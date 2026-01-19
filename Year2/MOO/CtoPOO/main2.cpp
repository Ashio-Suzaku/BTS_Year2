/*----------------------------------------------------------------------------
| BTS CIEL-IR Lycée La Fayette - 0770920G
+ ----------------------------------------------------------------------------
|
| Nom : main2.cpp
|
| Projet : C to POO
| Sujet : ???
|
| Auteur : OULD CADI-RAVILY Sacha
| Version : 0.1
| Création : 26/09/2025
| Mise à jour : 26/09/2025
|
| Contraintes : ???
| Fabrication : ???
+------------------------------------------------------------------------- */

#include "tdate.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv ) {

    TDate tdate1 = { 14, JUL, 1789 };
    TDate tdate2;

    unsigned j, m, a;
    cout << "jour, mois et année (séparés par espaces) ? ";
    cin >> j >> m >> a;

    //tdate2.day = j;
    setDay(&tdate2, (unsigned)j);
    //tdate2.month = (TMonth)m;
    setMonth(&tdate2, (TMonth)m);
    //tdate2.year = a;
    setYear(&tdate2, (unsigned)a);

    cout << "date 1 : " << tdate1.day << '/';
    cout << tdate1.month << '/' << tdate1.year << endl;
    cout << "date 2 : " << tdate2.day << '/';
    cout << strMonth(tdate2.month) << '/' << tdate2.year << endl;

    return 0;

}