#include "trainer.h"
#include <iostream>
#include <algorithm>

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

void Trainer::addPokemon(Pokemon *pokemon)
{
    itsPokemons->push_back(pokemon);

    addXP(1);

    std::cout << "Pokemon " << pokemon->getItsName() << " ajouté à la collection" << std::endl;
}

void Trainer::removePokemon(Pokemon *pokemon)
{
    if (itsXP < 2)
    {
        std::cout << "Oups! Vous devez avoir au minimum 2 XP pour retirer ce pokemon" << std::endl;
    }
    else
    {
        std::vector<Pokemon*>::iterator pokemonIterator = std::find(itsPokemons->begin(), itsPokemons->end(), pokemon);

        if (pokemonIterator != itsPokemons->end())
        {
            itsPokemons->erase(pokemonIterator);
        }
    }
}

void Trainer::compareWithOpponent(Trainer *opponent)
{
    std::cout << *this << std::endl;
    std::cout << *opponent << std::endl;

    unsigned int currentTrainerWinningProbability = getTotalStrengthPower() / getTotalHealthPoints() * 100;
    unsigned int opponentTrainerWinningProbability = getTotalStrengthPower() / getTotalHealthPoints() * 100;

    if (currentTrainerWinningProbability > opponentTrainerWinningProbability)
    {
        std::cout << itsName << " a plus de chance de gagné que " << opponent->itsName << "(" << currentTrainerWinningProbability << "% vs " << opponentTrainerWinningProbability << "%)";
    }
    else if (currentTrainerWinningProbability < opponentTrainerWinningProbability)
    {
        std::cout << opponent->itsName << " a plus de chance de gagné que " << itsName << "(" << opponentTrainerWinningProbability << "% vs " << currentTrainerWinningProbability << "%)";
    }
    else
    {
        std::cout << "Les deux dresseurs ont autant de chance de gagné." << std::endl;
    }
}

/*!
 * Permet d'ajouter de l'XP (points) et de faire levelup le dresseur
 * \brief Trainer::addXP
 * \param xp
 */
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
