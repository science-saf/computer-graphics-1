#pragma once
#include "qpainter.h"
class Arc
{
public:
	Arc();
	Arc(int x, int y, int w, int h, int a, int alen);
	~Arc();

	void draw(QPainter& painter);
	void setParams(int x, int y, int w, int h, int a, int alen);
	void setLineWidth(int newLineWidth);
private:
	int m_x;
	int m_y;
	int m_w;
	int m_h;
	int m_a;
	int m_alen;

	int m_lineWidth;
};

