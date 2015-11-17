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

    //Prepare all poker card images for the game
    loadCardImages();

    //Prepare positions on the desk for the five poker cards
    assignCardSlots();

    //Setting up the exchanged area
    exArea = addRect(305,97,407,69, QPen(Qt::transparent), QBrush(Qt::transparent));
}

/**
 * Reference to the declaration of this constructor
 * @brief MainScene::displayCards
 */
void MainScene::displayCards(QVector<int> cardIds)
{
    for (int i = 0; i < cardIds.size(); ++i) {
        crdImgs[cardIds[i]]->setPos(crdPoss[i].x(),crdPoss[i].y());
        addItem(crdImgs[cardIds[i]]);
        crCrdIs.append(crdImgs[cardIds[i]]);
    }
}

/**
 * Reference to the declaration of this function
 * @brief MainScene::getRCardIds
 * @return
 */
QVector<int> MainScene::getRCardIds()
{
    QVector<int> result;

    for (int i = 0; i < crCrdIs.size(); ++i) {
        if (exArea->collidesWithItem(crCrdIs[i])){
            result.append(i);
        }
        removeItem(crCrdIs[i]);
    }
    crCrdIs.clear();

    return result;
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

/**
 * Reference to the declaration of this function
 * @brief MainScene::loadCardImages
 */
void MainScene::loadCardImages()
{
    //An intermediate image object that used for loading a picture
    QImage iImage;

    //The item will be displayed on the main scene
    QGraphicsPixmapItem* pixItem;

    //Loading all picture files of cards
    for (int i = 0; i < MAXIMUM_CARD_NUMBER; ++i) {
        iImage.load(CARD_FILE_NAME_PREFIX + QString::number(i) + CARD_FILE_NAME_SUFFIX);
        pixItem = new QGraphicsPixmapItem(QPixmap::fromImage(iImage));
        pixItem->setFlag(QGraphicsItem::ItemIsMovable);
        crdImgs.append(pixItem);
    }

}

/**
 * Reference to the declaration of this function
 * @brief MainScene::assignCardSlots
 */
void MainScene::assignCardSlots()
{
    //The postion of the first poker card
    crdPoss.append(QPoint(270,200));

    //The postion of the second poker card
    crdPoss.append(QPoint(370,250));

    //The postion of the third poker card
    crdPoss.append(QPoint(470,250));

    //The postion of the fourth poker card
    crdPoss.append(QPoint(570,250));

    //The postion of the fifth poker card
    crdPoss.append(QPoint(670,200));

}

