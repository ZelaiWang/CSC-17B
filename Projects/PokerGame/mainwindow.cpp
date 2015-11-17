#include "mainwindow.h"
#include "ui_mainwindow.h"

/**
 * Reference to the function declaration
 * @brief MainWindow::MainWindow
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Set a permanent size for this main window and its graphics view
    setFixedSize(geometry().width(),geometry().height());
    ui->graphicsView->setFixedSize(ui->graphicsView->geometry().width()
                                   ,ui->graphicsView->geometry().height());

    //Setting up the main scene in the graphics view of this window
    mainScene = new MainScene(this);
    mainScene->setSceneRect(ui->graphicsView->geometry().topLeft().x()
                            ,ui->graphicsView->geometry().topLeft().y()
                            ,ui->graphicsView->geometry().width()
                            ,ui->graphicsView->geometry().height());

    //Connect the main scene to a view
    ui->graphicsView->setScene(mainScene);

    //Place the Play button on the window
    addPlayButton();

}

/**
 * Reference to the function declaration
 * @brief MainWindow::~MainWindow
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * Reference to the function declaration
 * @brief MainWindow::displayCards
 */
void MainWindow::displayCards(QVector<int> cardIds)
{
    mainScene->displayCards(cardIds);
}

/**
 * Reference to the function declaration
 * @brief MainWindow::getRCardIds
 * @return
 */
QVector<int> MainWindow::getRCardIds()
{
    return mainScene->getRCardIds();
}


/**
 * Reference to the function declaration
 * @brief MainWindow::getStartButton
 * @return
 */
void MainWindow::addPlayButton()
{
    if (playBtn == NULL){

        playBtn = new PokerPushButton(SBI_FILE_NAME,this);

        //Setting up geometry attributes
        playBtn->setGeometry(QRect(PokerHelper::START_BUTTON_ICON_X,PokerHelper::START_BUTTON_ICON_Y,
                                   PokerHelper::START_BUTTON_ICON_W,PokerHelper::START_BUTTON_ICON_H));

        playBtn->setIconSize(QSize(PokerHelper::START_BUTTON_ICON_W,PokerHelper::START_BUTTON_ICON_H));

        //Register with the Play button to receive the mouse clicked event
        connect(playBtn, SIGNAL(clicked()),this, SLOT(processPlayClicked()));

    }

}

/**
 * Reference to the function declaration
 * @brief MainWindow::addDealButton
 */
void MainWindow::addDealButton()
{
    if (dealBtn == NULL){

        dealBtn = new PokerPushButton(DBI_FILE_NAME,this);

        //Setting up geometry attributes
        dealBtn->setGeometry(QRect(PokerHelper::DEAL_BUTTON_ICON_X,PokerHelper::DEAL_BUTTON_ICON_Y,
                                   PokerHelper::DEAL_BUTTON_ICON_W,PokerHelper::DEAL_BUTTON_ICON_H));

        dealBtn->setIconSize(QSize(PokerHelper::DEAL_BUTTON_ICON_W,PokerHelper::DEAL_BUTTON_ICON_H));

        //Display the button on this ui
        dealBtn->show();

        //Register with the Deal button to receive the mouse clicked event
        connect(dealBtn, SIGNAL(clicked()),this, SLOT(processDealClicked()));

    }
}

/**
 * Reference to the function declaration
 * @brief MainWindow::processPlayClicked
 */
void MainWindow::processPlayClicked()
{
    //Clean up the play button before starting the game
    playBtn->setVisible(false);
    disconnect(playBtn, SIGNAL(clicked()),this, SLOT(processPlayClicked()));
    delete playBtn;

    //Let the Deal button appear
    addDealButton();

    //Notify the UIController for a game-started signal
    emit startGame();

}

/**
 * Reference to the function declaration
 * @brief MainWindow::processDealClicked
 */
void MainWindow::processDealClicked()
{

    dealBtn->setDisabled(true);

    //Notify the UIController for a replace-card signal
    emit replaceCards();
}
