//
// Created by santi on 09/11/2024.
//

#ifndef CARD_H
#define CARD_H

#include "enums.h"
#include <string>

struct Card {
    int value;
    Suite suite;
    Figure figure;
    bool isTaken = false;

    explicit Card(Suite suite, Figure figure);

    [[nodiscard]] std::string getCard() const;

    [[nodiscard]] std::string getSuiteDisplay() const;
};

#endif //CARD_H
