#include "aboutdialog.h"
#include "ui_aboutdialog.h"
#define _USE_MATH_DEFINES
#include "math.h"
#include "qpainter.h"
#include "qpoint.h"
#include "qpen.h"
#include "letter.h"
#include "lettersdrawer.h"
#include "letterscreator.h"
#include <ctime>
#include <windows.h>

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
}

AboutDialog::~AboutDialog()
{
    delete ui;
}

void AboutDialog::paintEvent(QPaintEvent *event)
{
	drawLetters();
	update();
}

void AboutDialog::drawLetters()
{
	QPainter painter(this);
	QFrame* lettersContainer = ui->lettersContainer;
	QRect geometry = lettersContainer->geometry();
	const int margin = 30;
	const int letterWidth = 100;
	int x = geometry.x() + margin;
	int y = geometry.y();
	int lineHeight = geometry.height();

	LettersCreator lettersCreator;
	lettersCreator.setXLineWidthCoeff(0.15);
	lettersCreator.setYLineWidthCoeff(0.15);
	Letter d = lettersCreator.createLetter('Ä', x, calculateLetterYCoord(y, 0), letterWidth, lineHeight);
	Letter p = lettersCreator.createLetter('Ï', x + letterWidth + lettersCreator.getDistance(), calculateLetterYCoord(y, 1), letterWidth, lineHeight);
	Letter s = lettersCreator.createLetter('Ñ', x + 2 * (letterWidth + lettersCreator.getDistance()), calculateLetterYCoord(y, 2), letterWidth, lineHeight);

	LettersDrawer lettersDrawer;
	lettersDrawer.setColor(Qt::GlobalColor::darkBlue);
	lettersDrawer.draw(painter, d);
	lettersDrawer.setColor(Qt::GlobalColor::darkGreen);
	lettersDrawer.draw(painter, p);
	lettersDrawer.setColor(Qt::GlobalColor::cyan);
	lettersDrawer.draw(painter, s);
}

int AboutDialog::calculateLetterYCoord(int initialYCoord, int beginPhase)
{
	const int amplitude = 20;
	const double timeCoefficient = 0.01;
	const int phaseCoefficient = 100;

	SYSTEMTIME systime;
	GetSystemTime(&systime);
	int phase = std::round((systime.wSecond * 1000 + systime.wMilliseconds + beginPhase * phaseCoefficient) * timeCoefficient);

	return initialYCoord + std::round(amplitude * sin(phase));
}