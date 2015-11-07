#include "drawable.h"
#include "arc.h"


Drawable::Drawable()
{
}

Drawable::Drawable(QRect rect)
{
	wrap(rect);
}

Drawable::Drawable(Arc arc)
{
	wrap(arc);
}

Drawable::Drawable(QPolygon polygon)
{
	wrap(polygon);
}

Drawable::Drawable(QLine line)
{
	wrap(line);
}

Drawable::~Drawable()
{
}

void Drawable::draw(QPainter& painter)
{
	switch (m_wrappedItem)
	{
	case Drawable::RECT:
		draw(painter, m_wrappedRect);
		break;
	case Drawable::ARC:
		draw(painter, m_wrappedArc);
		break;
	case Drawable::POLYGON:
		draw(painter, m_wrappedPolygon);
		break;
	case Drawable::LINE:
		draw(painter, m_wrappedLine);
		break;
	case Drawable::NOTHING:
	default:
		break;
	}
}

void Drawable::wrap(QRect rect)
{
	if (m_wrappedItem != Items::NOTHING)
		throw std::logic_error("Already wrapped something");

	m_wrappedRect = rect;
	m_wrappedItem = Items::RECT;
}

void Drawable::wrap(Arc arc)
{
	if (m_wrappedItem != Items::NOTHING)
		throw std::logic_error("Already wrapped something");

	m_wrappedArc = arc;
	m_wrappedItem = Items::ARC;
}

void Drawable::wrap(QPolygon polygon)
{
	if (m_wrappedItem != Items::NOTHING)
		throw std::logic_error("Already wrapped something");

	m_wrappedPolygon = polygon;
	m_wrappedItem = Items::POLYGON;
}

void Drawable::wrap(QLine line)
{
	if (m_wrappedItem != Items::NOTHING)
		throw std::logic_error("Already wrapped something");

	m_wrappedLine = line;
	m_wrappedItem = Items::LINE;
}


void Drawable::draw(QPainter& painter, QRect drawable)
{
	painter.drawRect(drawable);
}

void Drawable::draw(QPainter& painter, Arc drawable)
{
	drawable.draw(painter);
}

void Drawable::draw(QPainter& painter, QPolygon drawable)
{
	painter.drawPolygon(drawable);
}

void Drawable::draw(QPainter& painter, QLine drawable)
{
	painter.drawLine(drawable);
}