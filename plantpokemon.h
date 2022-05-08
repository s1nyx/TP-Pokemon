#ifndef PLANTPOKEMON_H
#define PLANTPOKEMON_H

#include "pokemon.h"

class PlantPokemon : public Pokemon
{
public:
    PlantPokemon(const QString &itsName, float itsSize, float itsWeight, float itsHealthPoint, int itsStrengthPower);
    // Pokemon interface
    QString getDescription();
    Type getItsType();
    void attack(Pokemon* otherPokemon);
};

#endif // PLANTPOKEMON_H
