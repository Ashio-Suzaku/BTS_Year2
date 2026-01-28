/* ----------------------------------------------------------------------------
 |	BTS CIEL    Lycée La Fayette 0770920G
 + ----------------------------------------------------------------------------
 |
 |	Nom :			crectangle.cpp
 |
 |	Projet :		cfigure
 |	Sujet :     	illustration du cours "Langage C++" Part. 3
 |
 |  Auteur :		Sacha OULD CADI-RAVILY
 |	Version :		1.0
 |	Cr�ation :		08/01/2026
 |	Mise � jour :	28/01/2026
 |
 |	Fabrication :	librairie XamGraph version SDL-2
 + ------------------------------------------------------------------------- */

#include "crectangle.h"
#include "cdraft.h"
#include "cmydraft.h"
#include "cfigure.h"

void CRectangle::draw(CDraft& dr) const {

    if (!this->isVisible()) return;

    CPoint pts[4] = {

        CPoint(this->getX(), this->getY()),
		CPoint(this->getX() + this->getDX(), this->getY()),
		CPoint(this->getX() + this->getDX(), this->getY() + this->getDY()),
		CPoint(this->getX(), this->getY() + this->getDY())

    };

    dr.poly(getPos(), 4, pts, getColor(), isFill());
    
}
