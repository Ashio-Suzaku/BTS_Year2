/* ----------------------------------------------------------------------------
 |	BTS CIEL    Lycée La Fayette 0770920G
 + ----------------------------------------------------------------------------
 |
 |	Nom :			main.cpp
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
#include <string>
using namespace std ;

int main(int argc, char** argv) {

	// Traitement de l'option '-v' (ligne de commandes)

	if ( argc > 1 ) {

		string opt(*++argv);
		if (opt == "-v" || opt == "-verbose")	CMyDraft::setVerbose(true);

	}

	// Construction de l'espace graphique

	CMyDraft draft(800, 600);

	draft.setX(400);
	draft.setY(300);
	draft.setScale(40);
	draft.draw(true);

	draft.XamGraph::loadImage(720, 0, "./src/embleme2.png");

	CVector v1(CPoint(1.5, 2), CPoint(7.2, 5));
	v1.setColor(XAM_LIGHT_RED);
	v1.setVisible(true);
	draft.draw(v1);

	CRectangle r1(5, 2.5);
	r1.setPos(CPoint(-6, 4.5));
	r1.setColor(XAM_LIGHT_BLUE);
	r1.setVisible(true);
	r1.setFill(true);
	draft.draw(r1);

	CSquare s1(3);
	s1.setPos(CPoint(2.4, 1));
	s1.setColor(XAM_DARK_MAGENTA);
	s1.setVisible(true);
	s1.setFill(false);
	draft.draw(s1);

	CLozenge z1(3, 1.4);
	z1.setPos(CPoint(-9, -4.5));
	z1.setColor(XAM_CYAN);
	z1.setVisible(true);
	z1.setFill(true);
	draft.draw(z1);

	CLabel l1("MY_CLABEL1");
	l1.setPos(CPoint(-8, -2));
	l1.setColor(XAM_DARK_GREEN);
	l1.setVisible(true);
	draft.draw(l1);

	CButton b1(CPoint(5.5, -5.2), 4, 1, "MY_CBUTTON1");
	b1.setColor(XAM_LAVENDER);
	b1.setVisible(true);
	b1.setFill(true);
	draft.draw(b1);

	int slot = 6; //nb figure dans le tableau suivant
	int contained = 0;
	CFigure* figure[slot];

	figure[0] = new CVector(4, -1.6);
	figure[0]->setPos(CPoint(-5, -4));
	figure[0]->setColor(XAM_RED);
	figure[0]->setVisible(true);
	contained++;

	figure[1] = new CRectangle(1, 3.14);
	figure[1]->setPos(CPoint(-8.5, 2));
	figure[1]->setColor(XAM_BLUE);
	figure[1]->setVisible(true);
	contained++;

	figure[2] = new CSquare(1.8);
	figure[2]->setPos(CPoint(-3, -0.5));
	figure[2]->setColor(XAM_VIOLET);
	figure[2]->setFill(true);
	figure[2]->setVisible(true);
	contained++;

	figure[3] = new CLozenge(4, 2.4);
	figure[3]->setPos(CPoint(0, 6));
	figure[3]->setColor(XAM_DARK_CYAN);
	figure[3]->setVisible(true);
	contained++;

	figure[4] = new CLabel("MY_CLABEL2");
	figure[4]->setPos(CPoint(6.5, 2));
	figure[4]->setColor(XAM_GREEN);
	figure[4]->setVisible(true);
	contained++;

	figure[5] = new CButton(CPoint(-8, 6.3), 5, 0.8, "MY_CBUTTON2");
	figure[5]->setColor(XAM_ORANGE);
	figure[5]->setVisible(true);
	contained++;

	for (int i = 0; i < slot; i++) {

		if (i < contained) {figure[i]->draw(draft);}

	}

	CPoint pts1[3] = {

		CPoint(-1, 0),
		CPoint(1, 1),
		CPoint(1, -1)

	};
	CPolygon poly1(CPoint(0, 0), 3, pts1);
	poly1.setVisible(true);
	poly1.setColor(XAM_BLACK);
	poly1.draw(draft);

	CPoint pts2[12] = {

		CPoint(2, -4),
		CPoint(3, -4),
		CPoint(3, -5),
		CPoint(4, -5),
		CPoint(4, -6),
		CPoint(3, -6),
		CPoint(3, -7),
		CPoint(2, -7),
		CPoint(2, -6),
		CPoint(1, -6),
		CPoint(1, -5),
		CPoint(2, -5)

	};
	CPolygon cross(CPoint(1, -4), 12, pts2);
	cross.setVisible(true);
	cross.setColor(XAM_GOLD);
	cross.setFill(true);
	cross.draw(draft);

	CCircle circle(CPoint(7.5, -3), 1.2);
	circle.setVisible(true);
	circle.setColor(XAM_PINK);
	circle.draw(draft);

	///Placer les objets à tracer avant ce bloc
	draft.updateScreen();
	draft.run();

	return 0;

}
