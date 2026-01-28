#include "CNotes.h"

void affiche(const string& m, const CNotes& c ) {

    cout << m << " : " << c.nbNotes() << " note";

    if (c.nbNotes() > 1) cout << 's';
    cout << ", moy. = " << c.Moyenne() << endl;

}

int main(void) {

    CNotes math; // constructeur par défaut
    CNotes physique(7);
    CNotes anglais;
    CNotes francais(12);

    math.Ajoute(12); // méthode Ajoute()
    math.Ajoute(10);

    physique += 13;
    physique += 10;

    affiche("math ", math);
    affiche("physique ", physique);
    physique.Liste();
    
    //math[1] = 13;
    //cout << math[1] << endl;
    //math[4] = 7.54;
    //math[12] = 1;

    //affiche("math ", math);
    //math.Liste();

    anglais[0] = 11; puts("#1");
    anglais[1] = 15; puts("#2");
    //anglais = anglais + 13;

    francais[2] = 14; puts("#3");

    affiche("anglais  ", anglais); //puts("#4");
    anglais.Liste();
    affiche("français ", francais); //puts("#5");
    francais.Liste();

}