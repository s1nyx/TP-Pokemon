#include "game.h"

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
    // TODO: choisir les pokemons aléatoirement pour les 2joueurs
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
