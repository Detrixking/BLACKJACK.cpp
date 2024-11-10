//
// Created by santi on 13/11/2024.
//

#include "3.0.h"

using namespace std;

Deck::Deck() {

    cards.reserve(52);
    for (int i = 0; i < 4; i++) {

        for (int j = 0; j < 13; j++) {

            auto suite = static_cast<Suite>(i);
            auto figure = static_cast<Figure>(j + 2);
            cards.emplace_back(suite, figure);
        }
    }
}

void Deck::shuffle() {

    random_device rd;
    mt19937 g(rd());
    std::shuffle(cards.begin(), cards.end(), g);
}

Card Deck::draw() {

    random_device rd;
    mt19937 g(rd());
    uniform_int_distribution<int> distribution(0, (int) cards.size() - 1);
    int index;
    Card card = cards[0];
    do {

        index = distribution(g);
        card = cards[index];
    } while (card.isTaken);
    card.isTaken = true;
    return card;
}