/********************************************************************************
** Form generated from reading UI file 'insertrowdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERTROWDIALOG_H
#define UI_INSERTROWDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_InsertRowDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *editName;
    QSpinBox *editValue;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *InsertRowDialog)
    {
        if (InsertRowDialog->objectName().isEmpty())
            InsertRowDialog->setObjectName(QStringLiteral("InsertRowDialog"));
        InsertRowDialog->resize(400, 139);
        buttonBox = new QDialogButtonBox(InsertRowDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setEnabled(true);
        buttonBox->setGeometry(QRect(40, 90, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        editName = new QLineEdit(InsertRowDialog);
        editName->setObjectName(QStringLiteral("editName"));
        editName->setGeometry(QRect(60, 20, 321, 20));
        editName->setMaxLength(20);
        editValue = new QSpinBox(InsertRowDialog);
        editValue->setObjectName(QStringLiteral("editValue"));
        editValue->setGeometry(QRect(60, 50, 321, 22));
        editValue->setMaximum(9999);
        label = new QLabel(InsertRowDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 41, 21));
        label_2 = new QLabel(InsertRowDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 50, 41, 21));

        retranslateUi(InsertRowDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), InsertRowDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), InsertRowDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(InsertRowDialog);
    } // setupUi

    void retranslateUi(QDialog *InsertRowDialog)
    {
        InsertRowDialog->setWindowTitle(QApplication::translate("InsertRowDialog", "Insert Row", 0));
        label->setText(QApplication::translate("InsertRowDialog", "Name:", 0));
        label_2->setText(QApplication::translate("InsertRowDialog", "Value:", 0));
    } // retranslateUi

};

namespace Ui {
    class InsertRowDialog: public Ui_InsertRowDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERTROWDIALOG_H
