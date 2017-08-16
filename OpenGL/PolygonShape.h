#pragma once
#include "BaseShape.h"
#include "Point2.h"
#include <vector>
#include <GL\glut.h>
#include <iterator>

class PolygonShape :
	public BaseShape
{
private:
	std::vector<Point2> p;
public:
	PolygonShape();
	~PolygonShape();
	void addHotspot(Point2 x);
	void BaseShape::drawShape(bool EditMode);
	int BaseShape::getHotspots(Point2 mouse);
	void setHotspot(Point2 pos, int num);
	void BaseShape::setDrawColor(float r, float g, float b);
};

