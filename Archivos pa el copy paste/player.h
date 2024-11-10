
#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Player {
    string name;
    vector<Card> hand;
    int score = 0;

    explicit Player(string name);

    void addCard(Card card);

    void showHand() const;
};

#endif //PLAYER_H
