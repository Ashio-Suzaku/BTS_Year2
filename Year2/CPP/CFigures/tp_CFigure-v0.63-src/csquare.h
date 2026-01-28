// csquare.h

#ifndef CSQUARE_H
#define CSQUARE_H

#include "crectangle.h"

// annonces de classes
class CDraft;

class CSquare : public CRectangle {

  public:

  	CSquare(double size) : CRectangle(size, size) {}

	std::string draw() {return "CSquare::draw()";}

	virtual std::string className() const {return "CSquare";}

	virtual void draw(CDraft& dr) const;

};
  
#endif

