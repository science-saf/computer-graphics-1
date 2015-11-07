#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>

namespace Ui {
class AboutDialog;
}

class AboutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AboutDialog(QWidget *parent = 0);
    ~AboutDialog();
protected:
	void paintEvent(QPaintEvent *event);

private:
	void drawLetters();
	int calculateLetterYCoord(int initialYCoord, int phase = 0);
	Ui::AboutDialog *ui;
};

#endif // ABOUTDIALOG_H
