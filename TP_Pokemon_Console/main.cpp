#include <iostream>
#include <ctime>
#include "databasemanager.h"
#include "game.h"

int main()
{
    srand(time(0));
    Game* game = new Game();

    /*std::string choseAnswer = "";
    do {
        std::cout << "Voulez-vous utilisé l'IA mode basique, avance ou choix aleatoire ? (Reponse: B, A, CA)" << std::endl;
        std::cin >> choseAnswer;
    } while (choseAnswer != "B" && choseAnswer != "A" && choseAnswer != "CA");
*/
    game->start();
    game->gameLoop();
}
