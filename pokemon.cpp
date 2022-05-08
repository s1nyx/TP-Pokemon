#include "pokemon.h"
#include <iostream>

int Pokemon::getItsHealthPoint() const
{
    return itsHealthPoint;
}

void Pokemon::setItsHealthPoint(int newItsHealthPoint)
{
    itsHealthPoint = newItsHealthPoint;
}

const QString &Pokemon::getItsName() const
{
    return itsName;
}

int Pokemon::getItsStrengthPower() const
{
    return itsStrengthPower;
}

float Pokemon::getItsSpeed() const
{
    return itsSpeed;
}

bool Pokemon::isDead()
{
    return itsHealthPoint == 0;
}

bool Pokemon::hasKoOneAttack() const
{
    return itsKoOneAttack;
}

Pokemon::Pokemon(const QString &itsName, float itsSize, float itsWeight, float itsHealthPoint, int itsStrengthPower)
    :
    itsName(itsName),
    itsSize(itsSize),
    itsWeight(itsWeight),
    itsHealthPoint(itsHealthPoint),
    itsStrengthPower(itsStrengthPower)
{
    itsMaxHealthPoint = itsHealthPoint;
    itsKoOneAttack = false;
}

void Pokemon::attack(Pokemon *otherPokemon)
{
    if (otherPokemon->itsMaxHealthPoint == otherPokemon->itsHealthPoint
        && otherPokemon->itsHealthPoint - itsStrengthPower <= 0)
    {
        // pokemon KO en 1 coup
        itsKoOneAttack = true;
    }

    otherPokemon->setItsHealthPoint(otherPokemon->itsHealthPoint - itsStrengthPower);

    //std::cout << itsName.tost << " inflige " << itsStrengthPower << " dégats à " << otherPokemon->getItsName() << std::endl;

    if (otherPokemon->itsHealthPoint <= 0)
    {
        otherPokemon->itsHealthPoint = 0;
    }
}

std::ostream& operator<<(std::ostream& outputStream, Pokemon& pokemon)
{
    outputStream << pokemon.getDescription().toStdString();

    return outputStream;
}
