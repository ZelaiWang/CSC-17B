#include "PokerCardTable.h"
#include <time.h>
#include <QDebug>

/**
 * Reference to the declaration
 */
PokerCardTable::PokerCardTable() {

    //Seeding a value for the random function
    srand(time(NULL));

    //Dealing first five cards
    dealsCards();
}

/**
 * Reference to the declaration
 */
PokerCardTable::~PokerCardTable() {
    //Free all the allocated memories
    clean();
}

/**
 * Reference to the declaration
 * @brief PokerCardTable::getCrCardIds
 * @return
 */
QVector<int> PokerCardTable::getCrCardIds()
{
    QVector<int> result;

    for (int i = 0; i < crCards.size(); ++i) {
        result.append(crCards[i]->id);
    }

    return result;
}

/**
 * Reference to the declaration of this function
 * @brief PokerCardTable::replaceCards
 * @param repIds
 */
void PokerCardTable::replaceCards(QVector<int> repIds)
{
    /*
     * Create a copy of all current hand cards, because crCards will be used for
     * containing the first five cards and new cards for the replacement process.
     */
    QVector<Card*> bkCrCds(crCards);


    //Do actual replacements on bkCrCds
    //while use crCards to store all cards have been dealt
    for (int i = 0; i < repIds.size(); ++i) {
        bkCrCds[repIds[i]] = getNewCardForReplacement();
    }

    //Deallocate the memories of the replaced cards
    deleteCardsBy(crCards, repIds);

    //The replacement process is done and crCards show have a new combination of only five cards
    crCards = bkCrCds;

}

/**
 * Reference to the declaration
 * @param index
 * @return
 */
PokerCardTable::Card* PokerCardTable::populateCardBy(int id) {
    Card* card = new Card;
    card->id = id;
    card->suit = static_cast<CARD_SUITS> (id / RANKS_PER_SUIT);
    card->rank = static_cast<CARD_RANKS> (id % RANKS_PER_SUIT);
    return card;
}

/**
 * Reference to the declaration
 * @param index
 * @return
 */
bool PokerCardTable::isCardExistedBy(int id) {

    int size = crCards.size();

    for (int i = 0; i < size; i++) {

        if (id == crCards[i]->id) {
            return true;
        }
    }

    return false;
}

/**
 * Reference to the declaration
 * @param index
 * @return
 */
bool PokerCardTable::isCardInsertedBy(int id) {

    //Do not insert any existing card
    if (isCardExistedBy(id)) {
        return false;
    }

    //Insert a completely new card
    crCards.push_back(populateCardBy(id));
    return true;
}

/**
 * Reference to the declaration
 */
void PokerCardTable::dealsCards() {

    for (int i = 0; i < FIVE_POKER_CARDS; i++) {
        while (!isCardInsertedBy(rand() % CARDS_TOTAL));
    }

}

/**
 * Reference to the declaration
 */
PokerCardTable::Card* PokerCardTable::dealsNewCard() {

    int randId;

    do {
        randId = rand() % CARDS_TOTAL;
    } while (isCardExistedBy(randId));

    return populateCardBy(randId);

}

/**
 * Reference to the declaration
 * @param index
 */
PokerCardTable::Card* PokerCardTable::getNewCardForReplacement() {
    Card* newCard = dealsNewCard();

    //Collecting all cards that have been dealt to assure that there is no duplication happens
    crCards.push_back(newCard);

    return newCard;
}


/**
 * Reference to the declaration
 */
void PokerCardTable::sortCardsByRank() {

    QVector<Card*>::iterator cardIt;

    for (int i = 0; i < FIVE_POKER_CARDS; i++) {

        for (cardIt = crSRnks.begin(); (cardIt != crSRnks.end())
             && ((*cardIt)->rank < crCards[i]->rank); cardIt++);

        crSRnks.insert(cardIt, crCards[i]);
    }
}

/**
 * Reference to the declaration
 */
void PokerCardTable::sortCardsBySuit() {

    QVector<Card*>::iterator cardIt;

    for (int i = 0; i < FIVE_POKER_CARDS; i++) {

        for (cardIt = crSSuits.begin(); (cardIt != crSSuits.end())
             && ((*cardIt)->suit < crCards[i]->suit); cardIt++);

        crSSuits.insert(cardIt, crCards[i]);
    }
}

