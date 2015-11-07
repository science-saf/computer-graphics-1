#include "arc.h"

Arc::Arc()
{
}

Arc::Arc(int x, int y, int w, int h, int a, int alen)
	: m_x(x)
	, m_y(y)
	, m_w(w)
	, m_h(h)
	, m_a(a)
	, m_alen(alen)
{
}


Arc::~Arc()
{
}

void Arc::draw(QPainter& painter)
{
	QPen oldPen = painter.pen();
	QPen pen(oldPen);
	pen.setWidth(m_lineWidth);
	painter.setPen(pen);
	painter.drawArc(m_x, m_y, m_w, m_h, m_a, m_alen);
	painter.setPen(oldPen);
}

void Arc::setParams(int x, int y, int w, int h, int a, int alen)
{
	m_x = x;
	m_y = y;
	m_w = w;
	m_h = h;
	m_a = a;
	m_alen = alen;
}

void Arc::setLineWidth(int newLineWidth)
{
	m_lineWidth = newLineWidth;
}