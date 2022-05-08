#ifndef POKEMON_H
#define POKEMON_H

#include <string>

enum Type {
    ELECTRIK,
    FIRE,
    WATER,
    PLANT
};

class Pokemon
{
protected:
    std::string itsName;
    float itsSize;
    float itsWeight;
    float itsHealthPoint;
    float itsMaxHealthPoint;
    int itsStrengthPower;
    float itsSpeed;

public:
    Pokemon(const std::string &itsName, float itsSize, float itsWeight, float itsHealthPoint, int itsStrengthPower);

    virtual std::string getDescription() = 0;
    virtual Type getItsType() = 0;
    virtual void attack(Pokemon* otherPokemon);

    friend std::ostream& operator<<(std::ostream& outputStream, Pokemon& pokemon);

    int getItsHealthPoint() const;
    void setItsHealthPoint(int newItsHealthPoint);
    const std::string &getItsName() const;
    int getItsStrengthPower() const;
    float getItsSpeed() const;
};

#endif // POKEMON_H
