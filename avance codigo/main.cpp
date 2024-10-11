#include <iostream>
#include <random>
#include <string>

using namespace std;

/**
 * @brief Se define al player y dealer/Variables globales.
 *
 * @param player somos nosotros.
 * @param dealer es la maquina.
 *
 */

int player = 0;
int dealer = 0;
string playerMessage = "Las cartas del jugador son:  ";
string dealerMessage = "Las casrtas del dealer son:  ";
int cards [52];

/**
 * @brief Esta función es el deck, las cartas que se usaran.
 *
 */

void createDeck(){
    int cardValue = 2;
    int cardCount = 0;
    for(int figure = 1; figure <= 4; figure++){
        for (int card = 1; card <= 13; card++){
            switch (card){
                case 10:
                case 11:
                case 12:
                    cardValue = 10;
                break;
                case 13:
                    cardValue = 11;
                break;
                default:
                    break;
            }
            cards[cardCount] = cardValue;
            cardCount++;
            cardValue++;
        }
        cardValue = 2;
    }
}

/**
 * @brief Esta función es el robo de las cartas.
 *
 * @code
 * int card = dist(gen);
 * @endcode
 *
 * @return int. Que carta se ha robado.
 */

int drawCard(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 52);
    int card = dist(gen);
    return cards[card -1];
}

/**
 * @brief Es el robo de cartas de cada "jugador".
 *
 */

void initGame() {
    createDeck();
    player = 0;
    dealer = 0;
    player += drawCard();
    dealer += drawCard();
    player += drawCard();
    dealer += drawCard();
    cout << playerMessage << player<< endl;
    cout << dealerMessage << dealer << endl;

}

/**
 * @brief Esta función nos dice el ganador, quien tiene mas "puntos".
 *
 * @code
* if (player == 21) {
        cout << "Ganaste" << endl;
 * @endcode
 *
 * @return Imprime quien ha ganado, perdido o empatado.
 */

void validateGame() {
    if (player == 21) {
        cout << "Ganaste" << endl;
    }else if (player > dealer && player <= 21) {
        cout << "Ganaste" << endl;
    }else if (player == dealer) {
        cout << "Empate" << endl;
    }else {
        cout << "Perdiste" << endl;
    }
}

/**
 * @brief Esta función es el final del juego XD.
 *
 */

int main() {
    initGame();
    validateGame();
    return 0;
}