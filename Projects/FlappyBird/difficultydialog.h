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

public:
    explicit DifficultyDialog(QWidget *parent = 0);
    ~DifficultyDialog();

private:
    Ui::DifficultyDialog *ui;
};

#endif // DIFFICULTYDIALOG_H
