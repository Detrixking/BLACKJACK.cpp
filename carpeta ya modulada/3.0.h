//
// Created by santi on 13/11/2024.
//

#ifndef INC_3_0_H
#define INC_3_0_H

#include "2.0.h"

#include <vector>
#include <random>
#include <algorithm>

struct Deck {

    std::vector<Card> cards;

    Deck();

    void shuffle();

    Card draw();
};

#endif //INC_3_0_H
