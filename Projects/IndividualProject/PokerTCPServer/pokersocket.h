#ifndef POKERSOCKET_H
#define POKERSOCKET_H

#include <QSqlQuery>
#include <QSqlDatabase>
#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QDataStream>

/**
 * This class is used for communicating with Poker clients
 * @brief The PokerSocket class
 */
class PokerSocket : public QTcpSocket
{
    Q_OBJECT

private:

    /* A simple MySQL database connection*/
    typedef struct CONNECTION{
        QSqlDatabase db;
        bool connected;
    } Connection;

    /* The default database type of the MySQL server */
    const QString DEFAULT_DATABASE_TYPE = "QMYSQL";

    /* The default ipv4 address of the server*/
    const QString DEFAULT_IPv4_ADRR = "209.129.8.2";

    /* The default user name and database name that are used for accessing the server*/
    const QString DEFAULT_DATABASE_NAME = "48941";

    /* The default password that is used for accessing the server*/
    const QString DEFAULT_PASSWORD = "48941cis17b";

public:

    /**
     * The main constructor of this class
     * @brief PokerSocket
     * @param parent
     */
    PokerSocket(QObject *parent = 0);

private:

    /* This function tries connecting to the RCC's MySQL database server*/
    Connection createConnection();


private slots:
    /**
     * Reads the data being sent from the Poker client
     * @brief readClient
     */
    void readClient();


};

#endif // POKERSOCKET_H
