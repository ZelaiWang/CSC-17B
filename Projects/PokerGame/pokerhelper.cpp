#include "pokerhelper.h"
#include <QDebug>
/**
 * Reference to the constant declaration
 * @brief PokerHelper::SER_CONF_FILE_NAME
 */
const QString PokerHelper::SER_CONF_FILE_NAME = ":/config.txt";

/**
 * Reference to the constant declaration
 * @brief PokerHelper::IP_V4_ADDR_REG_EXPRESS
 */
const QString PokerHelper::IP_V4_ADDR_REG_EXPRESS = "^([01]?\\d\\d?|2[0-4]\\d|25[0-5])\\.([01]?\\d\\d?|2[0-4]\\d|25[0-5])\\.([01]?\\d\\d?|2[0-4]\\d|25[0-5])\\.([01]?\\d\\d?|2[0-4]\\d|25[0-5])$";

/**
 * The default constructor
 * @brief PokerHelper::PokerHelper
 */
PokerHelper::PokerHelper()
{

}

/**
 * Reference to the function declaration
 * @brief PokerHelper::loadFile
 * @param fileName
 * @return
 */
QString PokerHelper::loadFile(QString fileName)
{
    QFile file(fileName);

    QString result;

    if (!file.open(QFile::ReadOnly | QFile::Text )){

        qDebug() << fileName << " cannot be loaded !!!" << endl;
        exit(1);

    }

    QTextStream txtStrm(&file);
    result = txtStrm.readAll();
    file.close();

    return result;
}

/**
 * Reference to the function declaration
 * @brief PokerHelper::validateIPv4Addr
 * @param ipAddr
 * @return
 */
bool PokerHelper::validateIPv4Addr(QString ipAddr)
{
    QRegularExpression regExpr(IP_V4_ADDR_REG_EXPRESS);

    if (regExpr.match(ipAddr).hasMatch()){
        return true;
    }

    return false;
}

