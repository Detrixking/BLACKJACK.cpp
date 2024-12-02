#include "2.0.h"

/**
* @brief Esta función da el valor de las cartas.
*
 * @code
 * switch (figure) {
        case Figure::TWO:
            value = 2;
 * @endcode
 *
 * @return El valor de la carta.
 */

Card::Card(Suite suite, Figure figure) : suite(suite), figure(figure) {
    switch (figure) {
        case Figure::TWO:
            value = 2;
        case Figure::THREE:
            value = 3;
        break;
        case Figure::FOUR:
            value = 4;
        break;
        case Figure::FIVE:
            value = 5;
        break;
        case Figure::SIX:
            value = 6;
        break;
        case Figure::SEVEN:
            value = 7;
        break;
        case Figure::EIGHT:
            value = 8;
        break;
        case Figure::NINE:
            value = 9;
        break;
        case Figure::TEN:
        case Figure::JACK:
        case Figure::QUEEN:
        case Figure::KING:
            value = 10;
        break;
        case Figure::ACE:
            value = 11;
        break;
    }
}

/**
* @brief Esta función da la figura de las cartas.
*
 * @code
 * switch (figure) {
        case Figure::JACK:
            cardDisplay = "J";
 * @endcode
 *
 * @return El valor de la figura de las cartas.
 */

std::string Card::getCard() const {
    std::string cardDisplay;
    switch (figure) {
        case Figure::JACK:
            cardDisplay = "J";
        break;
        case Figure::QUEEN:
            cardDisplay = "Q";
        break;
        case Figure::KING:
            cardDisplay = "K";
        break;
        case Figure::ACE:
            cardDisplay = "Ace";
        break;
        default:
            cardDisplay = std::to_string(value);
        break;
    }
    return cardDisplay + getSuiteDisplay();
}

/**
* @brief Esta función dice que tipo de carta es.
*
 * @code
 * switch (suite) {
        case Suite::HEARTS:
            suiteDisplay = "(C)";
 * @endcode
 *
 * @return El valor de la carta, en este caso dice que es un corazon.
 */

std::string Card::getSuiteDisplay() const {
    std::string suiteDisplay;
    switch (suite) {
        case Suite::HEARTS:
            suiteDisplay = "(C)";
        break;
        case Suite::DIAMONDS:
            suiteDisplay = "(D)";
        break;
        case Suite::CLUBS:
            suiteDisplay = "(T)";
        break;
        case Suite::SPADES:
            suiteDisplay = "(P)";
        break;
    }

    return suiteDisplay;
}