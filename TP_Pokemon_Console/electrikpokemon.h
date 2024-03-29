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
    ElectrikPokemon(const std::string &itsName, float itsSize, float itsWeight, float itsHealthPoint, int itsStrengthPower, int itsPaws, int itsIntensity, int itsWings);
    void calculateSpeed();
    std::string getDescription();
    Type getItsType();
    void attack(Pokemon* otherPokemon);
};

#endif // ELECTRIKPOKEMON_H
