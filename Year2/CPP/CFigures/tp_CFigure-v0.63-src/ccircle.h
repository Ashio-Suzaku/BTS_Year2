#ifndef CCIRCLE_H
#define CCIRCLE_H

#include "cpolygon.h"

class CPolygon;

class CCircle : public CPolygon {

    private:

        double radius;
        CPoint points[12];

    public:

        CCircle(CPoint pos, double radius) : CPolygon(pos, 12, points) {

            setPointsTable(radius, pos);
            setPoints(12, points);

        }

        std::string draw() {return "CCircle::draw()";}

        virtual std::string className() const {return "CCircle";}

        void setPointsTable(double radius, CPoint pos);

        virtual void draw(CDraft& dr) const {CPolygon::draw(dr);};

};

#endif