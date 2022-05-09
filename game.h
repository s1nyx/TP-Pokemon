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

    void setItsWinner(const QString &newItsWinner);
    void setItsAIType(AIType newItsAIType);
    void setItsState(GameState newItsState);

    GameState getItsState() const;
    Trainer *getItsFirstTrainer() const;
    Trainer *getItsSecondTrainer() const;
    Game *getItsInstance() const;
    DatabaseManager *getItsDatabaseManager() const;
    const QString &getItsWinner() const;
};

#endif // GAME_H
