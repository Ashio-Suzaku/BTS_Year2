// clozenge.h

#ifndef CLOZENGE_H
#define CLOZENGE_H

#include "crectangle.h"

// annonces de classes
class CDraft;

class CLozenge : public CRectangle {

  public :
  	CLozenge(double width, double height ) : CRectangle(width, height ) {}

	std::string draw() { return "CLozenge::draw()" ; }

	virtual std::string className() const { return "CLozenge" ; }

	virtual void draw(CDraft& dr) const;

} ;
  
#endif

