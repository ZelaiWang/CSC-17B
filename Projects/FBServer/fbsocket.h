#ifndef FBSOCKET_H
#define FBSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>

class FBSocket : public QTcpSocket
{
    Q_OBJECT

public:
    /**
     * @brief FBSocket
     * @param parent
     */
    FBSocket(QObject *parent = 0);

private slots:
    /**
     * @brief readClient
     */
    void readClient();

signals:

public slots:
};

#endif // FBSOCKET_H
