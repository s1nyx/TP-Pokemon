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

const std::string &Pokemon::getItsName() const
{
    return itsName;
}

Pokemon::Pokemon(const std::string &itsName, int itsSize, int itsWeight, int itsHealthPoint, int itsStrengthPower)
    :
    itsName(itsName),
    itsSize(itsSize),
    itsWeight(itsWeight),
    itsHealthPoint(itsHealthPoint),
    itsStrengthPower(itsStrengthPower)
{}

void Pokemon::attack(Pokemon *otherPokemon)
{
    otherPokemon->setItsHealthPoint(otherPokemon->getItsHealthPoint() - itsCP);

    std::cout << itsName << " inflige " << itsCP << " dégats à " << otherPokemon->getItsName() << std::endl;

    if (otherPokemon->getItsHealthPoint() <= 0)
    {
        std::cout << otherPokemon->getItsName() << " est mort." << std::endl;
    }
}

std::ostream& operator<<(std::ostream& outputStream, Pokemon& pokemon)
{
    outputStream << pokemon.getDescription();

    return outputStream;
}
