#ifndef GAME_H
#define GAME_H

#include "trainer.h"

enum GameState {
    LOBBY,
    INGAME,
    FINISHED
};

class Game
{
private:
    GameState itsState;
    Trainer* itsFirstTrainer;
    Trainer* itsSecondTrainer;
public:
    Game();

    void start();
    void save();
    void gameLoop();

    GameState getItsState() const;
    void setItsState(GameState newItsState);
};

#endif // GAME_H
