#ifndef FIREPOKEMON_H
#define FIREPOKEMON_H

#include "pokemon.h"

class FirePokemon : public Pokemon
{
private:
    int itsPaws;

public:
    FirePokemon(const std::string &itsName, int itsSize, int itsWeight, int itsHealthPoint, int itsStrengthPower, int itsPaws);
    // Pokemon interface
    void calculateSpeed();
    std::string getDescription();
    Type getItsType();
    void attack(Pokemon* otherPokemon);
};

#endif // FIREPOKEMON_H
