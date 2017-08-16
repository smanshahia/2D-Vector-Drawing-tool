#include "LineShape.h"



LineShape::LineShape(Point2 a, Point2 b)
{
	this->a = a;
	this->b = b;
}


LineShape::~LineShape()
{
}

void LineShape::setHotspot(Point2 pos, int num)
{
	if (num == 0)
	{
		a = pos;
	}
	else
		b = pos;
}

void LineShape::drawShape(bool EditMode)
{
	glColor3f(0, 1, 0);
	if (EditMode)
	{
		glPointSize(5);

		glBegin(GL_POINTS);

		glVertex2i(a.getX(), a.getY());
		glVertex2i(b.getX(), b.getY());

		glEnd();

		glBegin(GL_LINES);

		glVertex2i(a.getX(), a.getY());
		glVertex2i(b.getX(), b.getY());

		glEnd();
	}
	else
	{
		glBegin(GL_LINES);

		glVertex2i(a.getX(), a.getY());
		glVertex2i(b.getX(), b.getY());

		glEnd();
	}
}

int LineShape::getHotspots(Point2 mouse)
{
	if ((mouse.getX() < a.getX() + 10 && mouse.getX() > a.getX() - 10) && (mouse.getY() < a.getY() + 10 && mouse.getY() > a.getY() - 10))
	{
		return 0;
	}
	else if ((mouse.getX() < b.getX() + 10 && mouse.getX() > b.getX() - 10) && (mouse.getY() < b.getY() + 10 && mouse.getY() > b.getY() - 10))
	{
		return 1;
	}
	else
		return -1;
}

void LineShape::setDrawColor(float r, float g, float b)
{

}
