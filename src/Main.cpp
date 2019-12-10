#include "Main.h"
#include "Line.h"
#include "Quad.h"
#include "Circle.h"
#include "UserInterface.h"
#include <iostream>
using std::vector;

GLFWwindow *gWindow;
int gWidth, gHeight;
bool gPress;
CUserInterface * userInterface;
vector <CFigure *> figures;
FigureType figureSelected;
int picked;
float ax1, ay1;
bool fill;

int pick(int x, int y)
{
	picked = -1;
	userInterface->hide();

	for (int i = figures.size()-1; i >= 0; i--)
	{
		float *v1 = figures[i]->getVertex(0);
		float *v2 = figures[i]->getVertex(1);
		float max[2];
		float min[2];

		// This should be precalculated

		
		if (figures[i]->getType() == CIRCLE){

			int rx, ry, r;

			rx = v1[0] - v2[0];
			if (rx < 0) {
				rx = rx * -1;
			}
			ry = v1[1] - v2[1];
			if (ry < 0) {
				ry = ry * -1;
			}
			r = rx;
			if (ry > rx) {
				r = ry;
			}

			min[0] = (int)v1[0] - r;
			max[1] = (int)v1[1] + r;
			max[0] = (int)v2[0] + r;
			min[1] = (int)v2[1] - r;

		}else{

			max[0] = MAX(v1[0], v2[0]);
			max[1] = MAX(v1[1], v2[1]);

			min[0] = MIN(v1[0], v2[0]);
			min[1] = MIN(v1[1], v2[1]);
		}
			
		if (x >= min[0] && x <= max[0] && y >= min[1] && y <= max[1]){

				

				picked = i;

				userInterface->setFigureColor(figures[picked]->getColor());
				userInterface->show();

				int type = figures[picked]->getType();

				if (type == LINE)
					userInterface->setFigureType("Line");
				else
					userInterface->setFigureType("Quad");


				return picked;
				break;
		}
		
	}

	return -1;
}

void updateUserInterface()
{
	if (picked > -1)
	{
		float * color = userInterface->getFigureColor();
		figures[picked]->setColor(color[0], color[1], color[2]);
	}
}

void display()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	for (unsigned int i = 0; i < figures.size(); i++)
		figures[i]->display();
}

void reshape(GLFWwindow *window, int width, int height)
{
	gWidth = width;
	gHeight = height;

	glViewport(0, 0, gWidth, gHeight);

	userInterface->reshape();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(0, gWidth, 0, gHeight, -1.0f, 1.0f);
}

void keyInput(GLFWwindow *window, int key, int scancode, int action, int mods)
{
	if (TwEventKeyGLFW(key, action))
		return;

	if (action == GLFW_PRESS)
	{
		switch (key)
		{
		case GLFW_KEY_ESCAPE:
			glfwSetWindowShouldClose(window, GL_TRUE);
			break;
		case GLFW_KEY_I:
			std::cout << "esto es una prueba \n";
			break;
		case GLFW_KEY_F:
			if (fill) {
				fill = 0;
			}
			else {
				fill = 1;
			}
			break;
		case GLFW_KEY_C:
			figureSelected = CIRCLE;
			break;

		case GLFW_KEY_P:
			figureSelected = NONE;
			//userInterface->hide();
			break;

		case GLFW_KEY_L:
			figureSelected = LINE;
			//userInterface->hide();
			break;

		case GLFW_KEY_Q:
			figureSelected = QUAD;
			//userInterface->hide();
			break;
		}
	}
}

