/*----------------------------------------------------------------------------
| BTS CIEL-IR Lycée La Fayette - 0770320G
+ ----------------------------------------------------------------------------
|
| Nom : equ2ndDeg.cpp
|
| Projet : N/A
|
| Auteur : OULD CADI-RAVILY Sacha
| Version : 2.0
| Création : 14/11/2025
| Mise à jour : 14/11/2025
|
| Contraintes : Aucune (C++ standard)
| Fabrication : g++ -W -o $HOME/bin/equ2ndDeg equ2ndDeg.cpp
+------------------------------------------------------------------------- */

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

void invalidValue(void);

int main(void) {

    double a, b, c, D;

    cout << "\n\x1b[4mCet outil ne prend en charge que les valeurs numériques réelles sous forme décimale ou entière.\n";

    cout << "\x1b[0mValeur de a ? : " << "\x1b[32;1m";
    cin >> a;
    if (cin.fail()) {invalidValue(); return -2;};

    cout << "\x1b[0mValeur de b ? : " << "\x1b[32;1m";
    cin >> b;
    if (cin.fail()) {invalidValue(); return -2;};

    cout << "\x1b[0mValeur de c ? : " << "\x1b[32;1m";
    cin >> c;
    if (cin.fail()) {invalidValue(); return -2;};

    D = pow(b, 2.0) - 4.0*a*c;

    if (a != 0) cout << "\x1b[0m\nValeur du discriminant \x1b[31mΔ\x1b[0m = \x1b[34m" << D << "\x1b[0m\n";

    if (a == 0) {

        cout << "\x1b[31;1mLes valeurs entrées ne constituent pas une équation du 2nd degré...\x1b[0m\n";
        
        return -1;

    } else if (D > 0) {

        double x1, x2;

        cout << "\n\x1b[31mΔ\x1b[0m > \x1b[34m0\x1b[0m donc l'équation admet 2 solution réelles : \n";

        x1 = (-(b) + sqrt(D)) / (2.0*a);

        x2 = (-(b) - sqrt(D)) / (2.0*a);

        cout << "  • \x1b[31mx1\x1b[0m = \x1b[34m"
             << x1
             << "\x1b[0m\n  • \x1b[31mx2\x1b[0m = \x1b[34m"
             << x2
             << "\x1b[0m\n";

    } else if (D == 0) {

        double x;

        cout << "\n\x1b[31mΔ\x1b[0m = \x1b[34m0\x1b[0m donc l'équation admet une seule solution réelle : \n";

        x = -(b / (2*a));

        cout << "  • \x1b[31mx\x1b[0m = \x1b[34m"
             << x
             << "\x1b[0m\n";

    } else if (D < 0) {

        double x1[2], x2[2];

        cout << "\n\x1b[31mΔ\x1b[0m < \x1b[34m0\x1b[0m donc l'équation admet 2 solution complexes : \n";

        x1[0] = (-b) / (2*a);
        x1[1] = (sqrt(abs(D))) / (2*a);

        x2[0] = x1[0];
        x2[1] = -((sqrt(abs(D))) / (2*a));

        cout.precision(2);
        cout << "  • \x1b[31mx1 \x1b[0m= \x1b[34m"
             << x1[0]
             << "\x1b[35m+"
             << x1[1]
             << "\x1b[0mi\n  • \x1b[31mx2\x1b[0m = \x1b[34m"
             << x2[0]
             << "\x1b[35m"
             << x2[1]
             << "\x1b[0mi\n";

    } else {

        invalidValue();

    }

    return 0;
    

}

void invalidValue(void) {

    cout << "\x1b[31;1mAu moins une valeur d'entrée est ivalide...\x1b[0m\n";

}