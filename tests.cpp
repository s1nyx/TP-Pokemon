#include "electrikpokemon.h"
#include "firepokemon.h"
#include "game.h"
#include "plantpokemon.h"
#include "pokemon.h"
#include "trainer.h"
#include "waterpokemon.h"

#include <iostream>

// TEST: WaterPokemon
void test_waterpokemon()
{
    std::cout << "TEST: WaterPokemon" << std::endl;
    Pokemon* water = new WaterPokemon("a", 1,2,3,4,5);

    // check: getItsName()
    if (water->getItsName() != "a")
    {
        std::cout << "Problème sur getItsName" << std::endl;
    }

    // check: getHpPercentage()
    if (water->getHpPercentage() != 100.0)
    {
        std::cout << "Problème sur getHpPercentage" << std::endl;
    }

    // check getDescription()
    if (water->getDescription() == QString::fromStdString("Je suis le Pokemon a (type EAU). Mon poids est de 2 kg, ma vitesse est de " + std::to_string(water->getItsSpeed()) + " km/h. J'ai 5 nageoires, ma taille est de 1m."))
    {
        std::cout << "Problème sur getDescription" << std::endl;
    }

    // check: getItsHealthPoint()
    if (water->getItsHealthPoint() != 3)
    {
        std::cout << "Problème sur getItsHealthPoint" << std::endl;
    }

    //check: getItsStrengthPower()
    if (water->getItsStrengthPower() != 4)
    {
        std::cout << "Problème sur getItsStrengthPower" << std::endl;
    }

    // check: getItsType()
    if (water->getItsType() != WATER)
    {
        std::cout << "Problème sur getItsType" << std::endl;
    }

    // check: isDead()
    if (water->isDead())
    {
        std::cout << "Problème sur isDead" << std::endl;
    }

    // check: setItsHealthPoint()
    water->setItsHealthPoint(1);

    if (water->getItsHealthPoint() != 1)
    {
        std::cout << "Problème sur setItsHealthPoint" << std::endl;
    }

    // check: evolve()
    QString currentDescription = water->getDescription();
    water->evolve();

    if (currentDescription == water->getDescription())
    {
        std::cout << "Problème sur evolve" << std::endl;
    }

    // check: hasKoOneAttack()
    Pokemon* opponant = new WaterPokemon("b", 1, 1, 1, 1, 1);

    water->attack(opponant);
    if (!water->hasKoOneAttack())
    {
        std::cout << "Problème sur hasKoOneAttack" << std::endl;
    }

    // check: attack()
    if (!opponant->isDead())
    {
        std::cout << "Problème sur attack" << std::endl;
    }

    delete water;
    delete opponant;

    std::cout << std::endl;
}

// TEST: PlantPokemon
void test_plantpokemon()
{
    std::cout << "TEST: PlantPokemon" << std::endl;
    Pokemon* plant = new PlantPokemon("a", 1,2,3,4);

    // check: getItsName()
    if (plant->getItsName() != "a")
    {
        std::cout << "Problème sur getItsName" << std::endl;
    }

    // check: getHpPercentage()
    if (plant->getHpPercentage() != 100.0)
    {
        std::cout << "Problème sur getHpPercentage" << std::endl;
    }

    // check getDescription()
    if (plant->getDescription() == QString::fromStdString("Je suis le Pokemon a (type PLANTE). Mon poids est de 2 kg, ma taille est de 1m, ma vitesse est de " + std::to_string(plant->getItsSpeed()) + " km/h."))
    {
        std::cout << "Problème sur getDescription" << std::endl;
    }

    // check: getItsHealthPoint()
    if (plant->getItsHealthPoint() != 3)
    {
        std::cout << "Problème sur getItsHealthPoint" << std::endl;
    }

    //check: getItsStrengthPower()
    if (plant->getItsStrengthPower() != 4)
    {
        std::cout << "Problème sur getItsStrengthPower" << std::endl;
    }

    // check: getItsType()
    if (plant->getItsType() != PLANT)
    {
        std::cout << "Problème sur getItsType" << std::endl;
    }

    // check: isDead()
    if (plant->isDead())
    {
        std::cout << "Problème sur isDead" << std::endl;
    }

    // check: setItsHealthPoint()
    plant->setItsHealthPoint(1);

    if (plant->getItsHealthPoint() != 1)
    {
        std::cout << "Problème sur setItsHealthPoint" << std::endl;
    }

    // check: evolve()
    QString currentDescription = plant->getDescription();
    plant->evolve();

    if (currentDescription == plant->getDescription())
    {
        std::cout << "Problème sur evolve" << std::endl;
    }

    // check: hasKoOneAttack()
    Pokemon* opponant = new WaterPokemon("b", 1, 1, 1, 1, 1);

    plant->attack(opponant);
    if (!plant->hasKoOneAttack())
    {
        std::cout << "Problème sur hasKoOneAttack" << std::endl;
    }

    // check: attack()
    if (!opponant->isDead())
    {
        std::cout << "Problème sur attack" << std::endl;
    }

    delete plant;
    delete opponant;

    std::cout << std::endl;
}

