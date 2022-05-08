#ifndef GAME_H
#define GAME_H

#include "trainer.h"

enum GameState {
    LOBBY,
    INGAME,
    FINISH
};

enum AIType {
    BASIC,
    ADVANCED,
    EXPERT
};

class Game
{
private:
    static Game* itsInstance; // Utilisation du Singleton comme design-pattern
    GameState itsState;
    Trainer* itsFirstTrainer;
    Trainer* itsSecondTrainer;
    QString itsWinner;
public:
    Game();

    void start(AIType aiType);
    bool canStart();
    void save();
    void gameLoop();

    GameState getItsState() const;
    void setItsState(GameState newItsState);
    Trainer *getItsFirstTrainer() const;
    Trainer *getItsSecondTrainer() const;
    Game *getItsInstance() const;
    const QString &getItsWinner() const;
    void setItsWinner(const QString &newItsWinner);
};

#endif // GAME_H
