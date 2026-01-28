/* ----------------------------------------------------------------------------
 |	BTS CIEL    Lycée La Fayette 0770920G
 + ----------------------------------------------------------------------------
 |
 |	Nom :			cpolygon.cpp
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

#include "cpolygon.h"
#include "cdraft.h"
#include "cmydraft.h"
#include "cfigure.h"

void CPolygon::setPoints(int nbPts, CPoint* pts) {

    num = nbPts;
    ppts = NULL;

    if (!nbPts) return;

    ppts = new CPoint[num];

    for (int i = 0; i < nbPts; i++) ppts[i] = *(pts + i) ;

}

void CPolygon::draw(CDraft& dr) const {

    if (ppts == NULL) return;

    if (!isVisible()) return;

    dr.poly(getPos(), num, ppts, getColor(), isFill());

}