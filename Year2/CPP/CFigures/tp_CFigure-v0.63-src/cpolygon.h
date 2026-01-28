// cpolygon.h

#ifndef CPOLYGON_H
#define CPOLYGON_H

#include "cfigure.h"
#include "cdraft.h"
#include <cmath>

class CPolygon : public CFigure {

    private:
        CPoint* ppts ;
        int num ;
    
    protected :
        void setPoints(int nbPts, CPoint* pts ) ;

    public :
        CPolygon() : CFigure(), ppts(NULL), num(0) {}
        CPolygon(CPoint pos, int nbPts = 0, CPoint* pts = NULL ) : CFigure( pos ) {
            
            setPoints(nbPts, pts);
            setFill(false);
        
        }
        ~CPolygon() { delete [] ppts ; }

        virtual double area() const { return 0;} ;
	    virtual std::string className() const {return "CPolygon"; } ;

        virtual void draw(CDraft& dr) const;

};

#endif

