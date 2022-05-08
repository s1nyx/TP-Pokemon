#include "databasemanager.h"
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

std::vector<Pokemon *> *Trainer::getItsPokemons() const
{
    return itsPokemons;
}

void Trainer::setItsName(const QString &newItsName)
{
    itsName = newItsName;
}

const QString &Trainer::getItsName() const
{
    return itsName;
}

Pokemon *Trainer::getCurrentPokemon() const
{
    return currentPokemon;
}

void Trainer::setCurrentPokemon(Pokemon *newCurrentPokemon)
{
    currentPokemon = newCurrentPokemon;
}

void Trainer::setItsAIType(const AIType &newItsAIType)
{
    itsAIType = newItsAIType;
}

Trainer::Trainer(const QString &itsName) : itsName(itsName)
{
    itsLevel = 0;
    itsXP = 0;
    itsPokemons = new std::vector<Pokemon*>;
    currentPokemon = nullptr;
}

Trainer::~Trainer()
{
    delete itsPokemons;
}

bool Trainer::choosePokemon()
{
    if (getTotalHealthPoints() == 0) return false;


    if (itsAIType == BASIC)
    {
        do {
           currentPokemon = (*itsPokemons)[rand() % 6];
        } while (currentPokemon->isDead());

    }
    else if (itsAIType == ADVANCED)
    {
        Pokemon* max = (*itsPokemons)[0];

        for (Pokemon* pokemon : *itsPokemons)
        {
            if (!pokemon->isDead() && max->getItsStrengthPower() < pokemon->getItsStrengthPower())
            {
                max = pokemon;
            }
        }

        currentPokemon = max;
    }
    else
    {
        Pokemon* max = (*itsPokemons)[0];

        for (Pokemon* pokemon : *itsPokemons)
        {
            if (!pokemon->isDead() && max->getItsHealthPoint() < pokemon->getItsHealthPoint())
            {
                max = pokemon;
            }
        }

        currentPokemon = max;
    }

    return true;
}

void Trainer::addPokemon(Pokemon *pokemon)
{
    itsPokemons->push_back(pokemon);

    addXP(1);

    //std::cout << "Pokemon " << pokemon->getItsName() << " ajouté à la collection" << std::endl;
}

bool Trainer::removePokemon(Pokemon *pokemon)
{
    if (itsXP < 2)
    {
       return false;
    }

    std::vector<Pokemon*>::iterator pokemonIterator = std::find(itsPokemons->begin(), itsPokemons->end(), pokemon);

    if (pokemonIterator != itsPokemons->end())
    {
        itsPokemons->erase(pokemonIterator);
        //std::cout << "Pokemon " << (*pokemonIterator)->getItsName() << " retiré de la collection" << std::endl;
    }

    return true;
}

void Trainer::compareWithOpponent(Trainer *opponent)
{
    std::cout << *this << std::endl;
    std::cout << *opponent << std::endl;

    unsigned int currentTrainerWinningProbability = getTotalStrengthPower() / getTotalHealthPoints() * 100;
    unsigned int opponentTrainerWinningProbability = getTotalStrengthPower() / getTotalHealthPoints() * 100;

    if (currentTrainerWinningProbability > opponentTrainerWinningProbability)
    {
        std::cout << itsName.toStdString() << " a plus de chance de gagné que " << opponent->itsName.toStdString() << "(" << currentTrainerWinningProbability << "% vs " << opponentTrainerWinningProbability << "%)";
    }
    else if (currentTrainerWinningProbability < opponentTrainerWinningProbability)
    {
        std::cout << opponent->itsName.toStdString() << " a plus de chance de gagné que " << itsName.toStdString() << "(" << opponentTrainerWinningProbability << "% vs " << currentTrainerWinningProbability << "%)";
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

void Trainer::removeXP(int xp)
{
    if (itsXP - xp < 0)
    {
        itsXP = 0;
    }
    else
    {
        itsXP -= xp;
    }
}

void Trainer::save()
{
    DatabaseManager().getItsInstance()->saveTrainer(itsName, itsPokemons);
}

std::vector<Pokemon*>* Trainer::generatePokemons()
{
    // Choisir les pokemons aléatoirement
    std::vector<Pokemon*>* pokemons = DatabaseManager().getItsInstance()->getPokemons();

    for (unsigned int i = 0; i < 6; ++i)
    {
        int randomIndex = rand() % 40;

        try {
            addPokemon(pokemons->at(randomIndex));
        }  catch (...) {
            std::cout << "Dresseur 1: L'index n'est pas dans le vecteur des pokemons : " << randomIndex << std::endl;
        }
    }

    // TODO: les triers par TYPE puis par PC

    return itsPokemons;
}

std::ostream& operator<<(std::ostream& outputStream, Trainer& trainer)
{
    outputStream << "=====================" << std::endl
        << "Dresseur: " << trainer.itsName.toStdString() << " (Niv. " << trainer.itsLevel << ", XP: " << trainer.itsXP << ")" << std::endl
        << "PV Total: " << trainer.getTotalHealthPoints()  << std::endl
        << "PC Total: " << trainer.getTotalStrengthPower()  << std::endl
        << "Moyenne vitesse attaque: " << trainer.getAverageAttackSpeed() << std::endl;

    return outputStream;
}
