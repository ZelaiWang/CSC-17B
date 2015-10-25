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

}

/**
 * Reference to the function declaration
 * @brief MainWindow::~MainWindow
 */
MainWindow::~MainWindow()
{
    delete ui;
}
