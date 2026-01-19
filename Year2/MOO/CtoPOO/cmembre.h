/*----------------------------------------------------------------------------
| BTS CIEL-IR Lycée La Fayette - 0770920G
+ ----------------------------------------------------------------------------
|
| name : cmembre.h
|
| Projet : C to POO
| Sujet : ???
|
| Auteur : OULD CADI-RAVILY Sacha
| Version : 0.1
| Création : 19/11/2025
| Mise à jour : 19/11/2025
|
| Contraintes : ???
| Fabrication : ???
+------------------------------------------------------------------------- */

#ifndef CMEMBRE_H
#define CMEMBRE_H

#include "cdate.h"
#include "tdate.h"
#include "tmonth.h"
#include <string>
#include <iostream>

class CMembre {

    private:
        std::string name;
        std::string firstName;
        CDate birthDate;

    public:
        CMembre() {set("?", "?", CDate(1, JAN, 1900));}
        CMembre(const std::string name, const std::string firstName, const CDate birthDate) {

            set(name, firstName, birthDate);

        }

        std::string getName() const;
        std::string getFirstName() const;
        CDate getBirthDate() const;

        void setName(const std::string name);
        void setFirstName(const std::string firstName);
        void setBirthDate(const CDate birthDate);

        void set(const std::string name, const std::string firstName, const CDate birthDate);
        void setMember(const CMembre& member);

        std::string print() const;

};

#endif