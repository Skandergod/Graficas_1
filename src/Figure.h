#pragma once

#include "../headers/glfw3.h"
#include <vector>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

enum FigureType
{
	NONE,
	LINE,
	QUAD,
	CIRCLE,
	TRIANGLE,
	ELIPSE
};

class CFigure
{
public:

	int minx, miny, maxx, maxy;
	float** mVertices, mColor[3];
	int mType;
	int nVer;

public:
	CFigure();
	virtual ~CFigure();
	void setVertex(int id, float x, float y);
	void setColor(float r, float g, float b);
	virtual void display() = 0;
	int getType();
	float* getVertex(int id);
	float* getColor();
	void move(int x, int y);
	bool picked;
	bool relleno;
	void setpicked(bool a);
	void setfill(bool a);
	void setMinAndMax();
};