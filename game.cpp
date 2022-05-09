#include "databasemanager.h"
#include "game.h"

/*!
 * \brief Game::Game
 */
Game::Game()
{
    itsState = LOBBY;

    itsWinner = "";

    itsDatabaseManager = new DatabaseManager();
    itsFirstTrainer = new Trainer("AI 1");
    itsSecondTrainer = new Trainer("AI 2");
}


Game* Game::itsInstance = nullptr;

/*!
 * Renvoie le statut actuel de la partie
 * \brief Game::getItsState
 * \return
 */
GameState Game::getItsState() const
{
    return itsState;
}

/*!
 * Définis le statut actuel de la partie
 * \brief Game::setItsState
 * \param newItsState
 */
void Game::setItsState(GameState newItsState)
{
    itsState = newItsState;
}

/*!
 * Renvoie le premier dresseur
 * \brief Game::getItsFirstTrainer
 * \return
 */
Trainer *Game::getItsFirstTrainer() const
{
    return itsFirstTrainer;
}

/*!
 * Renvoie le second dresseur
 * \brief Game::getItsSecondTrainer
 * \return
 */
Trainer *Game::getItsSecondTrainer() const
{
    return itsSecondTrainer;
}

/*!
 * Renvoie l'instance de la classe (Singleton)
 * \brief Game::getItsInstance
 * \return
 */
Game *Game::getItsInstance() const
{
    if (itsInstance == nullptr)
    {
        itsInstance = new Game();
    }

    return itsInstance;
}

/*!
 * Renvoie le gagnant de la partie
 * \brief Game::getItsWinner
 * \return
 */
const QString &Game::getItsWinner() const
{
    return itsWinner;
}

/*!
 * Définis le gagnant de la partie
 * \brief Game::setItsWinner
 * \param newItsWinner
 */
void Game::setItsWinner(const QString &newItsWinner)
{
    itsWinner = newItsWinner;
}

/*!
 * Renvoie l'objet qui gère la BDD
 * \brief Game::getItsDatabaseManager
 * \return
 */
DatabaseManager *Game::getItsDatabaseManager() const
{
    return itsDatabaseManager;
}

/*!
 * Permet de lancer la partie
 * \brief Game::start
 * \param aiType
 */
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

/*!
 * Renvoie un boolean vérifiant si la partie peut être commencé
 * \brief Game::canStart
 * \return
 */
bool Game::canStart()
{
    return itsState == INGAME;
}
