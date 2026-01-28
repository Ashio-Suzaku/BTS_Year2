#include "CNotes.h"

CNotes::~CNotes() {

    pElem p = prem;

    while (prem != NULL) {

        p = p->suiv;
        delete prem;
        prem = p;

    }

    prem = dern = NULL;
    nbElem = 0;

}

void CNotes::Ajoute(double v) {

    pElem p = new CElem;
    p->note = v;
    p->suiv = NULL;

    if (prem == NULL) {
        
        prem = dern = p;

    } else {

        dern->suiv = p;
        dern = dern->suiv;

    }

    nbElem++;

}

double CNotes::Moyenne() const {

    double total = 0.0;
    pElem p = prem;
    
    if (nbNotes() == 0) {

        return 0.0;

    } else {

        while (p != NULL) {

            total += p->note;
            p = p->suiv;

        }

        return total/(double)nbNotes();

    }

}

void CNotes::Liste() {

    pElem p = prem;
    int i = 1;

    while (p != NULL) {

            cout << "Note n°" << i << " : " << p->note << endl;
            p = p->suiv;
            i++;

    }

    cout << endl;

}

double& CNotes::operator +=(double v) {

    Ajoute(v);

}

double& CNotes::operator [](int i) {

    pElem p = prem;
    int iCheck = 0;

    while (p != NULL) {
        puts("#11");
        iCheck++;

        if (iCheck-1 == i) return p->note;
        p = p->suiv;
        puts("#12");
    }

    iCheck = 0;
    p = prem;
    puts("#13");

    if (i == 0) {

        Ajoute(0);
        p = prem;

    }

    while (iCheck < i) {
        puts("#14");
        if (p->suiv == NULL) {Ajoute(0);}
        iCheck++;
        p = p->suiv;
        puts("#15");
    }
    puts("#16");
    return p->note;

}

double& CNotes::operator+(double v) {

    Ajoute(v);

}