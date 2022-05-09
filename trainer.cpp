#include "databasemanager.h"
#include "game.h"
#include "trainer.h"

#include <iostream>
#include <algorithm>

class Game;

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
    delete itsCurrentPokemon;
}

/*!
 * Renvoie le niveau du dresseur
 * \brief Trainer::getItsLevel
 * \return
 */
int Trainer::getItsLevel() const
{
    return itsLevel;
}

/*!
 * Renvoie la vie totale des pokemons du dresseur
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
 * Renvoie la puissance de combat totale des pokemons du dresseur
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
 * Renvoie la moyenne de vitesse d'attack des pokemons du dresseur
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
 * Renvoie la liste des pokemons du dresseur
 * \brief Trainer::getItsPokemons
 * \return
 */
std::vector<Pokemon *> *Trainer::getItsPokemons() const
{
    return itsPokemons;
}

/*!
 * Définis son nom
 * \brief Trainer::setItsName
 * \param newItsName
 */
void Trainer::setItsName(const QString &newItsName)
{
    itsName = newItsName;
}

/*!
 * Renvoie son nom
 * \brief Trainer::getItsName
 * \return
 */
const QString &Trainer::getItsName() const
{
    return itsName;
}

/*!
 * Renvoie le pokemon sélectionné pour l'attaque
 * \brief Trainer::getItsCurrentPokemon
 * \return
 */
Pokemon *Trainer::getItsCurrentPokemon() const
{
    return itsCurrentPokemon;
}

/*!
 * Définis le pokemon pour l'attaque
 * \brief Trainer::setItsCurrentPokemon
 * \param newItsCurrentPokemon
 */
void Trainer::setItsCurrentPokemon(Pokemon *newItsCurrentPokemon)
{
    itsCurrentPokemon = newItsCurrentPokemon;
}

/*!
 * Définis le type d'IA
 * \brief Trainer::setItsAIType
 * \param newItsAIType
 */
void Trainer::setItsAIType(const AIType &newItsAIType)
{
    itsAIType = newItsAIType;
}

/*!
 * Renvoie l'XP (points) du pokemons
 * \brief Trainer::getItsXP
 * \return
 */
int Trainer::getItsXP() const
{
    return itsXP;
}

/*!
 * Renvoie un boolean vérifiant qu'il a encore des pokemons vivants
 * Permet de choisir un pokemon pour l'attaque
 * \brief Trainer::choosePokemon
 * \return
 */
bool Trainer::choosePokemon()
{
    if (getTotalHealthPoints() == 0) return false;

    // IA Basique: choix aléatoire du pokemon
    if (itsAIType == BASIC)
    {
        do {
           itsCurrentPokemon = (*itsPokemons)[rand() % 6];
        } while (itsCurrentPokemon->isDead());

    }
    // IA Avancé: choix du pokemon en fonction de sa puissance de combat
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
    // IA Expert: choix du pokemon en fonction de sa vie
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
 * Ajoute un pokemon à l'équipe
 * \brief Trainer::addPokemon
 * \param pokemon
 */
void Trainer::addPokemon(Pokemon *pokemon)
{
    itsPokemons->push_back(pokemon);
    addXP(1);
}

/*!
 * Supprime un pokemon de l'équipe
 * \brief Trainer::removePokemon
 * \param pokemon
 * \return
 */
bool Trainer::removePokemon(Pokemon *pokemon)
{
    // coûte 2 XP pour retirer un pokemon
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
 * Permet de retirer de l'XP
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

/*!
 * Enregistre le dresseur dans la BDD
 * \brief Trainer::save
 */
void Trainer::save()
{
    Game().getItsInstance()->getItsDatabaseManager()->saveTrainer(itsName, itsPokemons);
}

/*!
 * Génère les pokemons aléatoirement
 * \brief Trainer::generatePokemons
 * \return
 */
std::vector<Pokemon*>* Trainer::generatePokemons()
{
    // Récupère la liste des pokemons
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