/**
 * Reference to the declaration
 * @return true/false
 */
bool PokerCardTable::isRoyalFlush() {
    return ((crSRnks[INDEX_0]->rank == ACE) && isStraightFlush());
}

/**
 * Reference to the declaration
 * @return true/false
 */
bool PokerCardTable::isStraightFlush() {
    return (isFlush() && isStraight());
}

/**
 * Reference to the declaration
 * @return true/false
 */
bool PokerCardTable::isFlush() {
    return (crSSuits[INDEX_0]->suit == crSSuits[INDEX_4]->suit);
}

/**
 * Reference to the declaration
 * @return true/false
 */
bool PokerCardTable::isStraight() {

    if (crSRnks[INDEX_0]->rank == ACE) { //Case 1 {ACE, TEN, JACK, QUEEN, KING}
        //or {ACE, TWO, THREE, FOUR, FIVE}

        if (crSRnks[INDEX_1]->rank == TEN && crSRnks[INDEX_2]->rank == JACK
                && crSRnks[INDEX_3]->rank == QUEEN && crSRnks[INDEX_4]->rank == KING) {
            return true;
        }

        if (crSRnks[INDEX_1]->rank == TWO && crSRnks[INDEX_2]->rank == THREE
                && crSRnks[INDEX_3]->rank == FOUR && crSRnks[INDEX_4]->rank == FIVE) {
            return true;
        }

        return false;

    } else {//Case 2 Continuously Increasing
        //rc: A rank counter
        for (int rc = (crSRnks[INDEX_0]->rank + 1), i = 1; i < FIVE_POKER_CARDS; rc++, i++) {
            if (rc != crSRnks[i]->rank) {
                return false;
            }
        }
        return true;
    }

}

/**
 * Reference to the declaration
 * @return true/false
 */
bool PokerCardTable::isFourOfAKind() {

    //Case: 4 + 1
    if ((crSRnks[INDEX_0]->rank == crSRnks[INDEX_1]->rank)
            && (crSRnks[INDEX_1]->rank == crSRnks[INDEX_2]->rank)
            && (crSRnks[INDEX_2]->rank == crSRnks[INDEX_3]->rank)) {
        return true;
    }

    //Case 1 + 4
    if ((crSRnks[INDEX_1]->rank == crSRnks[INDEX_2]->rank)
            && (crSRnks[INDEX_2]->rank == crSRnks[INDEX_3]->rank)
            && (crSRnks[INDEX_3]->rank == crSRnks[INDEX_4]->rank)) {
        return true;
    }

    return false;
}

/**
 * Reference to the declaration
 * @return true/false
 */
bool PokerCardTable::isFullHouse() {

    //Case 3 + 2
    if ((crSRnks[INDEX_0]->rank == crSRnks[INDEX_1]->rank)
            && (crSRnks[INDEX_1]->rank == crSRnks[INDEX_2]->rank)
            && (crSRnks[INDEX_3]->rank == crSRnks[INDEX_4]->rank)) {
        return true;
    }

    //Case 2 + 3
    if ((crSRnks[INDEX_0]->rank == crSRnks[INDEX_1]->rank)
            && (crSRnks[INDEX_2]->rank == crSRnks[INDEX_3]->rank)
            && (crSRnks[INDEX_3]->rank == crSRnks[INDEX_4]->rank)) {
        return true;
    }

    return false;
}

/**
 * Reference to the declaration
 * @return true/false
 */
bool PokerCardTable::isThreeOfAKind() {

    //Case 3 + 1 + 1
    if ((crSRnks[INDEX_0]->rank == crSRnks[INDEX_1]->rank)
            && (crSRnks[INDEX_1]->rank == crSRnks[INDEX_2]->rank)) {
        return true;
    }

    //Case 1 + 3 + 1
    if ((crSRnks[INDEX_1]->rank == crSRnks[INDEX_2]->rank)
            && (crSRnks[INDEX_2]->rank == crSRnks[INDEX_3]->rank)) {
        return true;
    }

    //Case 1 + 1 + 3
    if ((crSRnks[INDEX_2]->rank == crSRnks[INDEX_3]->rank)
            && (crSRnks[INDEX_3]->rank == crSRnks[INDEX_4]->rank)) {
        return true;
    }

    return false;
}

