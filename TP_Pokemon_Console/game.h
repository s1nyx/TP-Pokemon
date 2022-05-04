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
    Trainer* itsFirstRobot;
    Trainer* itsSecondRobot;
public:
    Game();

    void start(std::string robotType);
    void save();
    void gameLoop();

    GameState getItsState() const;
    void setItsState(GameState newItsState);
};

#endif // GAME_H
