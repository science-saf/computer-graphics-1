#pragma once
#include "drawable.h"
class Letter
{
public:
	Letter();
	Letter(std::vector<Drawable> primitives);
	~Letter();

	void draw(QPainter& painter);

private:
	std::vector<Drawable> m_primitives;
};

