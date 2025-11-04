#include "cmembre.h"

std::string CMembre::getName() const {

    return (std::string)name;

}

std::string CMembre::getFirstName() const {

    return (std::string)firstName;

}

CDate CMembre::getBirthDate() const {

    return (CDate)birthDate;

}

void CMembre::setName(std::string name) {

    this->name = (std::string)name;

}

void CMembre::setFirstName(std::string firstName) {

    this->firstName = (std::string)firstName;

}

void CMembre::setBirthDate(CDate birthDate) {

    this->birthDate = (CDate)birthDate;

}

void CMembre::set(std::string name, std::string firstName, CDate birthDate) {

    setName(name);
    setFirstName(firstName);
    setBirthDate(birthDate);

}