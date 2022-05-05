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
    itsFirstTrainer = new Trainer("AI 1");
    itsSecondTrainer = new Trainer("AI 2");
}

void Game::start()
{
    if (!DatabaseManager().getItsInstance()->connect())
    {
        std::cout << "Connexion a la BDD impossible." << std::endl;
        return;
    }

    // Choisir les pokemons aléatoirement pour les 2 joueurs
    std::vector<Pokemon*>* pokemons = DatabaseManager().getItsInstance()->getPokemons();
    std::cout << pokemons->size() << std::endl;
    for (unsigned int i = 0; i < 12; ++i)
    {
        int randomIndex = rand() % 40;

        if (i < 6)
        {
            try {
                itsFirstTrainer->addPokemon(pokemons->at(randomIndex));
            }  catch (...) {
                std::cout << "Dresseur 1: L'index n'est pas dans le vecteur des pokemons : " << randomIndex << std::endl;
            }
        }
        else
        {
            try {
                itsSecondTrainer->addPokemon(pokemons->at(randomIndex));
            }  catch (...) {
                std::cout << "Dresseur 2: L'index n'est pas dans le vecteur des pokemons : " << randomIndex << std::endl;
            }
        }
    }

    // TODO: clean un peu le code ici

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

    itsState = INGAME;
}

void Game::gameLoop()
{
    /*while (itsState == INGAME)
    {

    }

    if (itsState == FINISHED)
    {

    }*/
    std::cout << "LOOP" << std::endl;
}
