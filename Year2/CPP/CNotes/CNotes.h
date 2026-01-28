#ifndef CNOTES_H
#define CNOTES_H

#include <iostream>

using namespace std;

class CElem;

typedef CElem* pElem;

class CElem {

    public:
        double note;
        pElem suiv;

};

class CNotes {

    pElem prem, dern;
    int nbElem;

    public:

        CNotes(double n = -1):prem(NULL), dern(NULL), nbElem(0) {

            if (n != -1) Ajoute(n);

        }

        ~CNotes();

        int nbNotes() const {return nbElem;}
        void Ajoute(double v);
        double Moyenne() const;
        void Liste();
        double& operator +=(double v);
        double& operator [](int i);
        double& operator+(double v);

};

#endif