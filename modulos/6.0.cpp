#include "5.0.h"

/**
 * @brief Este es el ejecutable.
 */


int main() {

    BlackJack blackJack;
    char choice;

    blackJack.showTable();
    blackJack.showWinner();

    cout << "Desesas guardar la partida? (Y/N)";
    cin >> choice;
    if(choice == 'Y' || choice == 'y') {
        blackJack.saveGame("Partida_guardada.txt");
    }

    cout << "Deseas cargar la partida? (Y/N)";
    cin >> choice;
    if(choice == 'Y' || choice == 'y') {
        blackJack.loadGame("partida_guardada.txt");
        blackJack.showTable();
    }

    return 0;
}