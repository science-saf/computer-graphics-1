#include "letter.h"


Letter::Letter()
{
}

Letter::Letter(std::vector<Drawable> primitives)
	: m_primitives(primitives)
{
	m_primitives = primitives;
}

Letter::~Letter()
{
}

void Letter::draw(QPainter& painter)
{
	std::vector<Drawable>::iterator it = m_primitives.begin();
	for (; it != m_primitives.end(); ++it)
	{
		it->draw(painter);
	}
}
