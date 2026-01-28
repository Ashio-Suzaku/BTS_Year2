/* ----------------------------------------------------------------------------
 |	BTS CIEL    Lycée La Fayette 0770920G
 + ----------------------------------------------------------------------------
 |
 |	Nom :			ccircle.cpp
 |
 |	Projet :		cfigure
 |	Sujet :     	illustration du cours "Langage C++" Part. 3
 |
 |  Auteur :		Sacha OULD CADI-RAVILY
 |	Version :		1.0
 |	Cr�ation :		23/01/2026
 |	Mise � jour :	28/01/2026
 |
 |	Fabrication :	librairie XamGraph version SDL-2
 + ------------------------------------------------------------------------- */

#include "ccircle.h"

void CCircle::setPointsTable(double radius, CPoint pos) {

    points[11].set((radius*cos(2*M_PI))+pos.getX(), (radius*sin(2*M_PI))+pos.getY());

    for (int i = 0; i < 11; i++) {

        points[i].set((radius*cos((i+1)*M_PI/6))+pos.getX(), (radius*sin((i+1)*M_PI/6))+pos.getY());

    }

}