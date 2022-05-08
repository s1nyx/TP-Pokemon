#ifndef FIREPOKEMON_H
#define FIREPOKEMON_H

#include "pokemon.h"

class FirePokemon : public Pokemon
{
private:
    int itsPaws;

public:
    FirePokemon(const QString &itsName, float itsSize, float itsWeight, float itsHealthPoint, int itsStrengthPower, int itsPaws);
    // Pokemon interface
    QString getDescription();
    Type getItsType();
    void attack(Pokemon* otherPokemon);
};

#endif // FIREPOKEMON_H
