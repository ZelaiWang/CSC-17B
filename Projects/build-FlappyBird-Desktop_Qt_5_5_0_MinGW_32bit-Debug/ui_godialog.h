/********************************************************************************
** Form generated from reading UI file 'godialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GODIALOG_H
#define UI_GODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_GODialog
{
public:
    QLabel *gameOverLabel;
    QLineEdit *nameLineEdit;
    QLabel *nameLabel;
    QLabel *scoreLabel;
    QLCDNumber *scoreDisplay;
    QPushButton *quitButton;
    QPushButton *sRestartButton;
    QPushButton *restartButton;

    void setupUi(QDialog *GODialog)
    {
        if (GODialog->objectName().isEmpty())
            GODialog->setObjectName(QStringLiteral("GODialog"));
        GODialog->resize(400, 242);
        gameOverLabel = new QLabel(GODialog);
        gameOverLabel->setObjectName(QStringLiteral("gameOverLabel"));
        gameOverLabel->setGeometry(QRect(160, 40, 91, 16));
        nameLineEdit = new QLineEdit(GODialog);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));
        nameLineEdit->setGeometry(QRect(170, 140, 113, 20));
        nameLabel = new QLabel(GODialog);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setGeometry(QRect(80, 140, 47, 13));
        scoreLabel = new QLabel(GODialog);
        scoreLabel->setObjectName(QStringLiteral("scoreLabel"));
        scoreLabel->setGeometry(QRect(80, 80, 47, 13));
        scoreDisplay = new QLCDNumber(GODialog);
        scoreDisplay->setObjectName(QStringLiteral("scoreDisplay"));
        scoreDisplay->setGeometry(QRect(190, 70, 64, 23));
        quitButton = new QPushButton(GODialog);
        quitButton->setObjectName(QStringLiteral("quitButton"));
        quitButton->setGeometry(QRect(274, 200, 71, 23));
        sRestartButton = new QPushButton(GODialog);
        sRestartButton->setObjectName(QStringLiteral("sRestartButton"));
        sRestartButton->setGeometry(QRect(90, 200, 81, 23));
        restartButton = new QPushButton(GODialog);
        restartButton->setObjectName(QStringLiteral("restartButton"));
        restartButton->setGeometry(QRect(190, 200, 71, 23));

        retranslateUi(GODialog);

        QMetaObject::connectSlotsByName(GODialog);
    } // setupUi

    void retranslateUi(QDialog *GODialog)
    {
        GODialog->setWindowTitle(QApplication::translate("GODialog", "EndMenu", 0));
        gameOverLabel->setText(QApplication::translate("GODialog", "Game Over", 0));
        nameLabel->setText(QApplication::translate("GODialog", "Name", 0));
        scoreLabel->setText(QApplication::translate("GODialog", "Score", 0));
        quitButton->setText(QApplication::translate("GODialog", "Quit", 0));
        sRestartButton->setText(QApplication::translate("GODialog", "Save && Restart", 0));
        restartButton->setText(QApplication::translate("GODialog", "Restart", 0));
    } // retranslateUi

};

namespace Ui {
    class GODialog: public Ui_GODialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GODIALOG_H
