#include "aboutdialog.h"
#include "ui_aboutdialog.h"
#define _USE_MATH_DEFINES
#include "math.h"
#include "qpainter.h"
#include "qpoint.h"
#include "qpen.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog),
	m_lettersDrawer(this)
{
    ui->setupUi(this);
	m_lettersDrawer.setXLineWidthCoeff(0.1);
	m_lettersDrawer.setYLineWidthCoeff(0.1);
}

AboutDialog::~AboutDialog()
{
    delete ui;
}

void AboutDialog::paintEvent(QPaintEvent *event)
{
	QFrame* lettersContainer = ui->lettersContainer;
	QRect geometry = lettersContainer->geometry();
	int x = geometry.x() + 30;
	int y = geometry.y();
	int lineHeight = geometry.height();
	int letterWidth = 100;

	m_lettersDrawer.setColor(Qt::GlobalColor::darkBlue);
	m_lettersDrawer.drawString("Ä", x, y, letterWidth, lineHeight);
	m_lettersDrawer.setColor(Qt::GlobalColor::darkGreen);
	m_lettersDrawer.drawString("Ï", x + letterWidth + m_lettersDrawer.getDistance(), y, letterWidth, lineHeight);
	m_lettersDrawer.setColor(Qt::GlobalColor::cyan);
	m_lettersDrawer.drawString("Ñ", x + 2 * (letterWidth + m_lettersDrawer.getDistance()), y, letterWidth, lineHeight);
}