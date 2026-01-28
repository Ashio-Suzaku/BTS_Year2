/* ----------------------------------------------------------------------------
 |	BTS CIEL    Lyc�e La Fayette 0770920G
 + ----------------------------------------------------------------------------
 |
 |	Nom :			cmydraft.h
 |
 |	Projet :		cfigure
 |	Sujet :     	illustration du cours "Langage C++" Part. 3
 |
 |  Auteur :		Sacha OULD CADI-RAVILY
 |	Version :		0.1
 |	Cr�ation :		08/01/2026
 |	Mise � jour :	N/A
 |
 |	Fabrication :	librairie XamGraph version SDL-0.2x ou sup. requise
 + ------------------------------------------------------------------------- */

#ifndef CMYDRAFT_H
#define CMYDRAFT_H

#include <xamgraph.h>
#include "cpoint.h"
#include "cdraft.h"
#include "cvector.h"
#include "crectangle.h"
#include "clozenge.h"
#include "clabel.h"
#include "cbutton.h"
#include "csquare.h"
#include "cfigure.h"
#include "cpolygon.h"
#include "ccircle.h"
#include <string>


// annonces de classes
class CRectangle;
class CVector;
class CLozenge;
class CLabel;
class CButton;
class CSquare;
class CDraft;
class CPolygon;
class CCircle;

// classe CMyDraft : gestion d'une zone de dessin 2D

class CMyDraft : public CDraft {

	CPoint	org;
	int		scale;

	static bool verbose;

  public :

	CMyDraft(int w = 640, int h = 480) : CDraft(w, h) {}
	~CMyDraft();

	void draw(bool grad = false) {CDraft::draw(grad);};			// dessin du rep�re gradu�
	void draw(const CVector& v);
	void draw(const CRectangle& r);
	void draw(const CLozenge& z);
	void draw(const CLabel& l);
	void draw(const CButton& b);

};

#endif