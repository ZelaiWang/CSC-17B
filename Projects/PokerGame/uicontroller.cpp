#include "uicontroller.h"
#include <QDebug>

/**
 * Reference to the function declaration
 * @brief UIController::UIController
 * @param parent
 */
UIController::UIController(QObject *parent) : QObject(parent)
{
    //Initialize the main window with its components
    mainWindow = new MainWindow();
    mainWindow->show();

    //Register with the mainWindow to receive a game-started signal
    connect(mainWindow,SIGNAL(startGame()),this, SLOT(startGame()));

}

/**
 * Reference to the function declaration
 * @brief UIController::startGame
 */
void UIController::startGame()
{

}

