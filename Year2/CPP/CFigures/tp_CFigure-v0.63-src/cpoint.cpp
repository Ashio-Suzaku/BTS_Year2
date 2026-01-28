/* ----------------------------------------------------------------------------
 |	BTS CIEL    Lycée La Fayette 0770920G
 + ----------------------------------------------------------------------------
 |
 |	Nom :			cpoint.cpp
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

#include "cpoint.h"
#include <sstream>

std::string CPoint::asString() const
{
	std::ostringstream	oss ;
	oss << '(' << x << ',' << y << ')' ;
	return oss.str() ;
}

CPoint&	CPoint::operator +=(const CPoint& p )
{
	set( x + p.x, y + p.y ) ;
	return *this ;
}

CPoint& CPoint::operator *=(double v )
{
	set( x * v, y * v ) ;
	return *this ;
}

bool CPoint::operator ==(const CPoint& p )
{
	return ( x == p.x )&&( y == p.y ) ;
}

bool CPoint::operator !=(const CPoint& p )
{
	return !( *this == p ) ;
}

std::ostream& operator <<(std::ostream& s, const CPoint& p )
{
	s << p.asString() ;
	return s ;
}

