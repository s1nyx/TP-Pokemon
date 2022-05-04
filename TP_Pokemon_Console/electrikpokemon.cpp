#include "electrikpokemon.h"

ElectrikPokemon::ElectrikPokemon(const std::string &itsName, float itsSize, float itsWeight, float itsHealthPoint, int itsStrengthPower, int itsPaws, int itsIntensity, int itsWings)
    : Pokemon(itsName, itsSize, itsWeight, itsHealthPoint, itsStrengthPower),
    itsPaws(itsPaws),
    itsIntensity(itsIntensity),
    itsWings(itsWings)
{}


void ElectrikPokemon::calculateSpeed()
{
    itsSpeed = (itsPaws + itsWings) * itsIntensity * 0.05;
}

std::string ElectrikPokemon::getDescription()
{
    return "Je suis le Pokemon " + itsName + " (type ELECTRIK). Mon poids est de " + std::to_string(itsWeight) +" kg, ma vitesse est de " + std::to_string(itsSpeed) + " km/h. J'ai " + std::to_string(itsPaws) + " pattes, ma taille est de " + std::to_string(itsSize) + "m et mon intensité est de " + std::to_string(itsIntensity) + "mA.";
}

Type ElectrikPokemon::getItsType()
{
    return ELECTRIK;
}

void ElectrikPokemon::attack(Pokemon* otherPokemon)
{
    int currentCP = itsStrengthPower;

    switch (otherPokemon->getItsType())
    {
        case WATER:
            itsStrengthPower *= 2;
            break;
        case PLANT:
        case ELECTRIK:
            itsStrengthPower *= 0.5;
            break;
        default:
            break;
    }

    Pokemon::attack(otherPokemon);

    itsStrengthPower = currentCP;
}

