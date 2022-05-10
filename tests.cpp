#include "pokemon.h"
#include "waterpokemon.h"

#include <iostream>

// TEST: WaterPokemon
void test_waterpokemon()
{
    std::cout << "TEST: WaterPokemon" << std::endl;
    Pokemon* water = new WaterPokemon("a", 1,2,3,4,5);

    if (water->getItsName() != "a")
    {
        std::cout << "Problème sur getItsName" << std::endl;
    }

    if (water->getHpPercentage() == 3)
    {
        std::cout << "Problème sur getHpPercentage" << std::endl;
    }
}

// TEST: PlantPokemon
void test_plantpokemon()
{

}

// TEST: FirePokemon
void test_firepokemon()
{

}

// TEST: ElectrikPokemon
void test_electrikpokemon()
{

}

// TEST: Trainer
void test_trainer()
{

}
