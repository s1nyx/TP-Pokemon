#ifndef TRAINER_H
#define TRAINER_H

#include <string>
#include <vector>
#include <pokemon.h>
#include <QString>

class Trainer
{
private:
    QString itsName;
    int itsLevel;
    int itsXP;
    std::vector<Pokemon*>* itsPokemons; // y'en a 6
    // TODO: checker "il connait la vitesse d’attaque moyenne pour l’ensemble de ses Pokemon ainsi que pour chaque type"

public:
    Trainer(const QString &itsName);
    ~Trainer();

    //void save();
    //void attack(Pokemon* hisPokemon, Trainer* opponent);
    void addPokemon(Pokemon* pokemon);
    bool removePokemon(Pokemon* pokemon);
    void compareWithOpponent(Trainer* opponent);
    void addXP(int xp);
    std::vector<Pokemon*>* generatePokemons();
    int getItsLevel() const;
    float getTotalHealthPoints() const;
    int getTotalStrengthPower() const;
    float getAverageAttackSpeed() const;

    friend std::ostream& operator<<(std::ostream& outputStream, Trainer& trainer);
    std::vector<Pokemon *> *getItsPokemons() const;
    void setItsName(const QString &newItsName);
    const QString &getItsName() const;
};

#endif // TRAINER_H
