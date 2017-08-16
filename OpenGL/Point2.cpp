#include "Point2.h"



Point2::Point2(int x, int y)
{
	this->x = x;
	this->y = y;
}

Point2::Point2()
{
	this->x = 0;
	this->y = 0;
}

int Point2::getX()
{
	return x;
}

int Point2::getY()
{
	return y;
}

void Point2::setX(int x)
{
	this->x = x;
}

void Point2::setY(int y)
{
	this->y = y;
}

float Point2::calcDist(Point2 x, Point2 y)
{
	float a = x.getX() - y.getX();
	float b = x.getY() - y.getY();
	return sqrt(a*a + b*b);
}


Point2::~Point2()
{
}
