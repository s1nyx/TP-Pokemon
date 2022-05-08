#ifndef PLANTPOKEMON_H
#define PLANTPOKEMON_H

#include "pokemon.h"

class PlantPokemon : public Pokemon
{
public:
    PlantPokemon(const std::string &itsName, float itsSize, float itsWeight, float itsHealthPoint, int itsStrengthPower);
    // Pokemon interface
    std::string getDescription();
    Type getItsType();
    void attack(Pokemon* otherPokemon);
};

#endif // PLANTPOKEMON_H
