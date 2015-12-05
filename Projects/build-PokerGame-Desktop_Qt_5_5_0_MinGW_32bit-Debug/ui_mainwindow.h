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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_Game;
    QAction *actionSave;
    QAction *actionLoad_Game;
    QAction *actionExit;
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QLabel *bkLabel;
    QLabel *betLabel;
    QLCDNumber *bkLCD;
    QLCDNumber *betLCD;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuGame;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1000, 600);
        MainWindow->setMaximumSize(QSize(1000, 600));
        actionNew_Game = new QAction(MainWindow);
        actionNew_Game->setObjectName(QStringLiteral("actionNew_Game"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionLoad_Game = new QAction(MainWindow);
        actionLoad_Game->setObjectName(QStringLiteral("actionLoad_Game"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(22, 10, 950, 570));
        graphicsView->setMaximumSize(QSize(950, 570));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        bkLabel = new QLabel(centralWidget);
        bkLabel->setObjectName(QStringLiteral("bkLabel"));
        bkLabel->setGeometry(QRect(90, 150, 91, 20));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(14);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        bkLabel->setFont(font);
        bkLabel->setScaledContents(false);
        betLabel = new QLabel(centralWidget);
        betLabel->setObjectName(QStringLiteral("betLabel"));
        betLabel->setGeometry(QRect(90, 180, 101, 20));
        betLabel->setFont(font);
        bkLCD = new QLCDNumber(centralWidget);
        bkLCD->setObjectName(QStringLiteral("bkLCD"));
        bkLCD->setGeometry(QRect(214, 150, 64, 23));
        betLCD = new QLCDNumber(centralWidget);
        betLCD->setObjectName(QStringLiteral("betLCD"));
        betLCD->setGeometry(QRect(214, 180, 64, 23));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 21));
        menuGame = new QMenu(menuBar);
        menuGame->setObjectName(QStringLiteral("menuGame"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuGame->menuAction());
        menuGame->addAction(actionNew_Game);
        menuGame->addAction(actionSave);
        menuGame->addAction(actionLoad_Game);
        menuGame->addSeparator();
        menuGame->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "PokerGame", 0));
        actionNew_Game->setText(QApplication::translate("MainWindow", "New Game", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save Bank Roll", 0));
        actionLoad_Game->setText(QApplication::translate("MainWindow", "Load Bank Roll", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        bkLabel->setText(QApplication::translate("MainWindow", "BankRoll:", 0));
        betLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p>Bet:</p></body></html>", 0));
        menuGame->setTitle(QApplication::translate("MainWindow", "Game", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
