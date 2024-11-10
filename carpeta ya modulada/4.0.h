//
// Created by santi on 13/11/2024.
//

#ifndef INC_4_0_H
#define INC_4_0_H

#include "2.0.h"
#include <string>
#include <vector>
#include <iostream>

struct Player {

    std::string name;
    std::vector<Card> hand;
    int score = 0;

    explicit Player(std::string name);

    void addCard(Card card);

    void showHand() const;
};

#endif //INC_4_0_H
