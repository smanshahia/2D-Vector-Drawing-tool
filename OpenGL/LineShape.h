#pragma once
#include "Point2.h"
#include "BaseShape.h"
#include <GL\glut.h>

class LineShape: public BaseShape
{
private:
	Point2 a, b;
public:
	LineShape(Point2 a, Point2 b);
	~LineShape();
	void BaseShape::drawShape(bool EditMode);
	int BaseShape::getHotspots(Point2 mouse);
	void setHotspot(Point2 pos, int num);
	void BaseShape::setDrawColor(float r, float g, float b);

};

