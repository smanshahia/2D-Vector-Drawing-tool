#pragma once
#include "BaseShape.h"
#include "Point2.h"
#include <GL\glut.h>
#include <math.h>

class CircleShape :public BaseShape
{
public:
	CircleShape(Point2 center, Point2 edge, int seg);
	~CircleShape();
	void BaseShape::drawShape(bool EditMode);
	int BaseShape::getHotspots(Point2 mouse);
	void setHotspot(Point2 pos, int num);
	void BaseShape::setDrawColor(float r, float g, float b);
	void offsetSegment(short offset);
private:
	Point2 center, edge;
	unsigned int seg;
};

