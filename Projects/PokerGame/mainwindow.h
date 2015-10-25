#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <mainscene.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    /*The primary constructor of this window*/
    explicit MainWindow(QWidget *parent = 0);

    /*Main window destructor*/
    ~MainWindow();

private:

    /*Main UI*/
    Ui::MainWindow *ui;

    /*The fundamental graphics scene of the game*/
    MainScene *mainScene;

};

#endif // MAINWINDOW_H
