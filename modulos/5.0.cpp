#include "5.0.h"
#include "3.0.h"
#include <string>
#include <iostream>
#include <codecvt>


#ifdef _WIN32

#include <windows.h>

#endif

using namespace std;

int money = 100;

int *moneyPtr = &money;

/**
 * @brief Esta función inicia la partida.
 */

BlackJack::BlackJack() {

    #ifdef _WIN32
    SetConsoleOutputCP((CP_UTF8));
    #endif

    std::locale::global(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));
    std::wcout.imbue(std::locale());

    deck.shuffle();
    player.addCard(deck.draw());
    player.addCard(deck.draw());
    dealer.addCard(deck.draw());
    dealer.addCard(deck.draw());
    showTable();
    playerTurn();
    dealerTurn();
    showWinner();
    play();
}

/**
 * @brief Muestra las manos de ambos jugadores.
 */

void BlackJack::play() {

    string option;
    do {
        cout << "\nDinero:  " << money << endl;
        cout << "Quieres jugar otra vez?  (s/n):  " ;
        cin >> option;

        if (option == "s") {
            deck = Deck();
            deck.shuffle();
            player.hand.clear();
            dealer.hand.clear();
            player.score = 0;
            dealer.score = 0;
            player.addCard(deck.draw());
            player.addCard(deck.draw());
            dealer.addCard(deck.draw());
            dealer.addCard(deck.draw());
            showTable();
            playerTurn();
            dealerTurn();
            showWinner();
        }
    }while (option == "s" && *moneyPtr > 0);
    cout << "Gracias por jugar" <<endl;
}

void BlackJack::showTable() const {

    player.showHand();
    dealer.showHand();
}

/**
 * @brief Indica el turno del Player.
 */

void BlackJack::playerTurn() {

    string option;
    if(player.score < 21) {
        do {
            cout << "Quieres otra carta?  (s/n)" ;
            cin >> option;
            if (option == "s"){
                player.addCard(deck.draw());
            player.showHand();
            }
            if(player.score > 21) {
                break;
            }
        }while (option == "s");
    }

}

/**
 * @brief Indica el turno del Dealer.
 */

void BlackJack::dealerTurn() {

    while (dealer.score < 17) {
        dealer.addCard(deck.draw());
    }
    dealer.showHand();

}

/**
 * @brief Indica al ganador de la partida.
 *
 * @param Player.
 * @param Dealer.
 *
 * @code
* if (player.score > 21) {
        return Winner::DEALER;
    } else {
        if (player.score == 21) {
            return Winner::PLAYER;
 * @endcode
 *
 * @return Al ganador.
 */

[[nodiscard]] Winner BlackJack::getWinner() const {

    if (player.score > 21) {
        if (dealer.score >21) {
            return Winner::DRAW;
        }else {
            *moneyPtr += 10;
            return Winner::DEALER;
        }
    }else {
        if(player.score == 21 || dealer.score > 21) {
            *moneyPtr += 10;
            return Winner::PLAYER;
        }else {
            if (player.score > dealer.score) {
                *moneyPtr += 10;
                return Winner::PLAYER;
            }else if (player.score < dealer.score) {
                *moneyPtr -= 10;
                return Winner::DEALER;
            }else {
                return Winner::DRAW;
            }
        }
    }
}

/**
 * @brief Muestra el resultado del juego.
 */

void BlackJack::showWinner() const {

    string winner = "El ganador es: ";
    switch (getWinner()) {
        case Winner::PLAYER:
            winner += player.name;
        break;
        case Winner::DEALER:
            winner += dealer.name;
        break;
        case Winner::DRAW:
            winner += "Empate";
        break;
    }
    cout << winner << endl;
}