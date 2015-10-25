#include "uicontroller.h"

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

}

