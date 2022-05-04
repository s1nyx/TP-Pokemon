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
    int itsHealthPoint;
    int itsStrengthPower;
    float itsSpeed;

public:
    Pokemon(const std::string &itsName, int itsSize, int itsWeight, int itsHealthPoint, int itsStrengthPower);

    virtual void calculateSpeed() = 0;
    virtual std::string getDescription() = 0;
    virtual Type getItsType() = 0;
    virtual void attack(Pokemon* otherPokemon);

    friend std::ostream& operator<<(std::ostream& outputStream, Pokemon& pokemon);

    int getItsHealthPoint() const;
    void setItsHealthPoint(int newItsHealthPoint);
    const std::string &getItsName() const;
};

#endif // POKEMON_H
