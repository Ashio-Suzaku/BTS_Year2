/*----------------------------------------------------------------------------
| BTS CIEL-IR Lycée La Fayette - 0770920G
+ ----------------------------------------------------------------------------
|
| Nom : main1.cpp
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

#include "tmonth.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv ) {

    for (TMonth m = JAN; m <= DEC; m = (TMonth)(m + 1)) {

        //cout << strMonth(m) << endl;
        printf("%d %s : %d\n", m, strMonth(m), (m%2));    //Ici cette ligne remplace la précédente (mise en commentaire) dans le but de donner la liste des mois
                                                          //avec quelques informations supplémentaires utilisées plus tard dans cdate.cpp

    }

    return 0;

}
