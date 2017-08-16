#pragma once
#include <math.h>

class Point2
{
public:
	Point2(int x, int y);
	Point2();
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	~Point2();
	static float calcDist(Point2 x, Point2 y);
private:
	int x, y;
};

