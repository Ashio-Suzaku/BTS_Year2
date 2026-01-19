/*----------------------------------------------------------------------------
| BTS CIEL-IR Lycée La Fayette - 0770920G
+ ----------------------------------------------------------------------------
|
| name : cmembres.cpp
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

#include "cmembre.h"
#include <iostream>

std::string CMembre::getName() const {

    return (std::string)name;

}

std::string CMembre::getFirstName() const {

    return (std::string)firstName;

}

CDate CMembre::getBirthDate() const {

    return (CDate)birthDate;

}

void CMembre::setName(const std::string name) {

    this->name = (std::string)name;

}

void CMembre::setFirstName(const std::string firstName) {

    this->firstName = (std::string)firstName;

}

void CMembre::setBirthDate(const CDate birthDate) {

    this->birthDate.set(birthDate.getDay(), birthDate.getMonth(), birthDate.getYear());

}

void CMembre::set(const std::string name, const std::string firstName, const CDate birthDate) {

    setName(name);
    setFirstName(firstName);
    setBirthDate(birthDate);

}

void CMembre::setMember(const CMembre& member) {

    setName(member.getName());
    setFirstName(member.getFirstName());
    setBirthDate(member.getBirthDate());

}

std::string CMembre::print() const {

    std::ostringstream oss;

    oss << this->firstName << " ";
    oss << this->name << ", né(e) le ";
    oss << this->birthDate.print();

    /*std::cout << this->firstName << " " << this->name << ", né(e) le ";

    this->birthDate.print();*/

    return oss.str();

}
