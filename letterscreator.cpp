#include "letterscreator.h"
#define _USE_MATH_DEFINES
#include "math.h"
#include "arc.h"
#include <vector>
#include "drawable.h"
#include "letter.h"

LettersCreator::LettersCreator()
{
}

LettersCreator::~LettersCreator()
{
}

void LettersCreator::setXLineWidthCoeff(double newXLineWidthCoeff)
{
	m_XLineWidthCoeff = newXLineWidthCoeff;
}

void LettersCreator::setYLineWidthCoeff(double newYLineWidthCoeff)
{
	m_YLineWidthCoeff = newYLineWidthCoeff;
}

void LettersCreator::setDistance(int newDistance)
{
	m_distance = newDistance;
}

int LettersCreator::getDistance()
{
	return m_distance;
}

std::vector<Letter> LettersCreator::createString(std::string str, int xBegin, int yBegin, int oneLetterWidth, int oneLetterHeight)
{
	int nextLetterBegin = xBegin;
	std::vector<Letter> result;
	for (int i = 0; i < str.length(); ++i)
	{
		result.push_back(createLetter(str[i], nextLetterBegin, yBegin, oneLetterWidth, oneLetterHeight));
		nextLetterBegin += oneLetterWidth + m_distance;
	}

	return result;
}

Letter LettersCreator::createLetter(char letter, int x, int y, int width, int height)
{
	m_XLineWidth = std::round(width * m_XLineWidthCoeff);
	m_YLineWidth = std::round(height * m_YLineWidthCoeff);

	Letter result;
	switch (letter)
	{
	case 'Ä':
		result = createCyrCapitalD(x, y, width, height);
		break;
	case 'Ï':
		result = createCyrCapitalP(x, y, width, height);
		break;
	case 'C':
	case 'Ñ':
		result = createCapitalC(x, y, width, height);
		break;
	default:
		throw std::invalid_argument("Drawing this letter not implemented: " + letter);
		break;
	}
	return result;
}

Letter LettersCreator::createCyrCapitalD(int x, int y, int width, int height)
{
	int topCenter = x + std::round(width / 2.0);

	QVector<QPoint> pointsArray1;
	pointsArray1.append(QPoint(topCenter, y));
	pointsArray1.append(QPoint(x + std::round(0.25 * width), y + std::round(0.67 * height)));
	pointsArray1.append(QPoint(x + std::round(0.25 * width) + m_XLineWidth, y + std::round(0.67 * height)));
	pointsArray1.append(QPoint(topCenter, y + m_YLineWidth));

	QVector<QPoint> pointsArray2;
	pointsArray2.append(QPoint(topCenter, y));
	pointsArray2.append(QPoint(topCenter, y + m_YLineWidth));
	pointsArray2.append(QPoint(x + std::round(0.75 * width) - m_XLineWidth, y + std::round(0.67 * height)));
	pointsArray2.append(QPoint(x + std::round(0.75 * width), y + std::round(0.67 * height)));

	QVector<QPoint> pointsArray3;
	pointsArray3.append(QPoint(x, y + std::round(0.67 * height) + m_YLineWidth));
	pointsArray3.append(QPoint(x + m_XLineWidth, y + height));
	pointsArray3.append(QPoint(x + m_XLineWidth * 2, y + height));
	pointsArray3.append(QPoint(x + m_XLineWidth, y + std::round(0.67 * height) + m_YLineWidth));

	QVector<QPoint> pointsArray4;
	pointsArray4.append(QPoint(x + width - m_XLineWidth, y + std::round(0.67 * height) + m_YLineWidth));
	pointsArray4.append(QPoint(x + width - m_XLineWidth * 2, y + height));
	pointsArray4.append(QPoint(x + width - m_XLineWidth, y + height));
	pointsArray4.append(QPoint(x + width, y + std::round(0.67 * height) + m_YLineWidth));
	

	QPolygon polygon1(pointsArray1);
	QPolygon polygon2(pointsArray2);
	QRect rect(x, y + std::round(0.67 * height), width, m_YLineWidth);
	QPolygon polygon3(pointsArray3);
	QPolygon polygon4(pointsArray4);

	std::vector<Drawable> primitives;
	primitives.push_back(Drawable(polygon1));
	primitives.push_back(Drawable(polygon2));
	primitives.push_back(Drawable(rect));
	primitives.push_back(Drawable(polygon3));
	primitives.push_back(Drawable(polygon4));

	return Letter(std::move(primitives));
}

Letter LettersCreator::createCyrCapitalP(int x, int y, int width, int height)
{
	QRect rect1(x, y, width, m_YLineWidth);
	QRect rect2(x, y + m_YLineWidth, m_XLineWidth, height - m_YLineWidth);
	QRect rect3(x + width - m_XLineWidth, y + m_YLineWidth, m_XLineWidth, height - m_YLineWidth);
	
	std::vector<Drawable> primitives;
	primitives.push_back(Drawable(rect1));
	primitives.push_back(Drawable(rect2));
	primitives.push_back(Drawable(rect3));

	return Letter(primitives);
}

Letter LettersCreator::createCapitalC(int x, int y, int width, int height)
{
	int lineWidth = std::round((m_XLineWidth + m_YLineWidth) / 2.0);
	std::vector<Drawable> primitives;
	Arc arc(x + std::round(lineWidth / 2.0), y + std::round(lineWidth / 2.0), width - 1 * lineWidth, height - 1 * lineWidth, degTo16(45), degTo16(270));
	arc.setLineWidth(lineWidth);
	Drawable wrappedArc(arc);
	primitives.push_back(wrappedArc);
	
	return Letter(primitives);
}

int LettersCreator::degTo16(int sixteenthDegrees)
{
	return sixteenthDegrees * 16;
}

double LettersCreator::degToRad(int degrees)
{
	return degrees * M_PI / 180;
}

double LettersCreator::radToDeg(double rad)
{
	return rad * 180 / M_PI;
}