#include "Circle.h"

Ccircle::Ccircle()
{
	mVertices = new float* [2];
	for (int i = 0; i < 2; ++i)
		mVertices[i] = new float[2];

	mType = CIRCLE;
}

Ccircle::~Ccircle()
{
	for (int i = 0; i < 2; ++i)
		delete[] mVertices[i];
}

void Ccircle::display()
{

	GLint* b[2];
	for (int i = 0; i < 2; ++i) {
		b[i] = new GLint[2];
	}

	glColor3fv(mColor);

	b[0][0] = (int)mVertices[0][0];
	b[0][1] = (int)mVertices[0][1];
	b[1][0] = (int)mVertices[1][0];
	b[1][1] = (int)mVertices[1][1];


}