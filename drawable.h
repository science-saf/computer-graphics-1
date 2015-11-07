#pragma once
#include "arc.h"
#include <QPainter>
#include <memory>

class Drawable
{
public:
	Drawable();
	Drawable(QRect rect);
	Drawable(Arc arc);
	Drawable(QPolygon polygon);
	Drawable(QLine line);

	void wrap(QRect rect);
	void wrap(Arc arc);
	void wrap(QPolygon polygon);
	void wrap(QLine line);

	void draw(QPainter& painter);
	~Drawable();
private:
	enum Items { NOTHING, RECT, ARC, POLYGON, LINE };

	void draw(QPainter& painter, QRect rect);
	void draw(QPainter& painter, Arc drawable);
	void draw(QPainter& painter, QPolygon drawable);
	void draw(QPainter& painter, QLine drawable);

	Items m_wrappedItem = Items::NOTHING;
	QRect m_wrappedRect;
	Arc m_wrappedArc;
	QPolygon m_wrappedPolygon;
	QLine m_wrappedLine;
};

