#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QGraphicsScene>
#include <QtGui>

/**
 * @brief The MainScene class
 * This is the main graphics scene of the game
 * It is used to manage all the items (Cards and QPushButton) as well as the background
 */
class MainScene : public QGraphicsScene
{
private:

    /*Path to the back ground image*/
    const QString BG_FILE_NAME = ":/Images/PokerGameDesk.jpg";

    /*The Background Image Object*/
    QImage bgImage;

public:

    /**
     * The main constructor is uesed for initating all components in this scene
     */
    MainScene(QObject *parent = 0);

protected:
    /**
     * Overriding function from QGraphicsScene
     * This function will draw the background being one of three layers of the scene
     * @brief drawBackground
     * @param painter
     * @param rect
     */
    void drawBackground(QPainter *painter, const QRectF &rect);

private:

signals:

public slots:
};

#endif // MAINSCENE_H
