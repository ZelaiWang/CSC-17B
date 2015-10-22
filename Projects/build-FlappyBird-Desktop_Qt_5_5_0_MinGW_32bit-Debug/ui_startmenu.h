/********************************************************************************
** Form generated from reading UI file 'startmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTMENU_H
#define UI_STARTMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartMenu
{
public:
    QLabel *titleLabel;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *difficultyLabel;
    QComboBox *difficultyComboBox;
    QPushButton *startButton;

    void setupUi(QDialog *StartMenu)
    {
        if (StartMenu->objectName().isEmpty())
            StartMenu->setObjectName(QStringLiteral("StartMenu"));
        StartMenu->resize(400, 300);
        titleLabel = new QLabel(StartMenu);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        titleLabel->setGeometry(QRect(100, 20, 191, 31));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(16);
        titleLabel->setFont(font);
        titleLabel->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget = new QWidget(StartMenu);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(70, 80, 241, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        difficultyLabel = new QLabel(horizontalLayoutWidget);
        difficultyLabel->setObjectName(QStringLiteral("difficultyLabel"));

        horizontalLayout->addWidget(difficultyLabel);

        difficultyComboBox = new QComboBox(horizontalLayoutWidget);
        difficultyComboBox->setObjectName(QStringLiteral("difficultyComboBox"));

        horizontalLayout->addWidget(difficultyComboBox);

        startButton = new QPushButton(StartMenu);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setGeometry(QRect(160, 240, 75, 23));

        retranslateUi(StartMenu);

        QMetaObject::connectSlotsByName(StartMenu);
    } // setupUi

    void retranslateUi(QDialog *StartMenu)
    {
        StartMenu->setWindowTitle(QApplication::translate("StartMenu", "Dialog", 0));
        titleLabel->setText(QApplication::translate("StartMenu", "Flappy Bird", 0));
        difficultyLabel->setText(QApplication::translate("StartMenu", "Difficulty:", 0));
        difficultyComboBox->setCurrentText(QString());
        startButton->setText(QApplication::translate("StartMenu", "Start Game", 0));
    } // retranslateUi

};

namespace Ui {
    class StartMenu: public Ui_StartMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTMENU_H
