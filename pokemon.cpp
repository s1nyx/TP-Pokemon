#include "pokemon.h"
#include <iostream>

/*!
 * \brief Pokemon::Pokemon
 * \param itsName
 * \param itsSize
 * \param itsWeight
 * \param itsHealthPoint
 * \param itsStrengthPower
 */
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

/*!
 * \brief Pokemon::~Pokemon
 */
Pokemon::~Pokemon()
{}

/*!
 * Renvoie les HP du pokemons
 * \brief Pokemon::getItsHealthPoint
 * \return
 */
float Pokemon::getItsHealthPoint() const
{
    return itsHealthPoint;
}

/*!
 * Renvoie les HP du pokemon en pourcentage
 * \brief Pokemon::getHpPercentage
 * \return
 */
float Pokemon::getHpPercentage() const
{
    return itsHealthPoint / itsMaxHealthPoint * 100;
}

/*!
 * Définis les HP du pokemon
 * \brief Pokemon::setItsHealthPoint
 * \param newItsHealthPoint
 */
void Pokemon::setItsHealthPoint(float newItsHealthPoint)
{
    itsHealthPoint = newItsHealthPoint;
}

/*!
 * Renvoie le nom du pokemon
 * \brief Pokemon::getItsName
 * \return
 */
const QString &Pokemon::getItsName() const
{
    return itsName;
}

/*!
 * Renvoie la puissance de combat du pokemon
 * \brief Pokemon::getItsStrengthPower
 * \return
 */
int Pokemon::getItsStrengthPower() const
{
    return itsStrengthPower;
}

/*!
 * Renvoie la vitesse du pokemon
 * \brief Pokemon::getItsSpeed
 * \return
 */
float Pokemon::getItsSpeed() const
{
    return itsSpeed;
}

/*!
 * Renvoie un boolean vérifiant si le pokemon est mort ou non
 * \brief Pokemon::isDead
 * \return
 */
bool Pokemon::isDead()
{
    return itsHealthPoint == 0;
}

/*!
 * Renvoie un boolean vérifiant si il vient de oneshot un autre pokemon
 * \brief Pokemon::hasKoOneAttack
 * \return
 */
bool Pokemon::hasKoOneAttack() const
{
    return itsKoOneAttack;
}

/*!
 * Evolue le pokemon
 * \brief Pokemon::evolve
 */
void Pokemon::evolve()
{
    itsHealthPoint += 5;
    itsStrengthPower += 8;
    itsWeight *= 1.05;
    itsSize *= 1.05;
}

/*!
 * Attaque un autre pokemon
 * \brief Pokemon::attack
 * \param otherPokemon
 */
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