// TEST: FirePokemon
void test_firepokemon()
{
    std::cout << "TEST: FirePokemon" << std::endl;
    Pokemon* fire = new FirePokemon("a", 1,2,3,4, 5);

    // check: getItsName()
    if (fire->getItsName() != "a")
    {
        std::cout << "Problème sur getItsName" << std::endl;
    }

    // check: getHpPercentage()
    if (fire->getHpPercentage() != 100.0)
    {
        std::cout << "Problème sur getHpPercentage" << std::endl;
    }

    // check getDescription()
    if (fire->getDescription() == QString::fromStdString("Je suis le Pokemon a (type FEU). Mon poids est de 2 kg, ma vitesse est de " + std::to_string(fire->getItsSpeed()) + " km/h. J'ai 5 pattes, ma taille est de 1m."))
    {
        std::cout << "Problème sur getDescription" << std::endl;
    }

    // check: getItsHealthPoint()
    if (fire->getItsHealthPoint() != 3)
    {
        std::cout << "Problème sur getItsHealthPoint" << std::endl;
    }

    //check: getItsStrengthPower()
    if (fire->getItsStrengthPower() != 4)
    {
        std::cout << "Problème sur getItsStrengthPower" << std::endl;
    }

    // check: getItsType()
    if (fire->getItsType() != FIRE)
    {
        std::cout << "Problème sur getItsType" << std::endl;
    }

    // check: isDead()
    if (fire->isDead())
    {
       std::cout << "Problème sur isDead" << std::endl;
    }

    // check: setItsHealthPoint()
    fire->setItsHealthPoint(1);

    if (fire->getItsHealthPoint() != 1)
    {
        std::cout << "Problème sur setItsHealthPoint" << std::endl;
    }

    // check: evolve()
    QString currentDescription = fire->getDescription();
    fire->evolve();

    if (currentDescription == fire->getDescription())
    {
        std::cout << "Problème sur evolve" << std::endl;
    }

    // check: hasKoOneAttack()
    Pokemon* opponant = new WaterPokemon("b", 1, 1, 1, 1, 1);

    fire->attack(opponant);
    if (!fire->hasKoOneAttack())
    {
        std::cout << "Problème sur hasKoOneAttack" << std::endl;
    }

    // check: attack()
    if (!opponant->isDead())
    {
        std::cout << "Problème sur attack" << std::endl;
    }

    delete fire;
    delete opponant;

    std::cout << std::endl;
}

// TEST: ElectrikPokemon
void test_electrikpokemon()
{
    std::cout << "TEST: ElectrikPokemon" << std::endl;
    Pokemon* electrik = new ElectrikPokemon("a", 1,2,3,4,5, 6, 7);

    // check: getItsName()
    if (electrik->getItsName() != "a")
    {
        std::cout << "Problème sur getItsName" << std::endl;
    }

    // check: getHpPercentage()
    if (electrik->getHpPercentage() != 100.0)
    {
        std::cout << "Problème sur getHpPercentage" << std::endl;
    }

    // check getDescription()
    if (electrik->getDescription() == QString::fromStdString("Je suis le Pokemon a (type ELECTRIK). Mon poids est de 2 kg, ma vitesse est de " + std::to_string(electrik->getItsSpeed()) + " km/h. J'ai 5 pattes, ma taille est de 1m et mon intensité est de 7mA."))
    {
        std::cout << "Problème sur getDescription" << std::endl;
    }

    // check: getItsHealthPoint()
    if (electrik->getItsHealthPoint() != 3)
    {
        std::cout << "Problème sur getItsHealthPoint" << std::endl;
    }

    //check: getItsStrengthPower()
    if (electrik->getItsStrengthPower() != 4)
    {
        std::cout << "Problème sur getItsStrengthPower" << std::endl;
    }

    // check: getItsType()
    if (electrik->getItsType() != ELECTRIK)
    {
        std::cout << "Problème sur getItsType" << std::endl;
    }

    // check: isDead()
    if (electrik->isDead())
    {
       std::cout << "Problème sur isDead" << std::endl;
    }

    // check: setItsHealthPoint()
    electrik->setItsHealthPoint(1);

    if (electrik->getItsHealthPoint() != 1)
    {
        std::cout << "Problème sur setItsHealthPoint" << std::endl;
    }

    // check: evolve()
    QString currentDescription = electrik->getDescription();
    electrik->evolve();

    if (currentDescription == electrik->getDescription())
    {
        std::cout << "Problème sur evolve" << std::endl;
    }

    // check: hasKoOneAttack()
    Pokemon* opponant = new WaterPokemon("b", 1, 1, 1, 1, 1);

    electrik->attack(opponant);
    if (!electrik->hasKoOneAttack())
    {
        std::cout << "Problème sur hasKoOneAttack" << std::endl;
    }

    // check: attack()
    if (!opponant->isDead())
    {
        std::cout << "Problème sur attack" << std::endl;
    }

    delete electrik;
    delete opponant;

    std::cout << std::endl;
}

