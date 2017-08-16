#include "CircleShape.h"



CircleShape::CircleShape(Point2 center, Point2 edge, int seg)
{
	this->center = center;
	this->edge = edge;
	this->seg = seg;
}


CircleShape::~CircleShape()
{
}

void CircleShape::drawShape(bool EditMode)
{
	glColor3f(0, 0, 0);
	if (EditMode)
	{
		glPointSize(5);
		glBegin(GL_POINTS);

		glVertex2i(center.getX(), center.getY());
		glVertex2i(edge.getX(), edge.getY());

		glEnd();

		glBegin(GL_LINES);
		float inc = 2.0f*(22.0f / 7.0f) / seg;
		for (int i = 1; i < seg; i++)
		{
			int x = center.getX() + (sin(i * inc) * Point2::calcDist(center, edge));
			int y = center.getY() + (cos(i * inc) * Point2::calcDist(center, edge));

			int x1 = center.getX() + (sin((i - 1) * inc) * Point2::calcDist(center, edge));
			int y1 = center.getY() + (cos((i - 1) * inc) * Point2::calcDist(center, edge));
			glVertex2i(x, y);
			glVertex2i(x1, y1);
		}
		int x = center.getX() + (sin(0 * inc) * Point2::calcDist(center, edge));
		int y = center.getY() + (cos(0 * inc) * Point2::calcDist(center, edge));

		int x1 = center.getX() + (sin((seg - 1) * inc) * Point2::calcDist(center, edge));
		int y1 = center.getY() + (cos((seg - 1) * inc) * Point2::calcDist(center, edge));

		glVertex2i(x, y);
		glVertex2i(x1, y1);

		glEnd();
	}
	else
	{
		glBegin(GL_LINES);
		float inc = 2.0f*(22.0f / 7.0f) / seg;
		for (int i = 1; i < seg; i++)
		{
			int x = center.getX() + (sin(i * inc) * Point2::calcDist(center, edge));
			int y = center.getY() + (cos(i * inc) * Point2::calcDist(center, edge));

			int x1 = center.getX() + (sin((i - 1) * inc) * Point2::calcDist(center, edge));
			int y1 = center.getY() + (cos((i - 1) * inc) * Point2::calcDist(center, edge));
			glVertex2i(x, y);
			glVertex2i(x1, y1);
		}
		int x = center.getX() + (sin(0 * inc) * Point2::calcDist(center, edge));
		int y = center.getY() + (cos(0 * inc) * Point2::calcDist(center, edge));

		int x1 = center.getX() + (sin((seg - 1) * inc) * Point2::calcDist(center, edge));
		int y1 = center.getY() + (cos((seg - 1) * inc) * Point2::calcDist(center, edge));

		glVertex2i(x, y);
		glVertex2i(x1, y1);

		glEnd();
	}


}
void CircleShape::setHotspot(Point2 pos, int num)
{
	Point2 temp;
	if (num == 0)
	{
		temp.setX( pos.getX() - center.getX());
		temp.setY( pos.getY() - center.getY());
		center = pos;
		edge.setX(edge.getX() + temp.getX());
		edge.setY(edge.getY() + temp.getY());
	}
	else
		edge = pos;
}
int CircleShape::getHotspots(Point2 mouse)
{
	if ((mouse.getX() < center.getX() + 10 && mouse.getX() > center.getX() - 10) && (mouse.getY() < center.getY() + 10 && mouse.getY() > center.getY() - 10))
	{
		return 0;
	}
	else if ((mouse.getX() < edge.getX() + 10 && mouse.getX() > edge.getX() - 10) && (mouse.getY() < edge.getY() + 10 && mouse.getY() > edge.getY() - 10))
	{
		return 1;
	}
	else
		return -1;
}
void CircleShape::setDrawColor(float r, float g, float b)
{

}
void CircleShape::offsetSegment(short offset)
{
	if (offset > 0)
	{
		if (seg < 40)
		{
			seg += offset;
		}
	}
	else
	{
		if (seg >10)
		{
			seg += offset;
		}

	}
}