#ifndef INC_3_0_H
#define INC_3_0_H

#include "2.0.h"

#include <vector>
#include <random>
#include <algorithm>

/**
* @brief Libreia para que el deck (3.0.cpp) funcione correctamente.
*/

struct Deck {

    std::vector<Card> cards;

    Deck();

    void shuffle();

    Card draw();
};

#endif //INC_3_0_H
