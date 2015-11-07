#pragma once
#include "qpainter.h"

class LettersDrawer
{
public:
	LettersDrawer(QPaintDevice* context);
	~LettersDrawer();

	void drawString(std::string str, int xBegin, int yBegin, int oneLetterWidth, int oneLetterHeight);
	void setXLineWidthCoeff(double newXLineWidthCoeff);
	void setYLineWidthCoeff(double newYLineWidthCoeff);
	void setDistance(int newDistance);
	int getDistance();
	void setColor(QColor newColor);
private:
	const double DEFAULT_LINE_WIDTH_COEFF_X = 0.05;
	const double DEFAULT_LINE_WIDTH_COEFF_Y = 0.05;
	const int DEFAULT_DISTANCE = 20;

	void drawCyrCapitalD(QPainter& painter, int x, int y, int width, int height);
	void drawCyrCapitalP(QPainter& painter, int x, int y, int width, int height);
	void drawCapitalC(QPainter& painter, int x, int y, int width, int height);

	void drawBorder(QPainter& painter, int x, int y, int width, int height);
	int degTo16(int sixteenthDegrees);
	double degToRad(int degrees);
	double radToDeg(double rad);

	QPaintDevice* m_context;
	QColor m_color;
	double m_XLineWidthCoeff = DEFAULT_LINE_WIDTH_COEFF_X;
	double m_YLineWidthCoeff = DEFAULT_LINE_WIDTH_COEFF_Y;
	int m_XLineWidth;
	int m_YLineWidth;
	int m_distance = DEFAULT_DISTANCE;
};

