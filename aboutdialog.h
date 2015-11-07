#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>
#include <QFrame>
#include "lettersdrawer.h"

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
	LettersDrawer m_lettersDrawer;

    Ui::AboutDialog *ui;
};

#endif // ABOUTDIALOG_H
