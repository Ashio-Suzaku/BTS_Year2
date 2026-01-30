/* ----------------------------------------------------------------------------
 |	BTS CIEL    Lycée La Fayette 0770920G
 + ----------------------------------------------------------------------------
 |
 |	Nom :			cbutton.cpp
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

#include "cbutton.h"
#include "cdraft.h"
#include "cmydraft.h"
#include "cfigure.h"

void CButton::draw(CDraft& dr) const {

	if (!this->isVisible()) return;

	CRectangle::draw(dr);
	dr.text((CRectangle) *this, this->getText());

}
