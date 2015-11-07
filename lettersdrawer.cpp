#include "lettersdrawer.h"


LettersDrawer::LettersDrawer()
	: m_color(Qt::GlobalColor::black)
{
}


LettersDrawer::~LettersDrawer()
{
}

void LettersDrawer::setColor(QColor newColor)
{
	m_color = newColor;
}

void LettersDrawer::draw(QPainter& painter, Letter letter)
{
	QBrush oldBrush = painter.brush();
	QPen oldPen = painter.pen();
	QBrush brush(m_color, Qt::BrushStyle::SolidPattern);
	QPen pen(m_color, Qt::PenStyle::SolidLine);
	painter.setBrush(brush);
	painter.setPen(pen);
	letter.draw(painter);
	painter.setBrush(oldBrush);
	painter.setPen(oldPen);
}