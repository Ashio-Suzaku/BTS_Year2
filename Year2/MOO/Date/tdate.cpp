/*----------------------------------------------------------------------------
| BTS CIEL-IR Lycée La Fayette - 0770920G
+ ----------------------------------------------------------------------------
|
| Nom : tdate.cpp
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

#include <stdio.h>
#include "tdate.h"

unsigned getDay(TDate* date) {return date->day;}
TMonth getMonth(TDate* date) {return date->month;}
unsigned getYear(TDate* date) {return date->year;}

void setDay(TDate* date, unsigned day) {

    if (day < 1) day = 1;

    if ((date->month <= JUL && date->month%2 == 1) || (date->month >= AOU && date->month%2 == 0)) {    //--- Condition pour les mois de 31 jours

        if (day > 31) day = 31;

    } else if (date->month == FEV) {    //------------------------------------------------------------------ Condition pour le cas particulier de février

        if ((date->year%100 != 0 && date->year%4 == 0) || (date->year%400 == 0)) {    //-------------------- Vérification si l'année donnée est bisextlie (multiple 4 mais pas 100 ou multiple 400) ou non

            if (day > 29) day = 29;

        } else {    //-------------------------------------------------------------------------------------- Si l'année n'est pas bisextile

            if (day > 28) day = 28;

        }

    } else {    //------------------------------------------------------------------------------------------ Condition pour les mois de 30 jours

        if (day > 30) day = 30;

    }

    date->day = day;

}

void setMonth(TDate* date, TMonth month) {
        
    if (month < JAN) month = JAN;

    if (month > DEC) month = DEC;

    date->month = month;

}

void setYear(TDate* date, unsigned year) {

    date->year = year;

}

void setDate(TDate* date, unsigned day, TMonth month, unsigned year) {

    setDay(date, day);
    setMonth(date, month);
    setYear(date, year);

}

char* printDate(TDate* date) {

    static char s[20];
    sprintf(s, "%02d/%02d/%04d", date->day, ((int)date->month >= 1 && (int)date->month <= 12) ? (int)date->month : 0, date->year);

    return s;

}

char* printLongDate(TDate* date) {

    static char s[20];
    sprintf(s, "%d%s %s %04d", date->day, (date->day == 1 ? "er" : ""), ((int)date->month >= 1 && (int)date->month <= 12) ? strMonth(date->month) : "invalide", date->year);

    return s;

}
