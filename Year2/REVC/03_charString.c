/* ----------------------------------------------------------------------------
| BTS CIEL-IR Lycée La Fayette - 0770920G
+ ----------------------------------------------------------------------------
|
| Nom : 03_charString.c
|
| Projet : Chaîne de caractères
| Sujet : N/A
|
| Auteur : OULD CADI-RAVILY Sacha
| Version : 1.1
| Création : 3/09/2025
| Mise à jour : 12/09/2025
|
| Contraintes : aucune ( C Standard )
| Fabrication : gcc -Wall -o /home/Documents/c_language/Year2/REVC/03_charString 03_charString.c
+ ------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "argv.h"

char* suite(int lg, char ch);

int main(int argc, char* argv[]) {
    
    if (argc < 3) return BadNumberOfArg;
    printf("%s\n", suiteMalloc(atoi(argv[1]), *argv[2]));
    putchar('\n');
    printf("%s\n", suite(atoi(argv[1]), *argv[2]));
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