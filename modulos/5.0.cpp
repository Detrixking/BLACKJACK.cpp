#include "5.0.h"
#include "3.0.h"

#include <string>
#include <iostream>

using namespace std;

/**
 * @brief Esta función inicia la partida.
 */

BlackJack::BlackJack() {

    deck.shuffle();
    player.addCard(deck.draw());
    player.addCard(deck.draw());
    dealer.addCard(deck.draw());
    dealer.addCard(deck.draw());
}

/**
 * @brief Muestra las manos de ambos jugadores.
 */

void BlackJack::showTable() const {

    player.showHand();
    dealer.showHand();
}

/**
 * @brief Indica el turno del Player.
 */

void BlackJack::playerTurn() {

}

/**
 * @brief Indica el turno del Dealer.
 */

void BlackJack::dealerTurn() {

}

/**
 * @brief Indica al ganador de la partida.
 *
 * @param Player.
 * @param Dealer.
 *
 * @code
* if (player.score > 21) {
        return Winner::DEALER;
    } else {
        if (player.score == 21) {
            return Winner::PLAYER;
 * @endcode
 *
 * @return Al ganador.
 */

[[nodiscard]] Winner BlackJack::getWinner() const {

    if (player.score > 21) {
        return Winner::DEALER;
    } else {
        if (player.score == 21) {
            return Winner::PLAYER;
        } else {
            if (player.score > dealer.score) {
                return Winner::PLAYER;
            } else if (player.score < dealer.score) {
                return Winner::DEALER;
            } else {
                return Winner::DRAW;
            }
        }
    }
}

/**
 * @brief Muestra el resultado del juego.
 */

void BlackJack::showWinner() const {

    string winner = "El ganador es: ";
    switch (getWinner()) {
        case Winner::PLAYER:
            winner += player.name;
        break;
        case Winner::DEALER:
            winner += dealer.name;
        break;
        case Winner::DRAW:
            winner += "Empate";
        break;
    }
    cout << winner << endl;
}