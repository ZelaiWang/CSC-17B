#ifndef DIFFICULTYDIALOG_H
#define DIFFICULTYDIALOG_H

#include <QDialog>
#include <gamelevel.h>

namespace Ui {
class DifficultyDialog;
}

class DifficultyDialog : public QDialog
{
    Q_OBJECT

private:
    Ui::DifficultyDialog *ui;

public:
    explicit DifficultyDialog(QWidget *parent = 0);
    ~DifficultyDialog();

signals:

    void startGame();

private slots:
    void on_startButton_clicked();


};

#endif // DIFFICULTYDIALOG_H
