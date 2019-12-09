#include "Figure.h"
#include <iostream>

CFigure::CFigure()
{
	mColor[0] =  1.0f;
	mColor[1] = mColor[2] = 0.f;
}

CFigure::~CFigure()
{
	delete[] mVertices;
}

void CFigure::setVertex(int id, float x, float y)
{
	mVertices[id][0] = x;
	mVertices[id][1] = y;
	nVer = id+1;
}

void CFigure::setColor(float r, float g, float b)
{
	mColor[0] = r;
	mColor[1] = g;
	mColor[2] = b;
}

int CFigure::getType()
{
	return mType;
}

float* CFigure::getVertex(int id)
{
	return mVertices[id];
}

float* CFigure::getColor()
{
	return mColor;
}

void CFigure::move(int x, int y) {

	for (int i = 0; i < nVer; i++) {
		mVertices[i][0] += x;
		//std::cout << "ax: " << mVertices[i][0] + x << std::endl;
		mVertices[i][1] += y;
		//std::cout << "ay: " << mVertices[i][1] + y << std::endl;
	}


};