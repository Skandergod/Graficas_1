#include "Line.h"
#include <iostream>

CLine::CLine()
{
	mVertices = new float*[2];
	for (int i = 0; i < 2; ++i)
		mVertices[i] = new float[2];

	mType = LINE;
}

CLine::~CLine()
{
	for (int i = 0; i < 2; ++i)
		delete[] mVertices[i];
}

void CLine::display()
{
	glColor3fv(mColor);

	glBegin(GL_POINTS);
	GLfloat * a[1];
	for (int i = 0; i < 1; ++i) {
		a[i] = new GLfloat[1];
	}
	//mVertices[0][0] = x1, mVertices[0][1] = y1
	//mVertices[1][0] = x2, mVertices[0][1] = y1
	//std::cout << mVertices[1][0] << "," << mVertices[1][1] << std::endl;
		//glVertex2fv(mVertices[0]);
		//glVertex2fv(mVertices[1]);
	
		glVertex2fv(mVertices[0]);
	for (int i = mVertices[0][0]; i < mVertices[1][0]; i++) {
		mVertices[0][0] = mVertices[0][1];
		glVertex2fv(mVertices[1]);
	}
		glVertex2fv(mVertices[1]);
	glEnd();
}