#include "lettersdrawer.h"
#define _USE_MATH_DEFINES
#include "math.h"
#include <exception>

LettersDrawer::LettersDrawer(QPaintDevice* context)
	: m_context(context)
{
}

LettersDrawer::~LettersDrawer()
{
}

void LettersDrawer::setXLineWidthCoeff(double newXLineWidthCoeff)
{
	m_XLineWidthCoeff = newXLineWidthCoeff;
}

void LettersDrawer::setYLineWidthCoeff(double newYLineWidthCoeff)
{
	m_YLineWidthCoeff = newYLineWidthCoeff;
}

void LettersDrawer::setDistance(int newDistance)
{
	m_distance = newDistance;
}

int LettersDrawer::getDistance()
{
	return m_distance;
}

void LettersDrawer::setColor(QColor newColor)
{
	m_color = newColor;
}

void LettersDrawer::drawString(std::string str, int xBegin, int y, int oneLetterWidth, int oneLetterHeight)
{
	QPainter painter(m_context);
	QBrush brush(m_color);
	brush.setStyle(Qt::BrushStyle::SolidPattern);
	painter.setBrush(brush);
	QPen pen(m_color);
	pen.setStyle(Qt::PenStyle::SolidLine);
	painter.setPen(pen);

	m_XLineWidth = std::round(oneLetterWidth * m_XLineWidthCoeff);
	m_YLineWidth = std::round(oneLetterHeight * m_YLineWidthCoeff);

	int nextLetterBegin = xBegin;
	for (int i = 0; i < str.length(); ++i)
	{
		switch (str[i])
		{
		case 'Ä':
			drawCyrCapitalD(painter, nextLetterBegin, y, oneLetterWidth, oneLetterHeight);
			break;
		case 'Ï':
			drawCyrCapitalP(painter, nextLetterBegin, y, oneLetterWidth, oneLetterHeight);
			break;
		case 'C':
		case 'Ñ':
			drawCapitalC(painter, nextLetterBegin, y, oneLetterWidth, oneLetterHeight);
			break;
		default:
			throw std::invalid_argument("Drawing this letter not implemented: " + str[i]);
			break;
		}
		nextLetterBegin += oneLetterWidth + m_distance;
	}
}

void LettersDrawer::drawCyrCapitalD(QPainter& painter, int x, int y, int width, int height)
{
	int topCenter = x + std::round(width / 2.0);

	const QPoint pointsArray1[] = {
		QPoint(topCenter, y),
		QPoint(x + std::round(0.25 * width), y + std::round(0.67 * height)),
		QPoint(x + std::round(0.25 * width) + m_XLineWidth, y + std::round(0.67 * height)),
		QPoint(topCenter, y + m_YLineWidth)
	};

	const QPoint pointsArray2[4] = {
		QPoint(topCenter, y),
		QPoint(topCenter, y + m_YLineWidth),
		QPoint(x + std::round(0.75 * width) - m_XLineWidth, y + std::round(0.67 * height)),
		QPoint(x + std::round(0.75 * width), y + std::round(0.67 * height))
	};

	const QPoint pointsArray3[4] = {
		QPoint(x, y + std::round(0.67 * height) + m_YLineWidth),
		QPoint(x + m_XLineWidth, y + height),
		QPoint(x + m_XLineWidth * 2, y + height),
		QPoint(x + m_XLineWidth, y + std::round(0.67 * height) + m_YLineWidth)
	};

	const QPoint pointsArray4[4] = {
		QPoint(x + width - m_XLineWidth, y + std::round(0.67 * height) + m_YLineWidth),
		QPoint(x + width - m_XLineWidth * 2, y + height),
		QPoint(x + width - m_XLineWidth, y + height),
		QPoint(x + width, y + std::round(0.67 * height) + m_YLineWidth),
	};

	painter.drawPolygon(pointsArray1, 4);
	painter.drawPolygon(pointsArray2, 4);
	painter.drawRect(x, y + std::round(0.67 * height), width, m_YLineWidth);
	painter.drawPolygon(pointsArray3, 4);
	painter.drawPolygon(pointsArray4, 4);
}

void LettersDrawer::drawCyrCapitalP(QPainter& painter, int x, int y, int width, int height)
{
	painter.drawRect(x, y, width, m_YLineWidth);
	painter.drawRect(x, y + m_YLineWidth, m_XLineWidth, height - m_YLineWidth);
	painter.drawRect(x + width - m_XLineWidth, y + m_YLineWidth, m_XLineWidth, height - m_YLineWidth);
}

void LettersDrawer::drawCapitalC(QPainter& painter, int x, int y, int width, int height)
{
	int lineWidth = std::round((m_XLineWidth + m_YLineWidth) / 2.0);

	QPen pen = painter.pen();
	pen.setWidth(lineWidth);
	painter.setPen(pen);
	painter.drawArc(x + std::round(lineWidth / 2.0), y + std::round(lineWidth / 2.0), width - 1 * lineWidth, height - 1 * lineWidth, degTo16(45), degTo16(270));
}

void LettersDrawer::drawBorder(QPainter& painter, int x, int y, int width, int height)
{
	painter.drawLine(x, y, x, y + height);
	painter.drawLine(x, y, x + width, y);
	painter.drawLine(x, y + height, x + width, y + height);
	painter.drawLine(x + width, y, x + width, y + height);
}

int LettersDrawer::degTo16(int sixteenthDegrees)
{
	return sixteenthDegrees * 16;
}

double LettersDrawer::degToRad(int degrees)
{
	return degrees * M_PI / 180;
}

double LettersDrawer::radToDeg(double rad)
{
	return rad * 180 / M_PI;
}