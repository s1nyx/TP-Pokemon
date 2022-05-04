#include "databasemanager.h"
#include "game.h"
#include <iostream>

GameState Game::getItsState() const
{
    return itsState;
}

void Game::setItsState(GameState newItsState)
{
    itsState = newItsState;
}

Game::Game()
{
    itsState = LOBBY;
    itsFirstRobot = new Trainer("AI 1");
    itsSecondRobot = new Trainer("AI 2");
}

void Game::start(std::string aiType)
{
    if (!DatabaseManager().getItsInstance()->connect())
    {
        std::cout << "Connexion a la BDD impossible." << std::endl;
        return;
    }

    // TODO: choisir les pokemons aléatoirement pour les 2joueurs
    std::vector<Pokemon*>* pokemons = DatabaseManager().getItsInstance()->getPokemons();

    std::cout << pokemons->size() << std::endl;

    for (Pokemon* p : *pokemons)
    {
        std::cout << p->getDescription() << std::endl;
    }

    if (itsFirstRobot->getItsLevel() < itsSecondRobot->getItsLevel())
    {
        std::swap(itsFirstRobot, itsSecondRobot);
    }
    else
    {
        // TODO: le dresseur ayant la plus haute puissance de combat totale démarre
    }
}

void Game::gameLoop()
{

}
