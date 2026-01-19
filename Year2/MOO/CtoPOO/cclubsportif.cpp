/*----------------------------------------------------------------------------
| BTS CIEL-IR Lycée La Fayette - 0770920G
+ ----------------------------------------------------------------------------
|
| name : CClubSportif.cpp
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

#include "cclubsportif.h"
#include <iostream>

void CClubSportif::setClubName(const std::string clubName) {

    this->clubName = clubName;

}

int CClubSportif::getNbMembers() {

    int nb = 0;

    for (int i = 0; i < NMAX; ++i) {

        if (members[i] != 0) {

            nb++;

        } else {

            continue;

        }

    }

    return nb;

}

int CClubSportif::getFreeSlot() {

    for (int i = 0; i < NMAX; ++i) {

        if (members[i] == 0) {

            return i;

        } else {

            continue;

        }

    }

    return -1;

}

bool CClubSportif::addMember(const CMembre& member) {

    puts("4");
    int slot = getFreeSlot();
    puts("5");
    if (slot == -1) {
        
        std::cout << "Aucun emplacement libre..." << std::endl;
        puts("false");
        return false;

    } else {

        members[slot]->set(member.getName(), member.getFirstName(), member.getBirthDate());
        puts("true");
        return true;

    }

}


void CClubSportif::set(const std::string clubName) {

    setClubName(clubName);

    for (int i = 0; i < NMAX; ++i) members[i] = 0;

}

void CClubSportif::list() {
    puts("enter");
    for (int i = 0; i < NMAX; ++i) {
        //puts("enter2");
        if (members[i] != 0) {
            puts("print");
            std::cout << members[i]->print() << std::endl;

        } else {
            //puts("nah");
            continue;

        }

    }

}
