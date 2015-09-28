#include "uicontroller.h"

/**
 *Reference to the function declaration
 * @brief UIController::createAFlower
 */
UIController::UIController(QObject *parent) : QObject(parent)
{
    //Initialize the main window with its components
    mainWindow = new MainWindow();
    mainWindow->show();

    //Seeding the value for a random
    qsrand(time(NULL));

    //Initializing all the timers
    cFlowerTimer = new QTimer(this);
    mFlowerTimer = new QTimer(this);
    gBirdTimer = new QTimer(this);

    //Connecting timer to the behaviors of flowers in the main scene
    connect(cFlowerTimer,SIGNAL(timeout()),this,SLOT(createFlowers()));
    connect(mFlowerTimer,SIGNAL(timeout()),mainWindow,SLOT(moveFlowers()));

    //Connecting timer to the behaviors of the bird
    connect(gBirdTimer,SIGNAL(timeout()),mainWindow,SLOT(freeFallBird()));

    //Getting connect to the key event of the main window
    connect(mainWindow,SIGNAL(pressSpaceKey()),this,SLOT(processSpaceKeyPress()));

    //Getting a notify from the main window for a collision
    connect(mainWindow,SIGNAL(processCollision()),this,SLOT(processCollision()));

    //Waiting for a user to start the game
    isGameStarted = false;
}

/**
 * Reference to the function declaration
 * @brief UIController::createNewFLowers
 */
void UIController::createFlowers()
{
    //Randomize the time for creating new flowers
    cFlowerTimer->stop();
    mainWindow->createFlowers();
    cFlowerTimer->start(MIN_TIME_IN_MIL + (qrand()%(MAX_TIME_IN_MIL - MIN_TIME_IN_MIL + 1)));
}

/**
 * Reference to the function declaration
 * @brief UIController::processKeyPress
 */
void UIController::processSpaceKeyPress()
{
    if (!isGameStarted){ //Starting the game at the first time

        isGameStarted = true;

        //Let flowers appear and move in the scene
        cFlowerTimer->start(MIN_TIME_IN_MIL);
        mFlowerTimer->start(FLOWER_DEFAULT_SPEED);

        //Let the bird free fall
        gBirdTimer->start(BIRD_FALLING_SPEED);

        //Put the bird in the right position to start the game
        mainWindow->play();

    }else { //Processing the bird movements

        //Stop free-fall for fly-up
        gBirdTimer->stop();
        mainWindow->flyUpBird();

        //Start free-fall again
        gBirdTimer->start(BIRD_FALLING_SPEED);
    }

}

/**
 * Reference to the function declaration
 * @brief UIController::processCollision
 */
void UIController::processCollision()
{
    qDebug() << "Controller got the collision signal !";
}



