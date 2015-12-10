#include "fbsocket.h"
#include <QDataStream>

/**
 * @brief FBSocket::FBSocket
 * @param parent
 */
FBSocket::FBSocket(QObject *parent)
    : QTcpSocket(parent)
{
    connect(this, SIGNAL(readyRead()), this, SLOT(readClient()));
    connect(this, SIGNAL(disconnected()), this, SLOT(deleteLater()));
}

/**
 * @brief FBSocket::readClient
 */
void FBSocket::readClient()
{
    QDataStream in(this);

    QString name;

    QString score;

    in >> name >> score;

    qDebug() << name << score;

    close();
}
