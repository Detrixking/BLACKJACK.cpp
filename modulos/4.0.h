#ifndef INC_4_0_H
#define INC_4_0_H

#include "2.0.h"
#include <string>
#include <vector>
#include <iostream>

/**
* @brief Libreia para que el Player (4.0.cpp) funcione correctamente.
*/

struct Player {

    std::string name;
    std::vector<Card> hand;
    int score = 0;

    explicit Player(std::string name);

    void addCard(Card card);

    void showHand() const;
};

#endif //INC_4_0_H
