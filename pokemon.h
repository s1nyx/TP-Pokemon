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
    virtual ~Pokemon();

    virtual void attack(Pokemon* otherPokemon);
    bool isDead();
    bool hasKoOneAttack() const;
    void evolve();

    void setItsHealthPoint(float newItsHealthPoint);

    virtual QString getDescription() = 0;
    virtual Type getItsType() = 0;

    float getItsHealthPoint() const;
    float getHpPercentage() const;
    float getItsSpeed() const;
    int getItsStrengthPower() const;
    const QString &getItsName() const;
};

#endif // POKEMON_H
