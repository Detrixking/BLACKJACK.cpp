
#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "deck.h"
#include "player.h"
#include <string>
#include <iostream>

struct Blackjack {
    Player player = Player("Jugador");
    Player dealer = Player("Croupier");
    Deck deck;

    Blackjack();

    void showTable() const;

    void playerTurn();

    void dealerTurn();

    [[nodiscard]] Winner getWinner() const;

    void showWinner() const;
};

#endif //BLACKJACK_H
