#include "firepokemon.h"

FirePokemon::FirePokemon(const std::string &itsName, int itsSize, int itsWeight, int itsHealthPoint, int itsStrengthPower, int itsPaws)
    : Pokemon(itsName, itsSize, itsWeight, itsHealthPoint, itsStrengthPower),
      itsPaws(itsPaws)
{}

void FirePokemon::calculateSpeed()
{
    itsSpeed = itsPaws * itsWeight * 0.03;
}

std::string FirePokemon::getDescription()
{
    return "Je suis le Pokemon " + itsName + " (type FEU). Mon poids est de " + std::to_string(itsWeight) + " kg, ma vitesse est de " + std::to_string(itsSpeed) + " km/h. J'ai " + std::to_string(itsPaws) + " pattes, ma taille est de " + std::to_string(itsSize) + "m.";
}

Type FirePokemon::getItsType()
{
    return FIRE;
}

void FirePokemon::attack(Pokemon* otherPokemon)
{
    int currentCP = itsStrengthPower;

    switch (otherPokemon->getItsType())
    {
        case PLANT:
            itsStrengthPower *= 2;
            break;
        case WATER:
        case ELECTRIK:
            itsStrengthPower *= 0.5;
            break;
        default:
            break;
    }

    Pokemon::attack(otherPokemon);

    itsStrengthPower = currentCP;
}
