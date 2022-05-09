#include "waterpokemon.h"
#include <iostream>

/*!
 * \brief WaterPokemon::WaterPokemon
 * \param itsName
 * \param itsSize
 * \param itsWeight
 * \param itsHealthPoint
 * \param itsStrengthPower
 * \param itsFins
 */
WaterPokemon::WaterPokemon(const QString &itsName, float itsSize, float itsWeight, float itsHealthPoint, int itsStrengthPower, int itsFins)
    : Pokemon(itsName, itsSize, itsWeight, itsHealthPoint, itsStrengthPower),
      itsFins(itsFins)
{
    itsSpeed = itsWeight * itsFins / 25;
}

/*!
 * Renvoie la description du pokemon
 * \brief WaterPokemon::getDescription
 * \return
 */
QString WaterPokemon::getDescription()
{
    return "Je suis le Pokemon " + itsName + " (type EAU). Mon poids est de " + QString::number(itsWeight) + " kg, ma vitesse est de " + QString::number(itsSpeed) + " km/h. J'ai " + QString::number(itsFins) + " nageoires, ma taille est de " + QString::number(itsSize) + "m.";
}

/*!
 * Renvoie le type du pokemon
 * \brief WaterPokemon::getItsType
 * \return
 */
Type WaterPokemon::getItsType()
{
    return WATER;
}

/*!
 * Attaque un autre pokemon
 * \brief WaterPokemon::attack
 * \param otherPokemon
 */
void WaterPokemon::attack(Pokemon* otherPokemon)
{
    int currentCP = itsStrengthPower;

    switch (otherPokemon->getItsType())
    {
        case FIRE:
            itsStrengthPower *= 2;
            break;
        case WATER:
        case PLANT:
            itsStrengthPower *= 0.5;
            break;
        default:
            break;
    }

    Pokemon::attack(otherPokemon);

    itsStrengthPower = currentCP;
}
