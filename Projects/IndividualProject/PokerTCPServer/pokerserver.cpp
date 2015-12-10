#include "pokerserver.h"
#include "pokersocket.h"

/**
 * Reference to the function delaration
 * @brief PokerServer::PokerServer
 * @param parent
 */
PokerServer::PokerServer(QObject *parent)
    : QTcpServer(parent)
{

}

/**
 * Reference to the function delaration
 * @brief PokerServer::incomingConnection
 * @param socketId
 */
void PokerServer::incomingConnection(int socketId)
{
    PokerSocket *socket = new PokerSocket(this);
    socket->setSocketDescriptor(socketId);

}


