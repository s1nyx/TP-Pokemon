#ifndef TRAINER_H
#define TRAINER_H

#include <string>
#include <vector>
#include <pokemon.h>
#include <QString>

enum AIType {
    BASIC,
    ADVANCED,
    EXPERT
};

class Trainer
{
private:
    QString itsName;
    int itsLevel;
    int itsXP;
    std::vector<Pokemon*>* itsPokemons; // y'en a 6
    Pokemon* currentPokemon;
    AIType itsAIType;

public:
    Trainer(const QString &itsName);
    ~Trainer();

    bool choosePokemon();
    bool removePokemon(Pokemon* pokemson);
    void addPokemon(Pokemon* pokemon);
    void compareWithOpponent(Trainer* opponent);
    void addXP(int xp);
    void removeXP(int xp);
    void save();

    std::vector<Pokemon*>* generatePokemons();
    int getItsLevel() const;
    int getTotalStrengthPower() const;
    float getTotalHealthPoints() const;
    float getAverageAttackSpeed() const;

    std::vector<Pokemon *> *getItsPokemons() const;
    void setItsName(const QString &newItsName);
    const QString &getItsName() const;
    Pokemon *getCurrentPokemon() const;
    void setCurrentPokemon(Pokemon *newCurrentPokemon);
    void setItsAIType(const AIType &newItsAIType);
    int getItsXP() const;
};

#endif // TRAINER_H
