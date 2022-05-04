#include "trainer.h"

int Trainer::getItsLevel() const
{
    return itsLevel;
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
