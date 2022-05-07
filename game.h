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
    static Game* itsInstance; // Utilisation du Singleton comme design-pattern
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
    Trainer *getItsFirstTrainer() const;
    Trainer *getItsSecondTrainer() const;
    Game *getItsInstance() const;
};

#endif // GAME_H
