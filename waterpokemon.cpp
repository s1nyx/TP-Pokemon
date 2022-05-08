#include "waterpokemon.h"
#include <iostream>

WaterPokemon::WaterPokemon(const QString &itsName, float itsSize, float itsWeight, float itsHealthPoint, int itsStrengthPower, int itsFins)
    : Pokemon(itsName, itsSize, itsWeight, itsHealthPoint, itsStrengthPower),
      itsFins(itsFins)
{
    itsSpeed = itsWeight * itsFins / 25;
}


QString WaterPokemon::getDescription()
{
    return "Je suis le Pokemon " + itsName + " (type EAU). Mon poids est de " + QString::number(itsWeight) + " kg, ma vitesse est de " + QString::number(itsSpeed) + " km/h. J'ai " + QString::number(itsFins) + " nageoires, ma taille est de " + QString::number(itsSize) + "m.";
}

Type WaterPokemon::getItsType()
{
    return WATER;
}

void WaterPokemon::attack(Pokemon* otherPokemon)
{
    int currentCP = itsStrengthPower;

    switch (otherPokemon->getItsType())
    {
        case FIRE:
            itsStrengthPower *= 2;
            break;
        case WATER:
        case PLANT:
            itsStrengthPower *= 0.5;
            break;
        default:
            break;
    }

    Pokemon::attack(otherPokemon);

    itsStrengthPower = currentCP;
}
