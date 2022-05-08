#ifndef POKEMON_H
#define POKEMON_H

#include <QString>
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
    QString itsName;
    float itsSize;
    float itsWeight;
    float itsHealthPoint;
    float itsMaxHealthPoint;
    int itsStrengthPower;
    float itsSpeed;

private:
    bool itsKoOneAttack;

public:
    Pokemon(const QString &itsName, float itsSize, float itsWeight, float itsHealthPoint, int itsStrengthPower);

    virtual QString getDescription() = 0;
    virtual Type getItsType() = 0;
    virtual void attack(Pokemon* otherPokemon);

    friend std::ostream& operator<<(std::ostream& outputStream, Pokemon& pokemon);

    int getItsHealthPoint() const;
    void setItsHealthPoint(int newItsHealthPoint);
    const QString &getItsName() const;
    int getItsStrengthPower() const;
    float getItsSpeed() const;
    bool isDead();
    bool hasKoOneAttack() const;
};

#endif // POKEMON_H
