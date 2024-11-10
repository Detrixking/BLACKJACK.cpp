//
// Created by santi on 13/11/2024.
//

#ifndef INC_5_0_H
#define INC_5_0_H

#include "4.0.h"
#include "3.0.h"
#include <string>
#include <iostream>

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
