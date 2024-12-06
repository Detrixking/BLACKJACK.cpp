#ifndef INC_5_0_H
#define INC_5_0_H

#include "4.0.h"
#include "3.0.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Blackjack {
public:
    BlackJack();
    void showTable();
    void showWinner();
    void saveGame(const string& filename);
    void loadGame(const string& filename);

private:
    vector<string> playerNames;
};

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
