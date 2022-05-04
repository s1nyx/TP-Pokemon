#include "waterpokemon.h"
#include <iostream>

WaterPokemon::WaterPokemon(const std::string &itsName, float itsSize, float itsWeight, int itsHealthPoint, int itsStrengthPower, int itsFins)
    : Pokemon(itsName, itsSize, itsWeight, itsHealthPoint, itsStrengthPower),
      itsFins(itsFins)
{}

void WaterPokemon::calculateSpeed()
{
    itsSpeed = itsWeight * itsFins / 25;
}

std::string WaterPokemon::getDescription()
{
    return "Je suis le Pokemon " + itsName + " (type EAU). Mon poids est de " + std::to_string(itsWeight) + " kg, ma vitesse est de " + std::to_string(itsSpeed) + " km/h. J'ai " + std::to_string(itsFins) + " nageoires, ma taille est de " + std::to_string(itsSize) + "m.";
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
