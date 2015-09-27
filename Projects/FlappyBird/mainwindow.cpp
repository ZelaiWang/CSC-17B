#include "mainwindow.h"
#include "ui_mainwindow.h"

/*Reference to the function declaration*/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Set a permanent size for this main window and its graphics view
    setFixedSize(geometry().width(),geometry().height());
    ui->graphicsView->setFixedSize(ui->graphicsView->geometry().width()
                                   ,ui->graphicsView->geometry().height());

    //Setting up the main scene in this window
    mainScene = new MainScene(this);
    mainScene->setSceneRect(ui->graphicsView->geometry().topLeft().x()
                            ,ui->graphicsView->geometry().topLeft().y()
                            ,ui->graphicsView->geometry().width()
                            ,ui->graphicsView->geometry().height());

    ui->graphicsView->setScene(mainScene);

}

/*Reference to the function declaration*/
MainWindow::~MainWindow()
{
    delete ui;
}

/*Reference to the function declaration*/
void MainWindow::createFlowers()
{
    mainScene->createFlowers();
    //Make scene look smooth
    mainScene->update();
}

/*Reference to the function declaration*/
void MainWindow::moveFlowers()
{
    mainScene->moveFlowers();
    //Make scene look smooth
    mainScene->update();
}



