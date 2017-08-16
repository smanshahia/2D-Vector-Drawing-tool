#include <GL\glut.h>
#include <iostream>
#include "RectShape.h"
#include "LineShape.h"
#include "CircleShape.h"
#include "PolygonShape.h"
#include <list>
#include <typeinfo.h>

using namespace std;

enum SelectedShape
{
	LINE = 0,
	RECTANGLE,
	CIRCLE,
	POLYGON,
	TOGGLE_POLY_ADDITIONS,
	TOGGLE_EDIT_MODE,
	CLEAR_SCREEN,
	MENU_EXIT

};

int selected = RECTANGLE;
bool AddingVertices = false;
bool EditMode = false;
int num = -1;

BaseShape *drawing;
list<BaseShape *> shapelist;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0);

	for (list<BaseShape *>::iterator i = shapelist.begin(); i != shapelist.end(); i++)
	{
		(*i)->drawShape(EditMode);
	}

	glFlush();
}

void mouse(int button, int state, int x, int y)
{

	if (button == GLUT_LEFT_BUTTON)
	{

		if (EditMode && state == GLUT_DOWN)
		{

			for (list<BaseShape *>::iterator i = shapelist.begin(); i != shapelist.end(); i++)
			{
				if ((*i)->getHotspots(Point2(x, y)) != -1)
				{
					num = (*i)->getHotspots(Point2(x, y));
					drawing = *i;
					break;
				}
			}
		}
		if (state == GLUT_UP && num != -1)
		{
			cout << num << " " << typeid(*drawing).name();
			if (typeid(*drawing) == typeid(LineShape))
			{
				dynamic_cast<LineShape *>(drawing)->setHotspot(Point2(x, y), num);
				num = -1;
			}
			if (typeid(*drawing) == typeid(RectShape))
			{
				dynamic_cast<RectShape *>(drawing)->setHotspot(Point2(x, y), num);
				num = -1;
			}
			if (typeid(*drawing) == typeid(CircleShape))
			{
				dynamic_cast<CircleShape *>(drawing)->setHotspot(Point2(x, y), num);
				num = -1;
			}
			if (typeid(*drawing) == typeid(PolygonShape))
			{
				dynamic_cast<PolygonShape *>(drawing)->setHotspot(Point2(x, y), num);
				num = -1;
			}
		}

		switch (selected)
		{
		case(LINE):
			if ( !EditMode)
			{
				if (state == GLUT_DOWN)
				{
					drawing = new LineShape(Point2(x, y), Point2(x, y));
				}
				if (state == GLUT_UP)
				{
					dynamic_cast<LineShape *>(drawing)->setHotspot(Point2(x, y), 1);
					shapelist.push_front(drawing);
				}
			}
			break;
		case(RECTANGLE):

			if (!EditMode)
			{
				if (state == GLUT_DOWN)
				{
					drawing = new RectShape(Point2(x, y), Point2(x, y));
				}
				if (state == GLUT_UP)
				{
					dynamic_cast<RectShape *>(drawing)->setHotspot(Point2(x, y), 1);
					shapelist.push_front(drawing);
				}
			}
			break;
		case(CIRCLE):
			if ( !EditMode)
			{
				if (state == GLUT_DOWN)
				{
					drawing = new CircleShape(Point2(x, y), Point2(x, y), 30);
				}
				if (state == GLUT_UP)
				{
					dynamic_cast<CircleShape *>(drawing)->setHotspot(Point2(x, y), 1);
					shapelist.push_front(drawing);
				}
			}
			if (drawing != nullptr)
			{

				if (button == 3)
				{
					dynamic_cast<CircleShape *>(drawing)->offsetSegment(1);


				}
				if (button == 4)
				{
					dynamic_cast<CircleShape *>(drawing)->offsetSegment(-1);

				}

			}
			break;
		case(POLYGON): std::cout << "in polygon";
			if ( !EditMode)
			{
				if (button == GLUT_DOWN)
				{
					if (!AddingVertices) // if not continue then create new poly
					{
						drawing = new PolygonShape();
						drawing->setDrawColor(0.8f, 0.3f, 0.6f);
						AddingVertices = true;
						shapelist.push_front(drawing);
					}
					dynamic_cast<PolygonShape *>(drawing)->addHotspot(Point2(x, y));
				}
				else
					AddingVertices = false;
			}
			break;
		}
	}
}

void SelectFromMenu(int commandID)
{
	switch (commandID)
	{
	case LINE:
		selected = LINE;
		break;
	case RECTANGLE:
		selected = RECTANGLE;
		break;
	case CIRCLE:
		selected = CIRCLE;
		break;
	case POLYGON:
		selected = POLYGON;
		break;
	case TOGGLE_POLY_ADDITIONS:
		AddingVertices = !AddingVertices;
		break;
	case TOGGLE_EDIT_MODE:
		EditMode = !EditMode;
		break;
	case CLEAR_SCREEN:
		shapelist.clear();
		break;
	case MENU_EXIT:
		exit(0);
		break;
	}
	glutPostRedisplay();
}

int BuildPopupMenu(void)
{
	int menu;
	menu = glutCreateMenu(SelectFromMenu);
	glutAddMenuEntry("SELECT LINES", LINE);
	glutAddMenuEntry("SELECT RECTANGLES", RECTANGLE);
	glutAddMenuEntry("SELECT CIRCLES", CIRCLE);
	glutAddMenuEntry("SELECT POLYGONS", POLYGON);
	glutAddMenuEntry("TOGGLE POLYGON VERTEX ADDITION", TOGGLE_POLY_ADDITIONS);
	glutAddMenuEntry("TOGGLE EDIT MODE", TOGGLE_EDIT_MODE);
	glutAddMenuEntry("Clear screen", CLEAR_SCREEN);
	glutAddMenuEntry("Exit\tEsc", MENU_EXIT);
	return menu;
}

void reshapeFunc(int x, int y)
{
	if (y == 0)
		return;

	glViewport(0, 0, x, y);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(0, x, y, 0);
	glMatrixMode(GL_MODELVIEW);
}

void idleFunc()
{
	display();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 380);
	glutCreateWindow("Paint");

	glClearColor(1, 1, 1, 1);

	glutDisplayFunc(display);
	glutReshapeFunc(reshapeFunc);

	glutMouseFunc(mouse);
	BuildPopupMenu();
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutIdleFunc(idleFunc);

	glutMainLoop();
	return 0;
}