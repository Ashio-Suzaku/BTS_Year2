/* ----------------------------------------------------------------------------
 |	BTS CIEL    Lycée La Fayette 0770920G
 + ----------------------------------------------------------------------------
 |
 |	Nom :			cvector.cpp
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

#include "cvector.h"
#include "cdraft.h"
#include <cmath>

CPoint CVector::getEnd() const
{
	return CPoint( getXEnd(), getYEnd() ) ;
}

double CVector::getLength() const
{
	return std::sqrt( dx * dx + dy * dy ) ;
}

void CVector::draw(CDraft& dr) const {
	
	if (!isVisible()) return;
	
	dr.line(getPos(), getEnd(), getColor());

}