#ifndef WATERPOKEMON_H
#define WATERPOKEMON_H

#include "pokemon.h"

class WaterPokemon : public Pokemon
{
private:
    int itsFins;

public:
    WaterPokemon(const QString &itsName, float itsSize, float itsWeight, float itsHealthPoint, int itsStrengthPower, int itsFins);
    // Pokemon interface
    QString getDescription();
    Type getItsType();
    void attack(Pokemon* otherPokemon);
};

#endif // WATERPOKEMON_H
