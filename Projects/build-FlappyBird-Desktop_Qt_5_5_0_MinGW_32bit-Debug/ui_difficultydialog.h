/********************************************************************************
** Form generated from reading UI file 'difficultydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIFFICULTYDIALOG_H
#define UI_DIFFICULTYDIALOG_H

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

class Ui_DifficultyDialog
{
public:
    QLabel *titleLabel;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *difficultyLabel;
    QComboBox *dComboBox;
    QPushButton *startButton;

    void setupUi(QDialog *DifficultyDialog)
    {
        if (DifficultyDialog->objectName().isEmpty())
            DifficultyDialog->setObjectName(QStringLiteral("DifficultyDialog"));
        DifficultyDialog->resize(400, 225);
        titleLabel = new QLabel(DifficultyDialog);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        titleLabel->setGeometry(QRect(100, 20, 191, 31));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(16);
        titleLabel->setFont(font);
        titleLabel->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget = new QWidget(DifficultyDialog);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(70, 80, 241, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        difficultyLabel = new QLabel(horizontalLayoutWidget);
        difficultyLabel->setObjectName(QStringLiteral("difficultyLabel"));

        horizontalLayout->addWidget(difficultyLabel);

        dComboBox = new QComboBox(horizontalLayoutWidget);
        dComboBox->setObjectName(QStringLiteral("dComboBox"));

        horizontalLayout->addWidget(dComboBox);

        startButton = new QPushButton(DifficultyDialog);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setGeometry(QRect(150, 170, 75, 23));

        retranslateUi(DifficultyDialog);

        QMetaObject::connectSlotsByName(DifficultyDialog);
    } // setupUi

    void retranslateUi(QDialog *DifficultyDialog)
    {
        DifficultyDialog->setWindowTitle(QApplication::translate("DifficultyDialog", "Dialog", 0));
        titleLabel->setText(QApplication::translate("DifficultyDialog", "Flappy Bird", 0));
        difficultyLabel->setText(QApplication::translate("DifficultyDialog", "<html><head/><body><p align=\"center\">Difficulty:</p></body></html>", 0));
        dComboBox->setCurrentText(QString());
        startButton->setText(QApplication::translate("DifficultyDialog", "Start Game", 0));
    } // retranslateUi

};

namespace Ui {
    class DifficultyDialog: public Ui_DifficultyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIFFICULTYDIALOG_H
