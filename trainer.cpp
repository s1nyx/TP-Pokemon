#include "databasemanager.h"
#include "game.h"
#include "trainer.h"

#include <iostream>
#include <algorithm>

class Game;

/*!
 * \brief Trainer::getItsLevel
 * \return
 */
int Trainer::getItsLevel() const
{
    return itsLevel;
}

/*!
 * \brief Trainer::getTotalHealthPoints
 * \return
 */
float Trainer::getTotalHealthPoints() const
{
    float total = 0;

    for (Pokemon* pokemon : *itsPokemons)
    {
        total += pokemon->getItsHealthPoint();
    }

    return total;
}

/*!
 * \brief Trainer::getTotalStrengthPower
 * \return
 */
int Trainer::getTotalStrengthPower() const
{
    int total = 0;

    for (Pokemon* pokemon : *itsPokemons)
    {
        total += pokemon->getItsStrengthPower();
    }

    return total;
}

/*!
 * \brief Trainer::getAverageAttackSpeed
 * \return
 */
float Trainer::getAverageAttackSpeed() const
{
    float total = 0;

    for (Pokemon* pokemon : *itsPokemons)
    {
        total += pokemon->getItsSpeed();
    }

    return total / itsPokemons->size();
}

/*!
 * \brief Trainer::getItsPokemons
 * \return
 */
std::vector<Pokemon *> *Trainer::getItsPokemons() const
{
    return itsPokemons;
}

/*!
 * \brief Trainer::setItsName
 * \param newItsName
 */
void Trainer::setItsName(const QString &newItsName)
{
    itsName = newItsName;
}

/*!
 * \brief Trainer::getItsName
 * \return
 */
const QString &Trainer::getItsName() const
{
    return itsName;
}

/*!
 * \brief Trainer::getItsCurrentPokemon
 * \return
 */
Pokemon *Trainer::getItsCurrentPokemon() const
{
    return itsCurrentPokemon;
}

/*!
 * \brief Trainer::setItsCurrentPokemon
 * \param newItsCurrentPokemon
 */
void Trainer::setItsCurrentPokemon(Pokemon *newItsCurrentPokemon)
{
    itsCurrentPokemon = newItsCurrentPokemon;
}

/*!
 * \brief Trainer::setItsAIType
 * \param newItsAIType
 */
void Trainer::setItsAIType(const AIType &newItsAIType)
{
    itsAIType = newItsAIType;
}

/*!
 * \brief Trainer::getItsXP
 * \return
 */
int Trainer::getItsXP() const
{
    return itsXP;
}

/*!
 * \brief Trainer::Trainer
 * \param itsName
 */
Trainer::Trainer(const QString &itsName) : itsName(itsName)
{
    itsLevel = 0;
    itsXP = 0;
    itsPokemons = new std::vector<Pokemon*>;
    itsCurrentPokemon = nullptr;
}

/*!
 * \brief Trainer::~Trainer
 */
Trainer::~Trainer()
{
    delete itsPokemons;
}

/*!
 * \brief Trainer::choosePokemon
 * \return
 */
bool Trainer::choosePokemon()
{
    if (getTotalHealthPoints() == 0) return false;


    if (itsAIType == BASIC)
    {
        do {
           itsCurrentPokemon = (*itsPokemons)[rand() % 6];
        } while (itsCurrentPokemon->isDead());

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

        itsCurrentPokemon = max;
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

        itsCurrentPokemon = max;
    }

    return true;
}

/*!
 * \brief Trainer::addPokemon
 * \param pokemon
 */
void Trainer::addPokemon(Pokemon *pokemon)
{
    itsPokemons->push_back(pokemon);

    addXP(1);
}

/*!
 * \brief Trainer::removePokemon
 * \param pokemon
 * \return
 */
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
    }

    return true;
}

/*!
 * Permet d'ajouter de l'XP (points) et de faire levelup le dresseur (avec les pokemons)
 * \brief Trainer::addXP
 * \param xp
 */
void Trainer::addXP(int xp)
{
    if (itsXP + xp >= 10)
    {
        itsLevel += 1;
        itsXP = 0;

        for (Pokemon* pokemon : *itsPokemons)
        {
            if (!pokemon->isDead()) pokemon->evolve();
        }
    }
    else
    {
        itsXP += xp;
    }
}

/*!
 * \brief Trainer::removeXP
 * \param xp
 */
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
    Game().getItsInstance()->getItsDatabaseManager()->saveTrainer(itsName, itsPokemons);
}

std::vector<Pokemon*>* Trainer::generatePokemons()
{
    // Choisir les pokemons aléatoirement
    std::vector<Pokemon*>* pokemons = Game().getItsInstance()->getItsDatabaseManager()->getPokemons();

    try {
        for (unsigned int i = 0; i < 6; ++i)
        {
            int randomIndex = rand() % 40;
            addPokemon(pokemons->at(randomIndex));
        }
    }  catch (std::out_of_range const& e) {
        std::cerr << "Dresseur 1: L'index n'est pas dans le vecteur des pokemons : " << e.what() << std::endl;
    }

    // TODO: les triers par TYPE puis par PC

    return itsPokemons;
}
