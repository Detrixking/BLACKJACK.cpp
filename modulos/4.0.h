#ifndef INC_4_0_H
#define INC_4_0_H

#include "2.0.h"
#include <string>
#include <vector>
#include <iostream>
#include <memory>


/**
* @brief Libreia para que el Player (4.0.cpp) funcione correctamente.
*/

struct Player {

    std::string name;
    std::vector<std::unique_ptr<Card>> hand;
    int score = 0;
    bool isDealer{};

    explicit Player(std::string name);

    void addCard(std::unique_ptr<Card> card);

    void showHand() const;
};

#endif //INC_4_0_H
