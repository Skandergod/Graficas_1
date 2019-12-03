#pragma once

#include "Figure.h"

class CLine : public CFigure
{
	public:
		CLine();
		~CLine();
		void display();
		void drawLine(int x1, int y1, int x2, int y2, int color, int form);
		void case1(int x1, int y1, int x2, int y2, int color, int form);
		void case2(int x1, int y1, int x2, int y2, int color, int form);
		void case3(int x1, int y1, int x2, int y2, int color, int form);
		void case4(int x1, int y1, int x2, int y2, int color, int form);

};

