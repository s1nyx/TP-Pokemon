#include "plantpokemon.h"

/*!
 * \brief PlantPokemon::PlantPokemon
 * \param itsName
 * \param itsSize
 * \param itsWeight
 * \param itsHealthPoint
 * \param itsStrengthPower
 */
PlantPokemon::PlantPokemon(const QString &itsName, float itsSize, float itsWeight, float itsHealthPoint, int itsStrengthPower)
    : Pokemon(itsName, itsSize, itsWeight, itsHealthPoint, itsStrengthPower)
{
    itsSpeed = 10 / (itsWeight * itsSize);
}

/*!
 * Renvoie la description du pokemon
 * \brief PlantPokemon::getDescription
 * \return
 */
QString PlantPokemon::getDescription()
{
    return "Je suis le Pokemon " + itsName + " (type PLANTE). Mon poids est de " + QString::number(itsWeight) + " kg, ma taille est de " + QString::number(itsSize) + "m, ma vitesse est de " + QString::number(itsSpeed) + " km/h.";
}

/*!
 * Renvoie le type du pokemon
 * \brief PlantPokemon::getItsType
 * \return
 */
Type PlantPokemon::getItsType()
{
    return PLANT;
}

/*!
 * Permet d'attaquer un autre pokemon
 * \brief PlantPokemon::attack
 * \param otherPokemon
 */
void PlantPokemon::attack(Pokemon* otherPokemon)
{
    int currentCP = itsStrengthPower;

    switch (otherPokemon->getItsType())
    {
        case ELECTRIK:
            itsStrengthPower *= 2;
            break;
        case FIRE:
        case PLANT:
            itsStrengthPower *= 0.5;
            break;
        default:
            break;
    }

    Pokemon::attack(otherPokemon);

    itsStrengthPower = currentCP;
}
