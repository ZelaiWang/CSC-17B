#ifndef POKERHELPER_H
#define POKERHELPER_H

#include <QFile>
#include <QTextStream>
#include <QRegularExpression>

class PokerHelper
{

public:

    /*
     * The top-left x position of the start button icon
     */
    static const int START_BUTTON_ICON_X = 400;

    /*
     * The top-left y position of the start button icon
     */
    static const int START_BUTTON_ICON_Y = 250;

    /*
     * The width of the start button icon
     */
    static const int START_BUTTON_ICON_W = 200;

    /*
     * The height of the start button icon
     */
    static const int START_BUTTON_ICON_H = 100;

    /*
     * The top-left x position of the deal button icon
     */
    static const int DEAL_BUTTON_ICON_X = 700;

    /*
     * The top-left y position of the deal button icon
     */
    static const int DEAL_BUTTON_ICON_Y = 40;

    /*
     * The width of the deal button icon
     */
    static const int DEAL_BUTTON_ICON_W = 180;

    /*
     * The height of the deal button icon
     */
    static const int DEAL_BUTTON_ICON_H = 80;

    /*
     * The server configuration file name
     */
    static const QString SER_CONF_FILE_NAME;

    /*
     * The regular expression of an IPv4 Address
     */
    static const QString IP_V4_ADDR_REG_EXPRESS;

public:
    /**
     * The default constructor
     * @brief PokerHelper
     */
    PokerHelper();

    /**
     * This function reads all the content in the fileName for a subject
     * @brief loadFile
     * @param fileName
     * @return the content in the fileName
     */
    static QString loadFile(QString fileName = SER_CONF_FILE_NAME);

    /**
     * This function use a regular expression to validate the input string contains a valid IPv4 Address
     * @brief validateIPv4Addr
     * @param ipAddr
     * @return true/false
     */
    static bool validateIPv4Addr(QString ipAddr);

};

#endif // POKERHELPER_H
