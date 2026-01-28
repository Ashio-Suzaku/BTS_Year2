// crectangle.h

#ifndef CRECTANGLE_H
#define CRECTANGLE_H

#include "cvector.h"
#include <cmath>

// annonces de classes
class CDraft;

class CRectangle : public CVector {

	public:

	CRectangle(double width, double height ) 
		: CVector(width, -height ) {}

	double getPerimeter() const 
	{
		return 2 * ( std::fabs(dx) + std::fabs(dy) ) ;
	}

	virtual std::string draw() { return "CRectangle::draw()" ; }

	virtual std::string className() const { return "CRectangle" ; }

	virtual void draw(CDraft& dr) const;

} ;

#endif

