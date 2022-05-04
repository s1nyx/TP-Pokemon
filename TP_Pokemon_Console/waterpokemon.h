#ifndef WATERPOKEMON_H
#define WATERPOKEMON_H

#include "pokemon.h"

class WaterPokemon : public Pokemon
{
private:
    int itsFins;

public:
    WaterPokemon(const std::string &itsName, float itsSize, float itsWeight, int itsHealthPoint, int itsStrengthPower, int itsFins);
    // Pokemon interface
    void calculateSpeed();
    std::string getDescription();
    Type getItsType();
    void attack(Pokemon* otherPokemon);
};

#endif // WATERPOKEMON_H
