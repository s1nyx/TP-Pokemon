#include "databasemanager.h"
#include "game.h"
#include <iostream>

Game* Game::itsInstance = nullptr;

GameState Game::getItsState() const
{
    return itsState;
}

void Game::setItsState(GameState newItsState)
{
    itsState = newItsState;
}

Trainer *Game::getItsFirstTrainer() const
{
    return itsFirstTrainer;
}

Trainer *Game::getItsSecondTrainer() const
{
    return itsSecondTrainer;
}

Game *Game::getItsInstance() const
{
    if (itsInstance == nullptr)
    {
        itsInstance = new Game();
    }

    return itsInstance;
}

const QString &Game::getItsWinner() const
{
    return itsWinner;
}

void Game::setItsWinner(const QString &newItsWinner)
{
    itsWinner = newItsWinner;
}

Game::Game()
{
    itsState = LOBBY;

    itsWinner = "";

    itsFirstTrainer = new Trainer("AI 1");
    itsSecondTrainer = new Trainer("AI 2");
}

void Game::start(AIType aiType)
{
    // TODO: trier en fonction du type et des PC
    /*std::sort(itsFirstTrainer->getItsPokemons()->begin(), itsFirstTrainer->getItsPokemons()->end(), [](Pokemon* pokemon1, Pokemon* pokemon2){
        return pokemon1->getItsType() == pokemon2->getItsType();
    });

    for (std::vector<Pokemon*>::iterator it = itsFirstTrainer->getItsPokemons()->begin(); it != itsFirstTrainer->getItsPokemons()->end(); ++it)
    {
        std::cout << (*it)->getDescription() << std::endl;
    }*/

    // TODO: clean un peu le code ici

    itsFirstTrainer->setItsAIType(aiType);
    itsSecondTrainer->setItsAIType(aiType);

    // Gestion du premier joueur qui démarre
    if (itsFirstTrainer->getItsLevel() < itsSecondTrainer->getItsLevel())
    {
        std::swap(itsFirstTrainer, itsSecondTrainer);
    }
    else if (itsFirstTrainer->getItsLevel() == itsSecondTrainer->getItsLevel())
    {
        if (itsFirstTrainer->getAverageAttackSpeed() < itsSecondTrainer->getAverageAttackSpeed())
        {
           std::swap(itsFirstTrainer, itsSecondTrainer);
        }
        else if (itsFirstTrainer->getAverageAttackSpeed() == itsSecondTrainer->getAverageAttackSpeed())
        {
            if (rand() > 0.5)
            {
               std::swap(itsFirstTrainer, itsSecondTrainer);
            }
        }
    }

    itsFirstTrainer->choosePokemon();
    itsSecondTrainer->choosePokemon();


    itsState = INGAME;
}

bool Game::canStart()
{
    return itsState == INGAME;
}
