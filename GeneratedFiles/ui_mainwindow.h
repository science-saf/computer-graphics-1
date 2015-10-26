/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>
#include "customtableview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *newDocument;
    QAction *saveDocument;
    QAction *openDocument;
    QAction *saveDocumentAs;
    QAction *showTable;
    QAction *showDiagram;
    QAction *actionAbout;
    QAction *actionInsertRow;
    QAction *actionDeleteRow;
    QWidget *centralWidget;
    CustomTableView *tableData;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menuAbout;
    QMenu *menuInsert;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 600));
        newDocument = new QAction(MainWindow);
        newDocument->setObjectName(QStringLiteral("newDocument"));
        saveDocument = new QAction(MainWindow);
        saveDocument->setObjectName(QStringLiteral("saveDocument"));
        openDocument = new QAction(MainWindow);
        openDocument->setObjectName(QStringLiteral("openDocument"));
        saveDocumentAs = new QAction(MainWindow);
        saveDocumentAs->setObjectName(QStringLiteral("saveDocumentAs"));
        showTable = new QAction(MainWindow);
        showTable->setObjectName(QStringLiteral("showTable"));
        showDiagram = new QAction(MainWindow);
        showDiagram->setObjectName(QStringLiteral("showDiagram"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionInsertRow = new QAction(MainWindow);
        actionInsertRow->setObjectName(QStringLiteral("actionInsertRow"));
        actionDeleteRow = new QAction(MainWindow);
        actionDeleteRow->setObjectName(QStringLiteral("actionDeleteRow"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tableData = new CustomTableView(centralWidget);
        tableData->setObjectName(QStringLiteral("tableData"));
        tableData->setGeometry(QRect(0, 0, 801, 581));
        tableData->setAlternatingRowColors(true);
        tableData->setSortingEnabled(true);
        tableData->horizontalHeader()->setDefaultSectionSize(250);
        tableData->horizontalHeader()->setMinimumSectionSize(150);
        tableData->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableData->horizontalHeader()->setStretchLastSection(true);
        tableData->verticalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableData->verticalHeader()->setStretchLastSection(false);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        menuInsert = new QMenu(menuBar);
        menuInsert->setObjectName(QStringLiteral("menuInsert"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menuInsert->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menu->addAction(newDocument);
        menu->addAction(saveDocument);
        menu->addAction(openDocument);
        menu->addAction(saveDocumentAs);
        menu_2->addAction(showTable);
        menu_2->addAction(showDiagram);
        menuAbout->addAction(actionAbout);
        menuInsert->addAction(actionInsertRow);
        menuInsert->addAction(actionDeleteRow);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Stats View", 0));
        newDocument->setText(QApplication::translate("MainWindow", "New Table", 0));
        saveDocument->setText(QApplication::translate("MainWindow", "Save", 0));
        openDocument->setText(QApplication::translate("MainWindow", "Open...", 0));
        saveDocumentAs->setText(QApplication::translate("MainWindow", "Save As...", 0));
        showTable->setText(QApplication::translate("MainWindow", "Table", 0));
        showDiagram->setText(QApplication::translate("MainWindow", "Diagram", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "About Application", 0));
        actionInsertRow->setText(QApplication::translate("MainWindow", "Insert Row", 0));
        actionDeleteRow->setText(QApplication::translate("MainWindow", "Delete Row", 0));
        menu->setTitle(QApplication::translate("MainWindow", "File", 0));
        menu_2->setTitle(QApplication::translate("MainWindow", "View", 0));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", 0));
        menuInsert->setTitle(QApplication::translate("MainWindow", "Insert", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
