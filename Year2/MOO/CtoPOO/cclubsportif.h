/*----------------------------------------------------------------------------
| BTS CIEL-IR Lycée La Fayette - 0770920G
+ ----------------------------------------------------------------------------
|
| name : CClubSportif.h
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

#ifndef CCLUB_H
#define CCLUB_H

#include "cdate.h"
#include "tdate.h"
#include "tmonth.h"
#include "cmembre.h"
#include <string>
#include <iostream>

#define NMAX 101

class CClubSportif {

    private:
        CMembre* members[NMAX];
        std::string clubName;

    public:
        CClubSportif() {set("?");}
        CClubSportif(const std::string clubName) {

            set(clubName);

        }

        void setClubName(const std::string clubName);
        int getNbMembers();
        int getFreeSlot();

        bool addMember(const CMembre& memberu);

        void set(const std::string clubName);

        void list();

};

#endif