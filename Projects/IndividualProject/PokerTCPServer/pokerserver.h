#ifndef POKERSERVER_H
#define POKERSERVER_H

#include <QTcpServer>

/**
 * This class handles the incoming connections from Poker clients
 * @brief The PokerServer class
 */
class PokerServer : public QTcpServer
{
public:
    /**
     * The main constructor of this class
     * @brief PokerServer
     */
    PokerServer(QObject *parent = 0);

private:
    /**
     * Overriding the method of QTcpServer
     * @brief incomingConnection
     * @param socketId
     */
    void incomingConnection(int socketId);
};

#endif // POKERSERVER_H
