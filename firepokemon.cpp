#include "firepokemon.h"

FirePokemon::FirePokemon(const QString &itsName, float itsSize, float itsWeight, float itsHealthPoint, int itsStrengthPower, int itsPaws)
    : Pokemon(itsName, itsSize, itsWeight, itsHealthPoint, itsStrengthPower),
      itsPaws(itsPaws)
{
    itsSpeed = itsPaws * itsWeight * 0.03;
}

QString FirePokemon::getDescription()
{
    return "Je suis le Pokemon " + itsName + " (type FEU). Mon poids est de " + QString::number(itsWeight) + " kg, ma vitesse est de " + QString::number(itsSpeed) + " km/h. J'ai " + QString::number(itsPaws) + " pattes, ma taille est de " + QString::number(itsSize) + "m.";
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
