#ifndef INC_5_0_H
#define INC_5_0_H

#include "4.0.h"
#include "3.0.h"
#include <string>
#include <iostream>

/**
* @brief Libreia para que el juego (5.0.cpp) funcione correctamente.
*/

struct BlackJack {

    Player player = Player("Jugador");
    Player dealer = Player("Dealer");
    Deck deck;

    BlackJack();

    void showTable() const;

    void playerTurn();

    void dealerTurn();

    [[nodiscard]] Winner getWinner() const;

    void showWinner() const;
};

#endif //INC_5_0_H
