#ifndef ELECTRIKPOKEMON_H
#define ELECTRIKPOKEMON_H

#include "pokemon.h"

class ElectrikPokemon : public Pokemon
{
private:
    int itsPaws;
    int itsIntensity;
    int itsWings;

public:
    ElectrikPokemon(const QString &itsName, float itsSize, float itsWeight, float itsHealthPoint, int itsStrengthPower, int itsPaws, int itsIntensity, int itsWings);
    QString getDescription();
    Type getItsType();
    void attack(Pokemon* otherPokemon);
};

#endif // ELECTRIKPOKEMON_H
