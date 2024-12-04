#ifndef INC_2_0_H
#define INC_2_0_H

#include "1.0.h"
#include <string>

/**
* @brief Esta Libreia es para que el 2.0.cpp funcione correctamente.
*/

struct Card {
    int value;
    Suite suite;
    Figure figure;
    bool isTaken = false;

    explicit Card(Suite suite, Figure figure);

    [[nodiscard]] std::string getCard() const;

    [[nodiscard]] std::string getSuiteDisplay() const;
};

#endif //INC_2_0_H
