#ifndef INC_3_0_H
#define INC_3_0_H

#include "2.0.h"

#include <vector>
#include <random>
#include <algorithm>
#include <memory>

/**
* @brief Libreia para que el deck (3.0.cpp) funcione correctamente.
*/

/**
* @brief Libreia para que el deck (3.0.cpp) funcione correctamente.
*/

struct Deck {

    std::vector<std::unique_ptr<Card>> cards;

    Deck();

    void shuffle();

    std::unique_ptr<Card> draw();
};

#endif //INC_3_0_H
