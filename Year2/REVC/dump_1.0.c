/*----------------------------------------------------------------------------
| BTS CIEL-IR Lycée La Fayette - 0770920G
+ ----------------------------------------------------------------------------
|
| Nom : dump.c
|
| Projet : Dump
| Sujet : Afficher le contenu héxadécimal d'un fichier
|
| Auteur : OULD CADI-RAVILY Sacha
| Version : 1.0
| Création : 12/09/2025
| Mise à jour : 19/09/2025
|
| Contraintes : aucune (C Standard)
| Fabrication : gcc -Wall -o dump /home/Documents/c_language/Year2/REVC/dump.c
+------------------------------------------------------------------------- */

#include "argv.h"
#include <ctype.h>

#define NCOD    16
#define ICOD    10
#define OFFS    6
#define IASC    (ICOD + 3*NCOD + 4)
#define LINE    (IASC + NCOD + 1)
#define NPAG    16

char* suite (int lg, char ch);
char* itohex (long val, int lg);

int main (int argc, char* argv[]) {

    FILE* flux;
    char car;

    long cpt = 0;
    char ligne[LINE];

    //flux = fopen(*(argv + 1), "rb");
    //printf("args : %d", NumberOfArg);

    if (NumberOfArg == 1) {

        flux = fopen(*(argv + 1), "rb");

    } else if (NumberOfArg == 0) {

        flux = stdin;

    } else {

        return BadNumberOfArg;

    }

    strcpy(ligne, suite(LINE - 1, 32));
    memmove(ligne, itohex(cpt, OFFS), OFFS);
    
    if (flux == NULL) {

        printf("%s : ", argv[0]);
        puts("Fichier non trouvé");

        return -1;

    }

    while (fread(&car, 1, 1, flux)) {

        if (!(cpt % (NCOD*NPAG))) {       
            
            putchar('\n');
            strcpy(ligne, suite(LINE - 1, 32));
            
            for (int j = 0; j < 16; j++) {
                
                memmove(ligne+ICOD+3*j+1, itohex(j, 1), 1);

            }
            puts(ligne);

            strcpy(ligne, suite(LINE - 1, 32));
            memmove(ligne, itohex(cpt, OFFS), OFFS);

        }
        
        memmove(ligne+ICOD+3*(cpt%NCOD), itohex(car, 2), 2);

        if (isprint(car)) {
            
            ligne[IASC+(cpt%NCOD)] = car;
            
        } else {
            
            ligne[IASC+(cpt%NCOD)] = '.';

        }

        cpt++;

        if (!(cpt % NCOD)) {

            puts(ligne);

            strcpy(ligne, suite(LINE - 1, 32));
            memmove(ligne, itohex(cpt, OFFS), OFFS);

        }

    }

    if (cpt % NCOD) puts(ligne);

    if (!(NumberOfArg == 1)) fclose(flux);
    
    return 0;

}

char* suite(int lg, char ch) {
    
    static char str[80];
    int len = lg;
    
    if (len > 79) len = 79;
    
    for (int i = 0; i < len; i++) {
    
        str[i] = ch;
    
    }
    
    str[len] = '\0';
    
    return str;

}

char* itohex(long val, int lg) {

    static char hexValue[9] = "00000000";

    if (lg > 8) lg = 8;
    if (lg < 1) lg = 1;

    int i;
    for (i = 7; i >= 0; i--) {

        ((val & 0xF) > 9) ? (hexValue[i] = (val & 0xF)+55) : (hexValue[i] = (val & 0xF)+48);
        val >>= 4;
        
    }

    return hexValue + 8 - lg;

}