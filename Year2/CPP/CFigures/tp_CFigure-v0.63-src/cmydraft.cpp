/* ----------------------------------------------------------------------------
 |	BTS CIEL    Lycée La Fayette 0770920G
 + ----------------------------------------------------------------------------
 |
 |	Nom :			cmydraft.cpp
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

#include "cmydraft.h"
#include "cdraft.h"
#include "cvector.h"
#include "crectangle.h"
#include "clozenge.h"
#include "clabel.h"
#include "cbutton.h"
#include "csquare.h"
#include "cpolygon.h"
#include "ccircle.h"

#include <iostream>

bool CMyDraft::verbose = false ;

// Destruction de la zone graphique

CMyDraft::~CMyDraft() {
	
	if ( verbose )	std::cerr << "Bye..." << std::endl ;

}

//Méthodes publiques

void CMyDraft::draw(const CVector& v) {

	if (!v.isVisible()) return;

	line(v.getPos(), v.getEnd(), v.getColor());

}

void CMyDraft::draw(const CRectangle& r) {

	if (!r.isVisible()) return;

	CPoint pts[4] = {

		CPoint(r.getX(), r.getY()),
		CPoint(r.getX() + r.getDX(), r.getY()),
		CPoint(r.getX() + r.getDX(), r.getY() + r.getDY()),
		CPoint(r.getX(), r.getY() + r.getDY())
	};

	poly(r.getPos(), 4, pts, r.getColor(), r.isFill());

}

void CMyDraft::draw(const CLozenge& z) {

	if (!z.isVisible()) return;

	CPoint pts[4] = {

		CPoint(z.getX() + z.getDX()/2, z.getY()),
		CPoint(z.getX() + z.getDX(), z.getY() + z.getDY()/2),
		CPoint(z.getX() + z.getDX()/2, z.getY() + z.getDY()),
		CPoint(z.getX(), z.getY() + z.getDY()/2)
	};

	poly(z.getPos(), 4, pts, z.getColor(), z.isFill());

}

void CMyDraft::draw(const CLabel& l) {

	if (!l.isVisible()) return;

	text(l.getPos(), l.getText(), l.getColor());

}

void CMyDraft::draw(const CButton& b) {

	if (!b.isVisible()) return;

	CPoint pts[4] = {

		CPoint(b.getX(), b.getY()),
		CPoint(b.getX() + b.getDX(), b.getY()),
		CPoint(b.getX() + b.getDX(), b.getY() + b.getDY()),
		CPoint(b.getX(), b.getY() + b.getDY())

	};

	poly(b.getPos(), 4, pts, b.getColor(), b.isFill());
	text((CRectangle) b, b.getText());

}
