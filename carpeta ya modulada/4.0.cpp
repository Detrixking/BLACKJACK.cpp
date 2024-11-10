//
// Created by santi on 13/11/2024.
//

#include "4.0.h"

Player::Player(std::string name) : name(std::move(name)) {

    hand.reserve(2);
}

void Player::addCard(Card card) {

    hand.push_back(card);
    score += card.value;
}

void Player::showHand() const {

    std::string handStr = "La mano de " + name + " es: ";
    for (auto &card: hand) {
        handStr += card.getCard() + " ";
    }
    std::cout << handStr << std::endl;
}