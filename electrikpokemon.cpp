#include "electrikpokemon.h"

/*!
 * \brief ElectrikPokemon::ElectrikPokemon
 * \param itsName
 * \param itsSize
 * \param itsWeight
 * \param itsHealthPoint
 * \param itsStrengthPower
 * \param itsPaws
 * \param itsIntensity
 * \param itsWings
 */
ElectrikPokemon::ElectrikPokemon(const QString &itsName, float itsSize, float itsWeight, float itsHealthPoint, int itsStrengthPower, int itsPaws, int itsIntensity, int itsWings)
    : Pokemon(itsName, itsSize, itsWeight, itsHealthPoint, itsStrengthPower),
    itsPaws(itsPaws),
    itsIntensity(itsIntensity),
    itsWings(itsWings)
{
    itsSpeed = (itsPaws + itsWings) * itsIntensity * 0.05;
}

/*!
 * Renvoie la description du pokemon
 * \brief ElectrikPokemon::getDescription
 * \return
 */
QString ElectrikPokemon::getDescription()
{
    return "Je suis le Pokemon " + itsName + " (type ELECTRIK). Mon poids est de " + QString::number(itsWeight) +" kg, ma vitesse est de " + QString::number(itsSpeed) + " km/h. J'ai " + QString::number(itsPaws) + " pattes, ma taille est de " + QString::number(itsSize) + "m et mon intensité est de " + QString::number(itsIntensity) + "mA.";
}

/*!
 * Renvoie le type du pokemon
 * \brief ElectrikPokemon::getItsType
 * \return
 */
Type ElectrikPokemon::getItsType()
{
    return ELECTRIK;
}

/*!
 * Permet d'attaquer un autre pokemon
 * \brief ElectrikPokemon::attack
 * \param otherPokemon
 */
void ElectrikPokemon::attack(Pokemon* otherPokemon)
{
    int currentCP = itsStrengthPower;

    switch (otherPokemon->getItsType())
    {
        case WATER:
            itsStrengthPower *= 2;
            break;
        case PLANT:
        case ELECTRIK:
            itsStrengthPower *= 0.5;
            break;
        default:
            break;
    }

    Pokemon::attack(otherPokemon);

    itsStrengthPower = currentCP;
}

