#include "PolygonShape.h"



PolygonShape::PolygonShape()
{
}


PolygonShape::~PolygonShape()
{
}

void PolygonShape::drawShape(bool EditMode)
{
	glColor3f(1, 0, 0);
	if (EditMode)
	{
		glPointSize(5);

		glBegin(GL_POINTS);

		for (int i = 0; i < p.size(); i++)
		{
			glVertex2i(p.at(i).getX(), p.at(i).getY());
		}

		glEnd();

		glBegin(GL_LINES);
		for (int i = 0; i < p.size() - 1; i++)
		{
			glVertex2i(p.at(i).getX(), p.at(i).getY());
			glVertex2i(p.at(i + 1).getX(), p.at(i + 1).getY());
		}

		glVertex2i(p.at(p.size() - 1).getX(), p.at(p.size() - 1).getY());
		glVertex2i(p.at(0).getX(), p.at(0).getY());
		glEnd();
	}
	else
	{
		glBegin(GL_LINES);
		for (int i = 0; i < p.size() - 1; i++)
		{
			glVertex2i(p.at(i).getX(), p.at(i).getY());
			glVertex2i(p.at(i + 1).getX(), p.at(i + 1).getY());
		}

		glVertex2i(p.at(p.size() - 1).getX(), p.at(p.size() - 1).getY());
		glVertex2i(p.at(0).getX(), p.at(0).getY());
		glEnd();
	}

}
int PolygonShape::getHotspots(Point2 mouse)
{
	for (int i = 0; i < p.size(); i++)
	{
		if ((mouse.getX() < p[i].getX() + 10 && mouse.getX() > p[i].getX() - 10) && (mouse.getY() < p[i].getY() + 10 && mouse.getY() > p[i].getY() - 10))
		{
			return i;
		}
	}
	return -1;
}
void PolygonShape::setDrawColor(float r, float g, float b)
{

}

void PolygonShape::addHotspot(Point2 x)
{
	p.push_back(x);
}

void PolygonShape::setHotspot(Point2 pos, int num)
{
	p[num] = pos;
}