#pragma once
#include "Point2.h"
class BaseShape
{
public:
	BaseShape();
	~BaseShape();
	virtual void drawShape(bool EditMode) = 0;
	virtual void setDrawColor(float r, float g, float b) = 0;
	virtual int getHotspots(Point2 mouse) = 0;


};

