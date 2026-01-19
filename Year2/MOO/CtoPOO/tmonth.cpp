/*----------------------------------------------------------------------------
| BTS CIEL-IR Lycée La Fayette - 0770920G
+ ----------------------------------------------------------------------------
|
| Nom : tmonth.cpp
|
| Projet : C to POO
| Sujet : ???
|
| Auteur : OULD CADI-RAVILY Sacha
| Version : 0.1
| Création : 26/09/2025
| Mise à jour : 10/10/2025
|
| Contraintes : ???
| Fabrication : ???
+------------------------------------------------------------------------- */

#include "tmonth.h"

char mm[12][10] = {"janvier", "février", "mars", "avril", "mai", "juin", "juillet", "août", "septembre", "octobre", "novembre", "décembre"};

const char* strMonth(TMonth month) {

    // TODO : l’argument month doit être compris entre 1 et 12
    // TODO : retourner la chaîne adéquate…
    if (0 < month || month < 12) return mm[month-1];

}