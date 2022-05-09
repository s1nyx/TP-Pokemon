#include "pokemon.h"
#include <iostream>

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

float Pokemon::getItsHealthPoint() const
{
    return itsHealthPoint;
}

float Pokemon::getHpPercentage() const
{
    return itsHealthPoint / itsMaxHealthPoint * 100;
}

void Pokemon::setItsHealthPoint(float newItsHealthPoint)
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

void Pokemon::evolve()
{
    itsHealthPoint += 5;
    itsStrengthPower += 8;
    itsWeight *= 1.05;
    itsSize *= 1.05;
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

    if (otherPokemon->itsHealthPoint < 0)
    {
        otherPokemon->itsHealthPoint = 0;
    }
}

std::ostream& operator<<(std::ostream& outputStream, Pokemon& pokemon)
{
    outputStream << pokemon.getDescription().toStdString();

    return outputStream;
}
