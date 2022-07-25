#pragma once

#include "../src/Line.h"

class CTriangle : public CFigure
{
	CLine lines[3];
	std::vector <std::pair <float, float>*> rectas[4];
	std::pair <float, float>* punto;

public:
	CTriangle();
	~CTriangle();
	void display();
	void drawTriangle(float** mVertices, int color, int form);
	void drawLine(int x1, int y1, int x2, int y2, int color, int id);
	void case1(int x1, int y1, int x2, int y2, int color, int form);
	void case2(int x1, int y1, int x2, int y2, int color, int form);
	void case3(int x1, int y1, int x2, int y2, int color, int form);
	void case4(int x1, int y1, int x2, int y2, int color, int form);
	
};
