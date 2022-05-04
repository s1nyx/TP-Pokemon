#include "trainer.h"
#include <iostream>
#include <numeric>

int Trainer::getItsLevel() const
{
    return itsLevel;
}

float Trainer::getTotalHealthPoints() const
{
    float total = 0;

    for (Pokemon* pokemon : *itsPokemons)
    {
        total += pokemon->getItsHealthPoint();
    }

    return total;
}

int Trainer::getTotalStrengthPower() const
{
    int total = 0;

    for (Pokemon* pokemon : *itsPokemons)
    {
        total += pokemon->getItsStrengthPower();
    }

    return total;
}

float Trainer::getAverageAttackSpeed() const
{
    // TODO: vérifier que c'est bien la vitesse d'attaque
    float total = 0;

    for (Pokemon* pokemon : *itsPokemons)
    {
        total += pokemon->getItsSpeed();
    }

    return total / itsPokemons->size();
}

Trainer::Trainer(const std::string &itsName) : itsName(itsName)
{
    itsLevel = 0;
    itsXP = 0;
    itsPokemons = new std::vector<Pokemon*>;
}

Trainer::~Trainer()
{
    delete itsPokemons;
}

void Trainer::addXP(int xp)
{
    if (itsXP + xp >= 10)
    {
        itsLevel += 1;
        itsXP = 0; // TODO: est-ce qu'on garde l'XP supplémentaire ?
    }
    else
    {
        itsXP += xp;
    }
}

std::ostream& operator<<(std::ostream& outputStream, Trainer& trainer)
{
    outputStream << "=====================" << std::endl
        << "Dresseur: " << trainer.itsName << " (Niv. " << trainer.itsLevel << ", XP: " << trainer.itsXP << ")" << std::endl
        << "PV Total: " << trainer.getTotalHealthPoints()  << std::endl
        << "PC Total: " << trainer.getTotalStrengthPower()  << std::endl
        << "Moyenne vitesse attaque: " << trainer.getAverageAttackSpeed() << std::endl;

    return outputStream;
}