void mouseButton(GLFWwindow* window, int button, int action, int mods)
{
	if (TwEventMouseButtonGLFW(button, action))
		return;

	double x, y;
	glfwGetCursorPos(gWindow, &x, &y);

	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && !gPress)
	{
		float ax = float(x);
		float ay = gHeight - float(y);
		
		if (figureSelected == NONE) {
			if (picked >= 0) {
				figures[picked]->setpicked(0);
			}
			int picked = pick(int(ax), int(ay));
			ax1 = float(x);
			ay1 = gHeight - float(y);
			if (picked >= 0) { 
				figures[picked]->setpicked(1);
				figures[picked]->setfill(fill);
			}
			gPress = true;
		}
		else if (figureSelected == LINE)
		{
			if (picked >= 0) {
				figures[picked]->setpicked(0);
			}
			CLine *line = new CLine();
			line->setVertex(0, ax, ay);
			line->setVertex(1, ax, ay);
			line->setfill(fill);
			line->setColor(userInterface->getr(), userInterface->getg(), userInterface->getb());
			figures.push_back(line);

			gPress = true;
		}
		else if(figureSelected == QUAD)
		{
			if (picked >= 0) {
				figures[picked]->setpicked(0);
			}
			CQuad *quad = new CQuad();
			quad->setVertex(0, ax, ay);
			quad->setVertex(1, ax, ay);
			quad->setfill(fill);
			quad->setColor(userInterface->getr(), userInterface->getg(), userInterface->getb());
			figures.push_back(quad);

			gPress = true;
		}
		else
		{
			if (picked >= 0) {
				figures[picked]->setpicked(0);
			}
			Ccircle* circle = new Ccircle();
			circle->setVertex(0, ax, ay);
			circle->setVertex(1, ax, ay);
			circle->setfill(fill);
			circle->setColor(userInterface->getr(), userInterface->getg(), userInterface->getb());
			figures.push_back(circle);

			gPress = true;
		}
	}

	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
		gPress = false;
}

void cursorPos(GLFWwindow* window, double x, double y)
{
	if (TwEventMousePosGLFW(int(x), int(y)))
		return;

	if (gPress)
	{
		if (figureSelected == NONE && picked >= 0) {
			float ax = float(x);
			float ay = gHeight - float(y);

			int dx = int(ax) - int(ax1);
			int dy = int(ay) - int(ay1);

			ax1 = ax;
			ay1 = ay;

			figures[picked]->move(dx, dy);
		}
		else {
			if (figureSelected != NONE) {
				float ax = float(x);
				float ay = gHeight - float(y);
				std::cout << "axis x: " << ax << " axis y: " << ay << std::endl;
				figures.back()->setVertex(1, ax, ay);
			}
		}
	}
}

void charInput(GLFWwindow* window, unsigned int scanChar)
{
	if (TwEventCharGLFW(scanChar, GLFW_PRESS))
		return;
}

void destroy()
{
	for (unsigned int i = 0; i < figures.size(); i++)
		delete figures[i];

	delete userInterface;

	TwTerminate();
	glfwDestroyWindow(gWindow);
	glfwTerminate();
}

bool initGlfw()
{
	if (!glfwInit())
		return false;

	gWindow = glfwCreateWindow(gWidth, gHeight, "ICG - Plantilla", NULL, NULL);

	if (!gWindow)
	{
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(gWindow);

	const GLFWvidmode * vidMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	glfwSetWindowPos(gWindow, (vidMode->width - gWidth) >> 1, (vidMode->height - gHeight) >> 1);

	glfwSetWindowSizeCallback(gWindow, reshape);
	glfwSetKeyCallback(gWindow, keyInput);
	glfwSetMouseButtonCallback(gWindow, mouseButton);
	glfwSetCursorPosCallback(gWindow, cursorPos);
	glfwSetCharCallback(gWindow, charInput);

	return true;
}

bool initUserInterface()
{
	if (!TwInit(TW_OPENGL, NULL))
		return false;

	userInterface = CUserInterface::Instance();
	return true;
}

int main(void)
{
	gWidth = 1200;
	gHeight = 680;
	gPress = false;
	figureSelected = LINE;
	picked = -1;

	if (!initGlfw() || !initUserInterface())
		return EXIT_FAILURE;

	reshape(gWindow, gWidth, gHeight);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	while (!glfwWindowShouldClose(gWindow))
	{
		display();

		
		TwDraw();

		updateUserInterface();

		glfwSwapBuffers(gWindow);

		glfwPollEvents();
	}

	destroy();

	return EXIT_SUCCESS;
}