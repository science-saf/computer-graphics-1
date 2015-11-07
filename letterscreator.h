#pragma once
#include "letter.h"

class LettersCreator
{
public:
	LettersCreator();
	~LettersCreator();

	std::vector<Letter> createString(std::string str, int xBegin, int yBegin, int oneLetterWidth, int oneLetterHeight);
	Letter createLetter(char letter, int x, int y, int width, int height);
	void setXLineWidthCoeff(double newXLineWidthCoeff);
	void setYLineWidthCoeff(double newYLineWidthCoeff);
	void setDistance(int newDistance);
	int getDistance();
private:
	const double DEFAULT_LINE_WIDTH_COEFF_X = 0.05;
	const double DEFAULT_LINE_WIDTH_COEFF_Y = 0.05;
	const int DEFAULT_DISTANCE = 20;

	Letter createCyrCapitalD(int x, int y, int width, int height);
	Letter createCyrCapitalP(int x, int y, int width, int height);
	Letter createCapitalC(int x, int y, int width, int height);

	int degTo16(int sixteenthDegrees);
	double degToRad(int degrees);
	double radToDeg(double rad);

	double m_XLineWidthCoeff = DEFAULT_LINE_WIDTH_COEFF_X;
	double m_YLineWidthCoeff = DEFAULT_LINE_WIDTH_COEFF_Y;
	int m_XLineWidth;
	int m_YLineWidth;
	int m_distance = DEFAULT_DISTANCE;
};

