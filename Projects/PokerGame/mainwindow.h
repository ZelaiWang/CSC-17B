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
    const QString SBI_FILE_NAME = ":/Images/PokerPlayIcon.gif";

    /*Path to the deal button icon image*/
    const QString DBI_FILE_NAME = ":/Images/PokerDIcon.gif";

    /*Main UI*/
    Ui::MainWindow *ui;

    /*The fundamental graphics scene of the game*/
    MainScene *mainScene;

    /*The play button*/
    PokerPushButton* playBtn = NULL;

    /*The play button*/
    PokerPushButton* dealBtn = NULL;

public:

    /*The primary constructor of this window*/
    explicit MainWindow(QWidget *parent = 0);

    /*Main window destructor*/
    ~MainWindow();

    /**
     * This function displays five poker cards on the scene
     * @brief displayCards
     */
    void displayCards(QVector<int> cardIds);

    /**
     * This function ask the main scene for the card Ids that need replacing
     * @brief getRCardIds
     * @return The Ids of cards need replacing
     */
    QVector<int> getRCardIds();

private:

    /**
     * This proceduced function creates a new start button
     * @brief getStartButton
     * @return
     */
    void addPlayButton();

    /**
     * This proceduced function creates a deal button
     * @brief getStartButton
     * @return
     */
    void addDealButton();

signals:

    /*This game-started signal is generated after the play button was clicked*/
    void startGame();

    /*This card-replaced signal is generated after the deal button was clicked*/
    void replaceCards();

public slots:

    /*This function handles the mouse clicked event from the play button*/
    void processPlayClicked();

    /*This function handles the mouse clicked event from the deal button*/
    void processDealClicked();
};

#endif // MAINWINDOW_H
