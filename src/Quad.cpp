#include "Quad.h"

CQuad::CQuad()
{
	mVertices = new float*[2];
	for (int i = 0; i < 2; ++i)
		mVertices[i] = new float[2];

	mType = QUAD;
}

CQuad::~CQuad()
{
	for (int i = 0; i < 2; ++i)
		delete[] mVertices[i];
}

void CQuad::display()
{
	glColor3fv(mColor);
	GLint* b[2];
	int xMax, yMax, xMin, yMin;
	for (int i = 0; i < 2; ++i) {
		b[i] = new GLint[2];
	}

	glColor3fv(mColor);

	b[0][0] = (int)mVertices[0][0];
	b[0][1] = (int)mVertices[0][1];
	b[1][0] = (int)mVertices[1][0];
	b[1][1] = (int)mVertices[1][1];

	drawLine(b[0][0], b[0][1], b[1][0], b[0][1], 0, 0);
	drawLine(b[0][0], b[0][1], b[0][0], b[1][1], 0, 0);
	drawLine(b[1][0], b[0][1], b[1][0], b[1][1], 0, 0);
	drawLine(b[0][0], b[1][1], b[1][0], b[1][1], 0, 0);

	
	/*glBegin(GL_POLYGON);
	glVertex2fv(mVertices[0]);
	glVertex2f(mVertices[0][0], mVertices[1][1]);
	glVertex2fv(mVertices[1]);
	glVertex2f(mVertices[1][0], mVertices[0][1]);*/


	glEnd();
}