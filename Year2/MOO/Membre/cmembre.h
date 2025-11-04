#ifndef CMEMBRE_H
#define CMEMBRE_H

#include "cdate.h"

class CMembre {

    private:
        std::string name;
        std::string firstName;
        CDate birthDate;

    public:
        CMembre() {set("?", "?", (1, JAN, 1900));}

        CMembre(std:string name, std::string firstName, CDate birthDate) {

            set(std:string name, std::string firstName, CDate birthDate);

        }

        std::string getName() const;
        std::string getFirstName() const;
        CDate getBirthDate() const;

        void setName(std::string name);
        void setFirstName(std::string firstName);
        void setBirthDate(CDate birthDate);

        void set(std::string name, std::string firstName, CDate birthDate);

};

#endif