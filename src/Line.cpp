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
	
	GLint* b[2];
	for (int i = 0; i < 2; ++i) {
		b[i] = new GLint[2];
	}
	
	glColor3fv(mColor);

	b[0][0] = (int)mVertices[0][0];
	b[0][1] = (int)mVertices[0][1];
	b[1][0] = (int)mVertices[1][0];
	b[1][1] = (int)mVertices[1][1];

	drawLine(b[0][0], b[0][1], b[1][0], b[1][1], 0, 0);

}

void CLine::drawLine(int x1, int y1, int x2, int y2, int color, int form) {
	
	GLint* b[2];
	GLint dx, dy;
	for (int i = 0; i < 2; ++i) {
		b[i] = new GLint[2];
	}

	//glColor3f(0.0f,1.0f,0.0f);

	b[0][0] = x1;
	b[0][1] = y1;
	b[1][0] = x2;
	b[1][1] = y2;

	dx = b[1][0] - b[0][0];
	dy = b[1][1] - b[0][1];

	if (b[0][1] < b[1][1]) {

		if (dx >= 0) {
			if (dy <= dx) {
				case1(b[0][0], b[0][1], b[1][0], b[1][1], 0, 0);
			}
			else {
				case2(b[0][0], b[0][1], b[1][0], b[1][1], 0, 0);
			}
		}
		else {
			if (-dx <= dy) {
				case4(b[1][0], b[1][1], b[0][0], b[0][1], 0, 0);


			}
			else {
				case3(b[1][0], b[1][1], b[0][0], b[0][1], 0, 0);
			}
		}

	}
	else {

		if (dx >= 0) {
			if (dx <= -dy) {
				case4(b[0][0], b[0][1], b[1][0], b[1][1], 0, 0);
			}
			else {
				case3(b[0][0], b[0][1], b[1][0], b[1][1], 0, 0);
			}
		}
		else {
			if (-dx <= -dy) {
				case2(b[1][0], b[1][1], b[0][0], b[0][1], 0, 0);
			}
			else {
				case1(b[1][0], b[1][1], b[0][0], b[0][1], 0, 0);
			}
		}

	}
}

void CLine::case1(int x1, int y1,int x2,int y2, int color, int form) { //M En [0,1]

	int dx, dy, x0, y0, d, incrE, incrNE;

	dx = x2 - x1;
	dy = y2 - y1;

	d = dx - (dy << 1);
	incrE = -(dy << 1);
	incrNE = ((dx - dy) << 1);

	x0 = x1;
	y0 = y1;

	

	
	glBegin(GL_POINTS);
	
	//glColor3fv(mColor);
	
	glVertex2i(x1, y1);

	while (x0 < x2) {
		//std::cout << "hi" << std::endl;
		//Pintar noreste
		if (d <= 0) {
			d = d + incrNE;
			y0 = y0 + 1;
		}
		//Pintar este
		else {
			d = d + incrE;
		}
		x0 = x0 + 1;
		glVertex2i(x0, y0);
	}


	glVertex2i(x2, y2);
	glEnd();

}

void CLine::case2(int x1, int y1, int x2, int y2, int color, int form) { //M En [1,inf]

	int m, dx, dy, x0, y0, d, incrE, incrNE;

	dx = x2 - x1;
	dy = y2 - y1;

	//Funcion Inversa de la pendiente
	m = dy;
	dy = dx;
	dx = m;

	d = dx - (dy << 1);
	incrE = -(dy << 1);
	incrNE = ((dx - dy) << 1);

	x0 = x1;
	y0 = y1;




	glBegin(GL_POINTS);

	//glColor3fv(mColor);

	glVertex2i(x1, y1);

	while (y0 < y2) {
		//std::cout << "hi" << std::endl;
		//Pintar noreste
		if (d <= 0) {
			d = d + incrNE;
			x0 = x0 + 1;
		}
		//Pintar este
		else {
			d = d + incrE;
		}
		y0 = y0 + 1;
		glVertex2i(x0, y0);
	}


	glVertex2i(x2, y2);
	glEnd();

}

void CLine::case3(int x1, int y1, int x2, int y2, int color, int form) {//m en [-1,0]

	int dx, dy, x0, y0, d, incrE, incrNE;	

	dx = x2 - x1;
	dy = y2 - y1;

	d = dx + (dy << 1);
	incrE = (dy << 1);
	incrNE = ((dx + dy) << 1);

	x0 = x1;
	y0 = y1;




	glBegin(GL_POINTS);

	//glColor3fv(mColor);

	glVertex2i(x1, y1);

	while (x0 < x2) {
		//std::cout << "hi" << std::endl;
		//Pintar noreste
		if (d <= 0) {
			d = d + incrNE;
			y0 = y0 - 1;
		}
		//Pintar este
		else {
			d = d + incrE;
		}
		x0 = x0 + 1;
		glVertex2i(x0, y0);
	}


	glVertex2i(x2, y2);
	glEnd();


}

void CLine::case4(int x1, int y1, int x2, int y2, int color, int form) { //M En [-inf,-1]

	int m, dx, dy, x0, y0, d, incrE, incrNE;

	dx = x2 - x1;
	dy = y2 - y1;

	//Funcion Inversa de la pendiente
	m = dy;
	dy = dx;
	dx = m;

	d = -dx - (dy << 1);
	incrE = -(dy << 1);
	incrNE = ((-dx - dy) << 1);

	x0 = x1;
	y0 = y1;


	glBegin(GL_POINTS);

	//glColor3fv(mColor);

	glVertex2i(x1, y1);

	while (y2 < y0) {
		//std::cout << "hi" << std::endl;
		//Pintar noreste
		if (d <= 0) {
			d = d + incrNE;
			x0 = x0 + 1;
		}
		//Pintar este
		else {
			d = d + incrE;
		}
		y0 = y0 - 1;
		glVertex2i(x0, y0);
	}


	glVertex2i(x2, y2);
	glEnd();

}