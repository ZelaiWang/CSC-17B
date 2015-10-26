#include "pokerpushbutton.h"
#include "mainwindow.h"

/**
 * Reference to the function declaration
 * @brief PokerPushButton::PokerPushButton
 * @param parent
 */
PokerPushButton::PokerPushButton(QWidget* parent):QPushButton(parent)
{
    //Make the border transparent
    setFlat(true);

    //Tracking a mouse move event
    setMouseTracking(true);

    //Change the currsor symbol
    setCursor(QCursor(Qt::PointingHandCursor));

}



