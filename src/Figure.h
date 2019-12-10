#pragma once

#include "../headers/glfw3.h"

enum FigureType
{
	NONE,
	LINE,
	QUAD,
	CIRCLE
};

class CFigure
{
protected:
	float **mVertices, mColor[3];
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
};