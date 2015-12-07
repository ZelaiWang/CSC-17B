#ifndef FBHELPER_H
#define FBHELPER_H

#include <QSql>
#include <QSqlQuery>
#include <QSqlDatabase>

/*The Flapping Bird Helper class*/
class FBHelper
{

private:
    /* A simple MySQL database connection*/
    typedef struct CONNECTION{
        QSqlDatabase db;
        bool connected;
    } Connection;

private:

    /* This function tries connecting to the RCC's MySQL database server*/
    static Connection createConnection();

public:
    /*The default constructor*/
    FBHelper();

    /* Save a record the database*/
    static bool save(QString userName, int score);

};

#endif // FBHELPER_H
