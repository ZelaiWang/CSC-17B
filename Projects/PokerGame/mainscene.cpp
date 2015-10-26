#include "mainscene.h"

/**
 * Reference to the declaration of this constructor
 * @brief MainScene::MainScene
 * @param parent
 */
MainScene::MainScene(QObject *parent) : QGraphicsScene(parent)
{

    /*Loading a background picture into the equivalent image object*/
    bgImage.load(BG_FILE_NAME);

}

/**
 * Reference to the declaration of this function
 * @brief MainScene::drawBackground
 * @param painter
 * @param rect
 */
void MainScene::drawBackground(QPainter *painter, const QRectF &rect)
{
    //Only drawing background for the main scene
    painter->drawImage(sceneRect(),bgImage);
}




