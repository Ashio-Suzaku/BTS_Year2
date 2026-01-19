/*----------------------------------------------------------------------------
| BTS CIEL-IR Lycée La Fayette - 0770920G
+ ----------------------------------------------------------------------------
|
| Nom : cdate.cpp
|
| Projet : C to POO
| Sujet : ???
|
| Auteur : OULD CADI-RAVILY Sacha
| Version : 0.1
| Création : 10/10/2025
| Mise à jour : 10/10/2025
|
| Contraintes : ???
| Fabrication : ???
+------------------------------------------------------------------------- */

#include "cdate.h"

TMonth CDate::getMonth() const {

    return (TMonth)month;

}

unsigned CDate::getDay() const {

    return (unsigned)day;

}

unsigned CDate::getYear() const {

    return (unsigned)year;

}

void CDate::setMonth(TMonth month) {

    if (month < JAN) month = JAN;
    if (month > DEC) month = DEC;
    this->month = (TMonth)month;

}

void CDate::setDay(unsigned day) {

    if (day < 1) day = 1;

    if ((month <= JUL && month%2 == 1) || (month >= AOU && month%2 == 0)) {    //--- Mois 31 jours

        if (day > 31) day = 31;

    } else if (month == FEV) {    //------------------------------------------------ Février

        if ((year%100 != 0 && year%4 == 0) || (year%400 == 0)) {    //-------------- Année bisextlie (multiple 4 mais pas 100 ou multiple 400)

            if (day > 29) day = 29;

        } else {    //-------------------------------------------------------------- Année non bisextile

            if (day > 28) day = 28;

        }

    } else {    //------------------------------------------------------------------ Mois 30 jours

        if (day > 30) day = 30;

    }

    this->day = (unsigned)day;

}

void CDate::setYear(unsigned year) {

    this->year = (unsigned)year;

}

void CDate::set(unsigned day, TMonth month, unsigned year) {

    setDay(day);
    setMonth(month);
    setYear(year);

}

std::string CDate::print() const {

    std::ostringstream oss;

    oss << std::setfill('0');
    oss << std::setw(2) << day << '/';
    oss << std::setw(2) << month << '/';
    oss << std::setw(4) << year;

    return oss.str();

}

std::string CDate::printLong() const {

    std::ostringstream oss;

    oss << day << (day == 1 ? "er" : "") << ' ';
    oss << strMonth((TMonth)month) << ' ';
    oss << year;

    return oss.str();

}

std::ostream& operator << (std::ostream& s, const CDate& date) {

    s << date.print();

    return s;

}