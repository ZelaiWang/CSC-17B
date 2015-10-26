#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <mainscene.h>
#include <pokerpushbutton.h>
#include <pokerhelper.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:

    /*Path to the start button icon image*/
    const QString SBI_FILE_NAME = ":/Images/PokerPlayIcon.png";

    /*Main UI*/
    Ui::MainWindow *ui;

    /*The fundamental graphics scene of the game*/
    MainScene *mainScene;

    /*The play button*/
    PokerPushButton* playBtn = NULL;

public:

    /*The primary constructor of this window*/
    explicit MainWindow(QWidget *parent = 0);

    /*Main window destructor*/
    ~MainWindow();

private:

    /**
     * This proceduced function creates a new start button
     * @brief getStartButton
     * @return
     */
    void addPlayButton();

signals:

    /*This game-started signal is generated after the play button was clicked*/
    void startGame();

public slots:

    /*This function handles the mouse clicked event from the play button*/
    void processPlayClicked();
};

#endif // MAINWINDOW_H