// TEST: Trainer
void test_trainer()
{
    std::cout << "TEST: Trainer" << std::endl;
    Trainer* trainer = new Trainer("AA");

    // check: generatePokemons()
    Game* game = new Game();
    game->getItsDatabaseManager()->connect();
    game->getItsDatabaseManager()->startQueries();

    if (trainer->generatePokemons(game)->size() == 0)
    {
        std::cout << "Problème sur generatePokemons" << std::endl;
    }

    // check: choosePokemon()
    bool hasPokemonsAlive = trainer->choosePokemon();

    if (!hasPokemonsAlive)
    {
        std::cout << "Problème sur choosePokemon" << std::endl;
    }

    // check: removePokemon()
    if (!trainer->removePokemon(trainer->getItsCurrentPokemon()))
    {
        std::cout << "Problème sur removePokemon" << std::endl;
    }

    // check: addPokemon()
    unsigned long long currentPokemonsSize = trainer->getItsPokemons()->size();
    trainer->addPokemon(new FirePokemon("a",1,1,1,1,1));

    if (trainer->getItsPokemons()->size() == currentPokemonsSize)
    {
        std::cout << "Problème sur addPokemon" << std::endl;
    }

    // check: addXP()
    int currentLevel = trainer->getItsLevel();
    trainer->addXP(10);

    if (trainer->getItsXP() != 0 || trainer->getItsLevel() == currentLevel)
    {
        std::cout << "Problème sur addXP" << std::endl;
    }

    // check: removeXP()
    trainer->removeXP(5);

    if (trainer->getItsXP() != 0)
    {
        std::cout << "Problème sur removeXP" << std::endl;
    }

    // check: setItsName()
    trainer->setItsName("aze");

    if (trainer->getItsName() != "aze")
    {
        std::cout << "Problème sur setItsName" << std::endl;
    }

    // check: setItsCurrentPokemon()
    trainer->setItsCurrentPokemon(trainer->getItsPokemons()->at(0));

    if (trainer->getItsCurrentPokemon() != trainer->getItsPokemons()->at(0))
    {
       std::cout << "Problème sur setItsCurrentPokemon" << std::endl;
    }

    // check: getItsPokemons()
    if (trainer->getItsPokemons()->size() == 0)
    {
        std::cout  << "Problème sur getItsPokemons" << std::endl;
    }

    // check: getItsLevel()
    if (trainer->getItsLevel() == 0)
    {
        std::cout  << "Problème sur getItsLevel" << std::endl;
    }

    // check: getTotalStrengthPower()
    if (trainer->getTotalStrengthPower() == 0)
    {
        std::cout  << "Problème sur getTotalStrengthPower" << std::endl;
    }

    // check: getTotalHealthPoints()
    if (trainer->getTotalHealthPoints() == 0)
    {
        std::cout  << "Problème sur getTotalHealthPoints" << std::endl;
    }

    // check: getAverageAttackSpeed()
    if (trainer->getAverageAttackSpeed() == 0)
    {
        std::cout  << "Problème sur getAverageAttackSpeed" << std::endl;
    }

    // check: getItsName()
    if (trainer->getItsName() == "AA")
    {
        std::cout  << "Problème sur getItsName" << std::endl;
    }

    // check: getItsCurrentPokemon()
    if (trainer->getItsCurrentPokemon() != trainer->getItsPokemons()->at(0))
    {
        std::cout  << "Problème sur getItsCurrentPokemon" << std::endl;
    }

    delete trainer;
    delete game;

    std::cout << std::endl;
}

// TEST: Game
void test_game()
{
    std::cout << "TEST: Game" << std::endl;

    Game* game = new Game();

    // check: start() et canStart()
    game->start(BASIC);

    if (!game->canStart())
    {
        std::cout << "Problème sur start ou canStart" << std::endl;
    }

    // check: setItsWinner() et getItsWinner()
    game->setItsWinner("aaaa");

    if (game->getItsWinner() != "aaaa")
    {
        std::cout << "Problème sur setItsWinner ou getItsWinner" << std::endl;
    }

    // check: setItsState()
    game->setItsState(FINISH);

    if (game->getItsState() != FINISH)
    {
        std::cout << "Problème sur setItsState ou getItsState" << std::endl;
    }

    // check: getItsFirstTrainer()
    if (game->getItsFirstTrainer() == nullptr)
    {
        std::cout << "Problème sur getItsFirstTrainer" << std::endl;
    }

    // check: getItsSecondTrainer()
    if (game->getItsSecondTrainer() == nullptr)
    {
        std::cout << "Problème sur getItsSecondTrainer" << std::endl;
    }

    // check: getItsDatabaseManager()
    if (game->getItsDatabaseManager() == nullptr)
    {
        std::cout << "Problème sur getItsDatabaseManager" << std::endl;
    }

    delete game;

    std::cout << std::endl;
}
