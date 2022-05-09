#ifndef GAME_H
#define GAME_H

#include "databasemanager.h"
#include "trainer.h"

enum GameState {
    LOBBY,
    INGAME,
    FINISH
};

class Game
{
private:
    static Game* itsInstance; // Utilisation du Singleton comme design-pattern
    GameState itsState;
    DatabaseManager* itsDatabaseManager;
    Trainer* itsFirstTrainer;
    Trainer* itsSecondTrainer;
    QString itsWinner;

public:
    Game();

    void start(AIType aiType);
    bool canStart();

    GameState getItsState() const;
    void setItsState(GameState newItsState);
    Trainer *getItsFirstTrainer() const;
    Trainer *getItsSecondTrainer() const;
    Game *getItsInstance() const;
    const QString &getItsWinner() const;
    void setItsWinner(const QString &newItsWinner);
    void setItsAIType(AIType newItsAIType);
    DatabaseManager *getItsDatabaseManager() const;
};

#endif // GAME_H
