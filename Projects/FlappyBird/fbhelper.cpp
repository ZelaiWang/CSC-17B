#include "fbhelper.h"

/**
 * @brief FBHelper::createConnection
 */
FBHelper::Connection FBHelper::createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("209.129.8.2");
    db.setDatabaseName("48941");
    db.setUserName("48941");
    db.setPassword("48941cis17b");
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
 * @brief FBHelper::FBHelper
 */
FBHelper::FBHelper()
{

}

/**
 * @brief FBHelper::save
 * @param userName
 * @param score
 * @return
 */
bool FBHelper::save(QString userName, int score)
{
    Connection connection = createConnection();
    if ( !connection.connected ){

        return false;
    }

    QSqlQuery query;
    query.exec("INSERT INTO FlappingBird (UserName, Score)"
               "VALUES ('" + userName + "','"+ QString::number(score) +"')");
    connection.db.close();
    return true;

}

