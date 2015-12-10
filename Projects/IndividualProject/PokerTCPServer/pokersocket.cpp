#include "pokersocket.h"

/**
 * Reference to the function declaration
 * @brief PokerSocket::PokerSocket
 * @param parent
 */
PokerSocket::PokerSocket(QObject *parent)
    : QTcpSocket(parent)
{
    connect(this, SIGNAL(readyRead()), this, SLOT(readClient()));
    connect(this, SIGNAL(disconnected()), this, SLOT(deleteLater()));
}

/**
 * Reference to the function declaration
 * @brief PokerSocket::createConnection
 * @return
 */
PokerSocket::Connection PokerSocket::createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase(DEFAULT_DATABASE_TYPE);
    db.setHostName(DEFAULT_IPv4_ADRR);
    db.setDatabaseName(DEFAULT_DATABASE_NAME);
    db.setUserName(DEFAULT_DATABASE_NAME);
    db.setPassword(DEFAULT_PASSWORD);
    Connection connection;
    connection.db = db;
    if (!db.open()) {
        connection.connected = false;
        return connection;
    }
    connection.connected = true;

    return connection;
}

/**
 * Reference to the function declaration
 * @brief PokerSocket::readClient
 */
void PokerSocket::readClient()
{
    QDataStream in(this);

    //The player of the dealer
    QString object;

    //The final score
    QString score;

    in >> object >> score;

    //Saving the received data to the SQL server
    Connection connection = createConnection();
    if ( connection.connected ){
        QSqlQuery query;
        query.exec("INSERT INTO PokerGame (Object, Score)"
                   "VALUES ('" + object + "','" + score +"')");
        connection.db.close();

    }


    close();
}

