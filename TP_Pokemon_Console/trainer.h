#ifndef TRAINER_H
#define TRAINER_H

#include <string>
#include <vector>
#include <pokemon.h>

class Trainer
{
private:
    std::string itsName;
    int itsLevel;
    int itsXP;
    std::vector<Pokemon*>* itsPokemons; // y'en a 6
    // TODO: checker "il connait la vitesse d’attaque moyenne pour l’ensemble de ses Pokemon ainsi que pour chaque type"

public:
    Trainer(const std::string &itsName);
    ~Trainer();

    void save();
    void attack(Pokemon* hisPokemon, Trainer* opponent);
    void addPokemon(Pokemon* pokemon);
    void removePokemon(Pokemon* pokemon);
    void compareWithOpponent(Trainer* opponent);
    void addXP(int xp);
    int getItsLevel() const;
};

#endif // TRAINER_H
