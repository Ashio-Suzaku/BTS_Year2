/* ----------------------------------------------------------------------------
 |	BTS CIEL    Lycée La Fayette 0770920G
 + ----------------------------------------------------------------------------
 |
 |	Nom :			clabel.cpp
 |
 |	Projet :		cfigure
 |	Sujet :     	illustration du cours "Langage C++" Part. 3
 |
 |  Auteur :		Sacha OULD CADI-RAVILY
 |	Version :		1.0
 |	Cr�ation :		16/01/2026
 |	Mise � jour :	21/01/2026
 |
 |	Fabrication :	librairie XamGraph version SDL-2
 + ------------------------------------------------------------------------- */

#include "clabel.h"
#include "cdraft.h"
#include "cmydraft.h"
#include "cfigure.h"

void CLabel::draw(CDraft& dr) const {

	if (!this->isVisible()) return;

	dr.text(this->getPos(), this->getText(), this->getColor());

}