/*----------------------------------------------------------------------------
| BTS CIEL-IR Lycée La Fayette - 0770320G
+ ----------------------------------------------------------------------------
|
| Nom : rlc.c
|
| Projet : RLC
|
| Auteur : OULD CADI-RAVILY Sacha
| Version : 1.0
| Création : 07/11/2025
| Mise à jour : 07/11/2025
|
| Contraintes : Aucune (C standard)
| Fabrication : gcc -W -o $HOME/bin/rlc rlc.c -lm
+------------------------------------------------------------------------- */

#ifndef ARG
#define NumberOfArg          (argc - 1)
#define CharacterArg(N, I)   (argc > (N) ? *(argv[N] + (I)) : '\0')
#endif

#include <stdio.h>
#include <math.h>
#include <complex.h>

int main(int argc, char* argv[]) {

    char circuitType;
    double r, l, c, freq, w, L, C, Re, Im;
    int circuitTypeInArg = 0;

    if (NumberOfArg == 1) {
        
        if (CharacterArg(1, 1) == 's') {

            circuitType = 's';
            circuitTypeInArg = 1;

        } else if (CharacterArg(1, 1) == 'p') {

            circuitType = 'p';
            circuitTypeInArg = 1;

        }

    }

    if (!circuitTypeInArg) {

        printf("Circuit RLC: Série (s) ou Parallèle (p) ? : \x1b[32;1m");
        scanf(" %c", &circuitType);

    }

    if (circuitType != 's' && circuitType != 'p') {

        printf("\x1b[31;1m/!\\ Erreur : \x1b[0mType de montage invalide.\n");

        return 1;

    }

    printf("\x1b[0mR         (en Ω )  ? : \x1b[32;1m");
    scanf("%lf", &r);

    printf("\x1b[0mL         (en mH)  ? : \x1b[32;1m");
    scanf("%lf", &l);

    printf("\x1b[0mC         (en µF)  ? : \x1b[32;1m");
    scanf("%lf", &c);

    printf("\x1b[0mFréquence (en Hz)  ? : \x1b[32;1m");
    scanf("%lf", &freq);

    printf("\x1b[0m\n| Circuit RLC %s à %.2lf Hz\n", ( circuitType == 's' ? "série" : "parallèle" ), freq);
    printf("|\n| Avec R = %.2lf Ω\n|      L = %.2lf mH\n|      C = %.2lf µF\n", r, l, c);

    w = 2.0 * M_PI * freq;
    L     = l * 1e-3;    //Convertion mH --> H
    C     = c * 1e-6;    //Convertion µF --> F

    if (circuitType == 's') {

        Im = (w * L) - (1.0 / (w * C));

    } else {

        Re = (1/r) / (pow((1/r), 2) + pow((C*w)-(1/(L*w)), 2));
        Im = ((C*w) - (1/(L*w))) / (pow((1/r), 2) + pow((C*w)-(1/(L*w)), 2));

    }

    printf("|\n| Pulsation = %.2lf rad/s\n", w);
    printf("|\n| Module   G = %.2lf Ω   (%.2lf dB) \n", (circuitType == 's') ? sqrt(r*r + Im*Im) : sqrt(pow(Re, 2) + pow(Im, 2)), 20.0*log10((circuitType == 's') ? sqrt(r*r + Im*Im) : sqrt(pow(Re, 2) + pow(Im, 2))));
    printf("| Argument θ = %.2lf rad   (%.2lf °) \n", (circuitType == 's') ? atan2(Im, r) : -atan2(Im, Re), (circuitType == 's') ? atan2(Im, r) * (180.0 / M_PI) : -atan2(Im, Re) * (180.0 / M_PI));
    return 0;
}