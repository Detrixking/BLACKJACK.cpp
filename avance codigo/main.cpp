#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

enum class Suite {
    Corazones,
    Diamantes,
    Treboles,
    Picas
};

enum class Figure {
    Dos = 2,
    Tres = 3,
    Cuatro = 4,
    Cinco = 5,
    Seis = 6,
    Siete = 7,
    Ocho = 8,
    Nueve = 9,
    Diez = 10,
    J = 10,
    Q = 10,
    K = 10,
    As = 1
};

class Card {
public:
    Suite suite;
    Figure figure;

    Card(Suite s, Figure f) : suite(s), figure(f) {}

    int getValue() const {
        return static_cast<int>(figure);
    }
};

class Deck {
private:
    vector<Card> cards;

public:
    Deck() {
        for (int s = 0; s < 4; s++) {

            cards.emplace_back(static_cast<Suite>(s), Figure::Dos);
            cards.emplace_back(static_cast<Suite>(s), Figure::Tres);
            cards.emplace_back(static_cast<Suite>(s), Figure::Cuatro);
            cards.emplace_back(static_cast<Suite>(s), Figure::Cinco);
            cards.emplace_back(static_cast<Suite>(s), Figure::Seis);
            cards.emplace_back(static_cast<Suite>(s), Figure::Siete);
            cards.emplace_back(static_cast<Suite>(s), Figure::Ocho);
            cards.emplace_back(static_cast<Suite>(s), Figure::Nueve);
            cards.emplace_back(static_cast<Suite>(s), Figure::Diez);
            cards.emplace_back(static_cast<Suite>(s), Figure::J);
            cards.emplace_back(static_cast<Suite>(s), Figure::Q);
            cards.emplace_back(static_cast<Suite>(s), Figure::K);
            cards.emplace_back(static_cast<Suite>(s), Figure::As);
        }
        shuffleDeck();
    }

    void shuffleDeck() {
        random_device rd;
        mt19937 g(rd());
        std::shuffle(cards.begin(), cards.end(), g);
    }

    Card drawCard() {
        Card card = cards.back();
        cards.pop_back();
        return card;
    }

    bool isEmpty() const {
        return cards.empty();
    }
};

class Player {
public:
    string name;
    vector<Card> hand;

    Player(string n) : name(n) {}

    void addCard(const Card& card) {
        hand.push_back(card);
    }

    int getTotal() const {
        int total = 0;
        int acesCount = 0;
        for (const auto& card : hand) {
            total += card.getValue();
            if (card.figure == Figure::As) {
                acesCount++;
            }
        }

        while (total > 21 && acesCount > 0) {
            total -= 10;
            acesCount--;
        }
        return total;
    }
};

class Blackjack {
private:
    Deck deck;
    Player player;
    Player dealer;

public:
    Blackjack() : player("Jugador"), dealer("Dealer") {}

    void initGame() {
        for (int i = 0; i < 2; i++) {
            player.addCard(deck.drawCard());
            dealer.addCard(deck.drawCard());
        }
    }

    void displayHands() {
        cout << "Las cartas del jugador son: ";
        for (const auto& card : player.hand) {
            cout << static_cast<int>(card.figure) << " ";
        }
        cout << "Total: " << player.getTotal() << endl;

        cout << "Las cartas del dealer son: ";
        for (const auto& card : dealer.hand) {
            cout << static_cast<int>(card.figure) << " ";
        }
        cout << "Total: " << dealer.getTotal() << endl;
    }

    void validateGame() {
        int playerTotal = player.getTotal();
        int dealerTotal = dealer.getTotal();

        if (playerTotal == 21) {
            cout << "\nGanaste" << endl;
        } else if (playerTotal > dealerTotal && playerTotal <= 21) {
            cout << "\nGanaste" << endl;
        } else if (playerTotal == dealerTotal) {
            cout << "\nEmpate" << endl;
        } else {
            cout << "\nPerdiste" << endl;
        }
    }

    void play() {
        initGame();
        displayHands();
        validateGame();
    }
};

int main() {
    Blackjack game;
    game.play();
    return 0;
}