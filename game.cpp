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

DatabaseManager *Game::getItsDatabaseManager() const
{
    return itsDatabaseManager;
}

Game::Game()
{
    itsState = LOBBY;

    itsWinner = "";

    itsDatabaseManager = new DatabaseManager();
    itsFirstTrainer = new Trainer("AI 1");
    itsSecondTrainer = new Trainer("AI 2");
}

void Game::start(AIType aiType)
{
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
