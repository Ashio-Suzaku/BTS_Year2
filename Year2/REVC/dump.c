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
| Version : 3.2
| Création : 12/09/2025
| Mise à jour : 24/09/2025
|
| Contraintes : aucune (C Standard)
| Fabrication : gcc -Wall -o dump ~/Documents/c_language/Year2/REVC/dump.c
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
void header (char ligne[LINE], long cpt);

int main (int argc, char* argv[]) {

    FILE* flux;
    char car;

    long cpt = 0;
    char ligne[LINE];

    int withPages = 0;

    if (NumberOfArg == 0) {

        puts("Using standard input.\n-help as command argmuent displays help menu.");
        flux = stdin;

    } else if (NumberOfArg == 1) {

        if (CharacterArg(1, 1) == 'p') {
        
            puts("Using standard input.\n-help as command argmuent displays help menu.");
            withPages = 1;
            flux = stdin;
            

        } else if (CharacterArg(1, 1) == 'h') {

            printf("\nFormat : dump [ARG]* [FILE]\n* : Non mandatory field.\n");
            printf("\nAvailable arguments :\n-h, -help : Displays this help menu.\n-p, -page : Displays export as separated pages.\n\n");
            return -3;

        } else {

            flux = fopen(*(argv + 1), "rb");

        }

    } else if (NumberOfArg == 2) {
        
        if (CharacterArg(1, 1) == 'p') {
            
            withPages = 1;
            flux = fopen(*(argv + 2), "rb");
            
        } else {

            return InvalidArg;

        }

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
        
        if ((!(cpt % (NCOD*NPAG))) && ((withPages == 1) || (cpt == 0))) {

            header(ligne, cpt);

        }
        
        memmove(ligne+ICOD+3*(cpt%NCOD), itohex(car, 2), 2);

        if (isprint(car)) {
            
            ligne[IASC+(cpt%NCOD)] = car;
            
        } else {
            
            ligne[IASC+(cpt%NCOD)] = '.';

        }

        cpt++;

        if (!(cpt % NCOD)) {

            printf("\x1b[37m\x1b[1m\x1b[45m");
            for (int a = 0; a < OFFS; a++) {

                printf("%c", ligne[a]);

            }
            printf("\x1b[0m");

            printf("%s", ligne+OFFS);

            strcpy(ligne, suite(LINE - 1, 32));
            memmove(ligne, itohex(cpt, OFFS), OFFS);

            putchar('\n');

        }

    }

    if (cpt % NCOD) {

        printf("\x1b[37m\x1b[1m\x1b[45m");
        for (int a = 0; a < OFFS; a++) {

            printf("%c", ligne[a]);

        }
        printf("\x1b[0m");

        printf("%s\n", ligne+OFFS);

    }


    if (!(NumberOfArg == 1)) fclose(flux);
    
    return 0;

}

void header (char ligne[LINE], long cpt) {

    putchar('\n');
    strcpy(ligne, suite(LINE - 1, 32));
    
    for (int j = 0; j < 16; j++) {
        
        memmove(ligne+ICOD+3*j+1, itohex(j, 1), 1);

    }
    memmove(ligne+IASC, "Texte décodé", 14);
    printf("\x1b[37m\x1b[1m\x1b[45m%s\x1b[0m\n", ligne);

    strcpy(ligne, suite(LINE - 1, 32));
    memmove(ligne, itohex(cpt, OFFS), OFFS);

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