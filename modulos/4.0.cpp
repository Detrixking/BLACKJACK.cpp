#include "4.0.h"

/**
 * @brief Se indica como se inicia el Player.
 */

Player::Player(std::string name) : name(std::move(name)) {

    hand.reserve(2);
}

/**
 * @brief Añande cartas para el Player.
 */

void Player::addCard(Card card) {

    hand.push_back(card);
    score += card.value;
}

/**
 * @brief Muestra las cartas que el jugador tiene en su mano.
 */

void Player::showHand() const {

    std::string handStr = "La mano de " + name + " es: ";
    for (auto &card: hand) {
        handStr += card.getCard() + " ";
    }
    std::cout << handStr << std::endl;
}