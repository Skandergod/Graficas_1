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

	GLint* b[2], x, y, r, rx, ry;
	for (int i = 0; i < 2; ++i) {
		b[i] = new GLint[2];
	}

	glColor3fv(mColor);

	b[0][0] = (int)mVertices[0][0];
	b[0][1] = (int)mVertices[0][1];
	b[1][0] = (int)mVertices[1][0];
	b[1][1] = (int)mVertices[1][1];

	rx = mVertices[0][0] - mVertices[1][0];
	if(rx < 0){
		rx = rx * -1;
	}
	ry = mVertices[0][1] - mVertices[1][1];
	if (ry < 0) {
		ry = ry * -1;
	}

	r = rx;
	x = 0;
	y = r;
	drawCircle(b[0][0], b[0][1], x, y, r, 0);

}

void Ccircle::drawCircle(int x1, int y1, int x2, int y2, int r, int fill) {

	int d = 1 - r;

	if (fill) {

	}
	draw8points(x1, y1, x2, y2, fill);

	while (y2 > x2) {

		if (d < 0) {
			d = d + (x2 << 1) + 3;
		}
		else {
			d += ((x2 - y2) << 1) + 5;
			y2 = y2 - 1;
		}
		
		x2 = x2 + 1;
		draw8points(x1, y1, x2, y2, fill);
	}
	

}

void Ccircle::draw8points(int x1, int y1, int x2, int y2, int fill) {
	
	if (fill) {
		
	}

	glColor3f(0.0f,1.0f,0.0f);

	glBegin(GL_POINTS);
	glVertex2i(x1 + x2, y1 + y2);
	glVertex2i(x1 + x2, y1 - y2);
	glVertex2i(x1 - x2, y1 + y2);
	glVertex2i(x1 - x2, y1 - y2);
	glVertex2i(x1 + y2, y1 + x2);
	glVertex2i(x1 + y2, y1 - x2);
	glVertex2i(x1 - y2, y1 + x2);
	glVertex2i(x1 - y2, y1 - x2);
	glEnd();

}