/**
 * Reference to the declaration
 * @return true/false
 */
bool PokerCardTable::isTwoPairs() {

    //Case 2 + 2 + 1
    if ((crSRnks[INDEX_0]->rank == crSRnks[INDEX_1]->rank)
            && (crSRnks[INDEX_2]->rank == crSRnks[INDEX_3]->rank)) {
        return true;
    }

    //Case 2 + 1 + 2
    if ((crSRnks[INDEX_0]->rank == crSRnks[INDEX_1]->rank)
            && (crSRnks[INDEX_3]->rank == crSRnks[INDEX_4]->rank)) {
        return true;
    }

    //Case 1 + 2 + 2
    if ((crSRnks[INDEX_1]->rank == crSRnks[INDEX_2]->rank)
            && (crSRnks[INDEX_3]->rank == crSRnks[INDEX_4]->rank)) {
        return true;
    }

    return false;
}

/**
 * Reference to the declaration
 * @return true/false
 */
bool PokerCardTable::isPair() {

    //Case: 2 + 1 + 1 + 1
    if (crSRnks[INDEX_0]->rank == crSRnks[INDEX_1]->rank) {
        return true;
    }

    //Case: 1 + 2 + 1 + 1
    if (crSRnks[INDEX_1]->rank == crSRnks[INDEX_2]->rank) {
        return true;
    }

    //Case: 1 + 1 + 2 + 1
    if (crSRnks[INDEX_2]->rank == crSRnks[INDEX_3]->rank) {
        return true;
    }

    //Case: 1 + 1 + 1 + 2
    if (crSRnks[INDEX_3]->rank == crSRnks[INDEX_4]->rank) {
        return true;
    }

    return false;
}

/**
 * Reference to the declaration
 * @return true/false: win/lose
 */
bool PokerCardTable::isPlayerWin() {

    //Sorting the current cards for checking a result
    sortCardsByRank();
    sortCardsBySuit();

    if (isRoyalFlush()) {
        qDebug() << "A Royal Flush!!!\n";

    } else if (isStraightFlush()) {
        qDebug() << "A Straight Flush!!\n";

    } else if (isFlush()) {
        qDebug() << "A Flush!\n";

    } else if (isStraight()) {
        qDebug() << "A Straight!\n";

    } else if (isFourOfAKind()) {
        qDebug() << "Four of the same kind!\n";

    } else if (isFullHouse()) {
        qDebug() << "Full house!\n";

    } else if (isThreeOfAKind()) {
        qDebug() << "Three of the same kind!\n";

    } else if (isTwoPairs()) {
        qDebug() << "Two pairs!\n";

    } else if (isPair()) {
        qDebug() << "A pair!\n";

    } else {
        qDebug() << "You lose !!!\n";
        return false;
    }

    qDebug() << "Congratulation! You are the winner !!!\n";
    return true;
}

/**
 * Reference to the declaration
 * @param cards : a vector of Card Structure pointers
 * @param poss : a vector of positions in cards
 */
void PokerCardTable::deleteCardsBy(QVector<Card*> cards, QVector<int> poss) {

    for (int i = 0; i < poss.size(); ++i) {
        delete cards[poss[i]];
    }

    poss.clear();
    cards.clear();
}

/**
 * Reference to the declaration
 * @param cards : a vector of Card Structure pointers
 */
void PokerCardTable::deleteCards(QVector<Card*> cards) {
    int size = cards.size();

    for (int i = 0; i < size; i++) {
        delete cards[i];
    }

    cards.clear();
}

/**
 * Reference to the declaration
 */
void PokerCardTable::clean() {

    //Clean up crCards for a new game
    deleteCards(crCards);

    //Both crSRnks and crSSuits reference to the same memories in crCards
    crSRnks.clear();
    crSSuits.clear();
}

