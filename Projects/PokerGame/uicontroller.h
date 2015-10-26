#ifndef UICONTROLLER_H
#define UICONTROLLER_H

#include <QObject>
#include <mainwindow.h>

/**
 * @brief The SceneController class
 * This is the primary controller of the GUI.
 * It controls all the behaviors on the main window and its scene
 */
class UIController : public QObject
{
    Q_OBJECT

private:

    /*The main window of Poker Game*/
    MainWindow *mainWindow;

public:

    /*The constructor of this main UI controller*/
    explicit UIController(QObject *parent = 0);

signals:



public slots:

    /*This function asks PokerCardTable to start a new game*/
    void startGame();
};

#endif // UICONTROLLER_H
