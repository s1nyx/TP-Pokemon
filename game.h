#ifndef GAME_H
#define GAME_H

#include "databasemanager.h"
#include "trainer.h"

enum GameState {
    LOBBY,
    INGAME,
    FINISH
};

class Trainer;

class Game
{
private:
    GameState itsState;
    DatabaseManager* itsDatabaseManager;
    Trainer* itsFirstTrainer;
    Trainer* itsSecondTrainer;
    QString itsWinner;

public:
    Game();

    void start(AIType aiType);
    bool canStart();

    void setItsWinner(const QString &newItsWinner);
    void setItsAIType(AIType newItsAIType);
    void setItsState(GameState newItsState);

    GameState getItsState() const;
    Trainer *getItsFirstTrainer() const;
    Trainer *getItsSecondTrainer() const;
    DatabaseManager *getItsDatabaseManager() const;
    const QString &getItsWinner() const;
};

#endif // GAME_H
