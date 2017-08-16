#pragma once
#include "Point2.h"
#include "BaseShape.h"
#include <GL\glut.h>

class RectShape: public BaseShape
{
private:
	Point2 a, b;
public:
	RectShape();
	RectShape(Point2 a, Point2 b);
	~RectShape();
	void BaseShape::drawShape(bool EditMode);
	void setHotspot(Point2 pos, int num);
	int BaseShape::getHotspots(Point2 mouse);
	void BaseShape::setDrawColor(float r, float g, float b);

};

