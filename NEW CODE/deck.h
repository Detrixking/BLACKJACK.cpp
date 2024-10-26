
#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <vector>
#include <random>
#include <algorithm>

struct Deck {
    std::vector<Card> cards;

    Deck();

    void shuffle();

    Card draw();
};

#endif //DECK_H
