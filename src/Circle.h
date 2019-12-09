#pragma once

#include "Figure.h"

class Ccircle : public CFigure {

public:
	Ccircle();
	~Ccircle();
	void display();
	void draw8points(int x1, int y1, int x2, int y2, int fill);
	void drawCircle(int x1, int y1, int x2, int y2, int r, int fill);
};