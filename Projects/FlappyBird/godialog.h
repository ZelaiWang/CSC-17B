#ifndef GODIALOG_H
#define GODIALOG_H

#include <QDialog>
#include "fbhelper.h"
#include <QDebug>

namespace Ui {
class GODialog;
}

/**
 * The game-over dialog
 */
class GODialog : public QDialog
{
    Q_OBJECT

private:
    Ui::GODialog *ui;

public:
    //The main constructor
    explicit GODialog(QWidget *parent = 0);

    //The main destructor
    ~GODialog();

    //This function pupolate the UI with the final score
    void populateUI(int score);

signals:

    //Start a new game
    void restart();

private slots:

    //Quit button handler
    void on_quitButton_clicked();

    //Restart button handler
    void on_restartButton_clicked();

    //Save and Restart button handler
    void on_sRestartButton_clicked();


};

#endif // GODIALOG_H
