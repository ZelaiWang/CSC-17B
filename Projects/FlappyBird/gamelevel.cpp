#include "gamelevel.h"

/**
 * Reference to the function declaration
 * @brief GameLevel::EASY
 */
GameLevel const GameLevel::EASY("Easy", 0);

/**
 * @brief GameLevel::MEDIUM
 */
GameLevel const GameLevel::MEDIUM("Medium", 1);

/**
 * @brief GameLevel::HARD
 */
GameLevel const GameLevel::HARD("Hard", 2);

/**
 * The singleton object
 * @brief GameLevel::gLevel
 */
GameLevel GameLevel::gLevel;

/*Reference to the constant declaration*/
GameLevel const GameLevel::levels[] = { EASY, MEDIUM, HARD};

/*Reference to the constant declaration*/
const float GameLevel::BIRD_PIC_SCALARS[] = {0.15, 0.16, 0.17};

/*Reference to the constant declaration*/
const int GameLevel::FLOWER_SPEEDS[] = {15, 12, 10};

/**
 * @brief GameLevel::getLevelN
 * @return
 */
QString GameLevel::getLevelN() const
{
    return levelN;
}

/**
 * @brief GameLevel::setLevelN
 * @param value
 */
void GameLevel::setLevelN(const QString &value)
{

    for (int i = 0; i < NUMBER_OF_LEVEL; ++i) {
        if (value == levels[i].levelN){
            this->levelN = value;
            this->id = levels[i].id;
            return;
        }
    }

}

/**
 * @brief GameLevel::getId
 * @return
 */
int GameLevel::getId() const
{
    return id;
}

/**
 * @brief GameLevel::setId
 * @param value
 */
void GameLevel::setId(int value)
{

    for (int i = 0; i < NUMBER_OF_LEVEL; ++i) {
        if (value == levels[i].id){
            this->levelN = levels[i].levelN;
            this->id = value;
            return;
        }
    }

}

/**
 * The singleton method
 * @brief GameLevel::getGLevel
 * @return
 */
GameLevel GameLevel::getInstance()
{
    return gLevel;
}

/**
 * Reference to the function declaration
 * @brief GameLevel::GameLevel
 * @param levelN
 * @param id
 */
GameLevel::GameLevel(QString levelN, int id)
{
    this->levelN = levelN;
    this->id = id;
}

