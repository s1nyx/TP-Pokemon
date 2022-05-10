#ifndef TRAINER_H
#define TRAINER_H

#include <string>
#include <vector>
#include <pokemon.h>
#include <QString>

class Game;

// Types d'IA possibles
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
    // 6 pokemons max
    std::vector<Pokemon*>* itsPokemons;
    Pokemon* itsCurrentPokemon;
    AIType itsAIType;

public:
    Trainer(const QString &itsName);
    ~Trainer();

    bool choosePokemon();
    bool removePokemon(Pokemon* pokemson);
    void addPokemon(Pokemon* pokemon);
    void addXP(int xp);
    void removeXP(int xp);
    void save(Game* game);
    std::vector<Pokemon*>* generatePokemons(Game* game);

    void setItsName(const QString &newItsName);
    void setItsCurrentPokemon(Pokemon* newItsCurrentPokemon);
    void setItsAIType(const AIType &newItsAIType);

    std::vector<Pokemon *> *getItsPokemons() const;
    int getItsLevel() const;
    int getTotalStrengthPower() const;
    int getItsXP() const;
    float getTotalHealthPoints() const;
    float getAverageAttackSpeed() const;
    const QString &getItsName() const;
    Pokemon *getItsCurrentPokemon() const;
};

#endif // TRAINER_H
