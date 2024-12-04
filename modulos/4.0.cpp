#include "4.0.h"
#include <iostream>

using namespace std;

/**
 * @brief Se indica como se inicia el Player.
 */

Player::Player(string name, bool isDealer) : name(std::move(name)), isDealer(isDealer) {
    hand.reserve(2);
}

/**
 * @brief Añande cartas para el Player.
 */

void Player::addCard(unique_ptr<Card> card) {

    if(card == nullptr) {
        cerr << "Error: Attempted to add a null card to the hand." << endl;
        return;
    }if(!isDealer) {
        if (card->figure == Figure::ACE) {
            int option;
            cout << "Elige el valor del As: 1 u 11" << endl;
            cin >> option;
            while (option != 1 && option != 11) {
                cout << "Elige el valor del As: 1 u 11" << endl;
                cin >> option;
            }
            score += option;
        }else {
            score += card->value;
        }
    }
    else {
        score += card->value;
    }
    hand.push_back(std::move(card));
}

/**
 * @brief Muestra las cartas que el jugador tiene en su mano.
 */

void Player::showHand() const {

    std::string handStr = "La mano de " + name + " es: ";
    for (const auto &card: hand) {

        if(card != nullptr) {
            handStr += card->getCard() + "   ";

        }else {
            cerr << "Error: Null card in hand"<< endl;
        }
    }

    std::cout << handStr << std::endl;
}