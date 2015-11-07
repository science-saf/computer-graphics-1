#pragma once
#include "qcolor.h"
#include "letter.h"
class LettersDrawer
{
public:
	LettersDrawer();
	void setColor(QColor newColor);
	void draw(QPainter& painter, Letter letter);
	~LettersDrawer();
private:
	QColor m_color;
};

