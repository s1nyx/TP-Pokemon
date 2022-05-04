#ifndef PLANTPOKEMON_H
#define PLANTPOKEMON_H

#include "pokemon.h"

class PlantPokemon : public Pokemon
{
public:
    PlantPokemon(const std::string &itsName, float itsSize, float itsWeight, int itsHealthPoint, int itsStrengthPower);
    // Pokemon interface
    void calculateSpeed();
    std::string getDescription();
    Type getItsType();
    void attack(Pokemon* otherPokemon);
};

#endif // PLANTPOKEMON_H
