#include "firepokemon.h"

/*!
 * \brief FirePokemon::FirePokemon
 * \param itsName
 * \param itsSize
 * \param itsWeight
 * \param itsHealthPoint
 * \param itsStrengthPower
 * \param itsPaws
 */
FirePokemon::FirePokemon(const QString &itsName, float itsSize, float itsWeight, float itsHealthPoint, int itsStrengthPower, int itsPaws)
    : Pokemon(itsName, itsSize, itsWeight, itsHealthPoint, itsStrengthPower),
      itsPaws(itsPaws)
{
    itsSpeed = itsPaws * itsWeight * 0.03;
}

/*!
 * Renvoie la description du pokemon
 * \brief FirePokemon::getDescription
 * \return
 */
QString FirePokemon::getDescription()
{
    return "Je suis le Pokemon " + itsName + " (type FEU). Mon poids est de " + QString::number(itsWeight) + " kg, ma vitesse est de " + QString::number(itsSpeed) + " km/h. J'ai " + QString::number(itsPaws) + " pattes, ma taille est de " + QString::number(itsSize) + "m.";
}

/*!
 * Renvoie le type du pokemon
 * \brief FirePokemon::getItsType
 * \return
 */
Type FirePokemon::getItsType()
{
    return FIRE;
}

/*!
 * Permet d'attaquer un autre pokemon
 * \brief FirePokemon::attack
 * \param otherPokemon
 */
void FirePokemon::attack(Pokemon* otherPokemon)
{
    int currentCP = itsStrengthPower;

    switch (otherPokemon->getItsType())
    {
        case PLANT:
            itsStrengthPower *= 2;
            break;
        case WATER:
        case ELECTRIK:
            itsStrengthPower *= 0.5;
            break;
        default:
            break;
    }

    Pokemon::attack(otherPokemon);

    itsStrengthPower = currentCP;
}
