#include "3.0.h"

using namespace std;

/**
* @brief Esto es el deck, indica cuantas cartas hay, de que tipo son, sus valores y donde se guardan.
*/

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

/**
* @brief Se mezclan las carta de forma aleatoria.
*/

void Deck::shuffle() {

    random_device rd;
    mt19937 g(rd());
    std::shuffle(cards.begin(), cards.end(), g);
}

/**
* @brief Aqui se decide que carta se robo de forma aleatoria.
* @code
* Card Deck::draw() {

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
* @endcode
*
* @return La carta.
*/

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