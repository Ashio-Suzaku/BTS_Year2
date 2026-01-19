/*----------------------------------------------------------------------------
| BTS CIEL-IR Lycée La Fayette - 0770920G
+ ----------------------------------------------------------------------------
|
| name : cdate.h
|
| Projet : C to POO
| Sujet : ???
|
| Auteur : OULD CADI-RAVILY Sacha
| Version : 0.1
| Création : 21/11/2025
| Mise à jour : 21/11/2025
|
| Contraintes : ???
| Fabrication : ???
+------------------------------------------------------------------------- */

#ifndef CDATE_H
#define CDATE_H

#include "tmonth.h"
#include <sstream>
#include <iomanip>
#include <string>
#include <ostream>

class CDate {

    private:
        unsigned day;
        TMonth month;
        unsigned year;

    public:
        CDate() {set(1, JAN, 1900);}

        CDate(unsigned day, TMonth month, unsigned year) {

            set(day, month, year);

        }

        TMonth getMonth() const;
        unsigned getDay() const;
        unsigned getYear() const;

        void setMonth(TMonth month);
        void setDay(unsigned day);
        void setYear(unsigned year);

        void set(unsigned day, TMonth month, unsigned year);

        std::string print() const;
        std::string printLong() const;

};

std::ostream& operator << (std::ostream& s, const CDate& date);

#endif
