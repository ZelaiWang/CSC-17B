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

    //Register with the mainWindow to receive a card-replace signal
    connect(mainWindow,SIGNAL(replaceCards()),this, SLOT(replaceCards()));

    //Initialize the object that manage the logic of this game
    pokTble = new PokerCardTable();

}

/**
 * Reference to the function declaration
 * @brief UIController::startGame
 */
void UIController::startGame()
{
    mainWindow->displayCards(pokTble->getCrCardIds());
}

/**
 * Reference to the function declaration
 * @brief UIController::replaceCards
 */
void UIController::replaceCards()
{
    QVector<int> repIds = mainWindow->getRCardIds();

    if (!repIds.empty()){
        pokTble->replaceCards(repIds);
    }

    mainWindow->displayCards(pokTble->getCrCardIds());
}

