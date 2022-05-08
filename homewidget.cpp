/*****************************************************************************
 * homewidget.cpp
 *
 * Created: 07/05/2022 2022 by sinyx
 *
 * Copyright 2022 sinyx. All rights reserved.
 *
 * This file may be distributed under the terms of GNU Public License version
 * 3 (GPL v3) as defined by the Free Software Foundation (FSF). A copy of the
 * license should have been included with this file, or the project in which
 * this file belongs to. You may also find the details of GPL v3 at:
 * http://www.gnu.org/licenses/gpl-3.0.txt
 *
 * If you have any questions regarding the use of this file, feel free to
 * contact the author of this file, or the owner of the project in which
 * this file belongs to.
 *****************************************************************************/
#include "databasemanager.h"
#include "game.h"
#include "homewidget.h"
#include "trainer.h"
#include "ui_homewidget.h"

#include <QString>
#include <QSqlRecord>
#include <QList>

HomeWidget::HomeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomeWidget)
{
    ui->setupUi(this);

    // TODO: voir pour opti
    fireTypePokemonsModel = new QSqlTableModel(0, DatabaseManager().getItsInstance()->getItsDatabase());
    fireTypePokemonsModel->setTable("fire_pokemons");
    fireTypePokemonsModel->select();

    plantTypePokemonsModel = new QSqlTableModel(0, DatabaseManager().getItsInstance()->getItsDatabase());
    plantTypePokemonsModel->setTable("plant_pokemons");
    plantTypePokemonsModel->select();

    electrikTypePokemonsModel = new QSqlTableModel(0, DatabaseManager().getItsInstance()->getItsDatabase());
    electrikTypePokemonsModel->setTable("electrik_pokemons");
    electrikTypePokemonsModel->select();

    waterTypePokemonsModel = new QSqlTableModel(0, DatabaseManager().getItsInstance()->getItsDatabase());
    waterTypePokemonsModel->setTable("water_pokemons");
    waterTypePokemonsModel->select();

    ui->firePokemonsTableView->setModel(fireTypePokemonsModel);
    ui->firePokemonsTableView->setAlternatingRowColors(true);
    ui->firePokemonsTableView->show();

    ui->plantPokemonsTableView->setModel(plantTypePokemonsModel);
    ui->plantPokemonsTableView->setAlternatingRowColors(true);
    ui->plantPokemonsTableView->show();

    ui->electrikPokemonsTableView->setModel(electrikTypePokemonsModel);
    ui->electrikPokemonsTableView->setAlternatingRowColors(true);
    ui->electrikPokemonsTableView->show();

    ui->waterPokemonsTableView->setModel(waterTypePokemonsModel);
    ui->waterPokemonsTableView->setAlternatingRowColors(true);
    ui->waterPokemonsTableView->show();
}

HomeWidget::~HomeWidget()
{
    delete ui;
}

Ui::HomeWidget *HomeWidget::getUi() const
{
    return ui;
}

void HomeWidget::on_addPokemon_clicked()
{
    int dresser = ui->targetedTrainer->currentIndex();
    Trainer* currentTrainer;
    QListWidget* currentTrainerTeam;

    if (dresser == 0)
    {
        currentTrainer = Game().getItsInstance()->getItsFirstTrainer();
        currentTrainerTeam = ui->trainer1Team;
    }
    else
    {
        currentTrainer = Game().getItsInstance()->getItsSecondTrainer();
        currentTrainerTeam = ui->trainer2Team;
    }

    // checker que le dresseur a pas déjà 6 pokemons
    if (currentTrainer->getItsPokemons()->size() < 6)
    {
        // TODO: voir pour opti le code dessous car dégeu

        int electrikSelectedID = ui->electrikPokemonsTableView->currentIndex().row();

        if (electrikSelectedID != -1)
        {
            QString pokemonName = electrikTypePokemonsModel->record(electrikSelectedID).value("name").toString();
            currentTrainerTeam->addItem(pokemonName);
            //TODO: optimiser le get du pokemon via la bd (mettre un cache?)
            currentTrainer->addPokemon(DatabaseManager().getItsInstance()->getElectrikTypePokemons()->at(electrikSelectedID));
        }

        int fireSelectedID = ui->firePokemonsTableView->currentIndex().row();

        if (fireSelectedID != -1)
        {
            QString pokemonName = fireTypePokemonsModel->record(fireSelectedID).value("name").toString();
            currentTrainerTeam->addItem(pokemonName);
            //TODO: optimiser le get du pokemon via la bd (mettre un cache?)
            currentTrainer->addPokemon(DatabaseManager().getItsInstance()->getFireTypePokemons()->at(fireSelectedID));
        }

        int waterSelectedID = ui->waterPokemonsTableView->currentIndex().row();

        if (waterSelectedID != -1)
        {
            QString pokemonName = waterTypePokemonsModel->record(waterSelectedID).value("name").toString();

            currentTrainerTeam->addItem(pokemonName);
            //TODO: optimiser le get du pokemon via la bd (mettre un cache?)
            currentTrainer->addPokemon(DatabaseManager().getItsInstance()->getWaterTypePokemons()->at(waterSelectedID));
        }

        int plantSelectedID = ui->plantPokemonsTableView->currentIndex().row();

        if (plantSelectedID != -1)
        {
            QString pokemonName = plantTypePokemonsModel->record(plantSelectedID).value("name").toString();

            currentTrainerTeam->addItem(pokemonName);
            //TODO: optimiser le get du pokemon via la bd (mettre un cache?)
            currentTrainer->addPokemon(DatabaseManager().getItsInstance()->getPlantTypePokemons()->at(plantSelectedID));
        }

        qDebug() << electrikSelectedID;
    }
}


void HomeWidget::on_removePokemon_clicked()
{
    // todo: passer le dresser en attribut pour les autres fonctions
    int dresser = ui->targetedTrainer->currentIndex();
    Trainer* currentTrainer;
    QListWidget* currentTrainerTeam;

    if (dresser == 0)
    {
        currentTrainer = Game().getItsInstance()->getItsFirstTrainer();
        currentTrainerTeam = ui->trainer1Team;
    }
    else
    {
        currentTrainer = Game().getItsInstance()->getItsSecondTrainer();
        currentTrainerTeam = ui->trainer2Team;
    }

    std::string selectedPokemonName = currentTrainerTeam->currentItem()->text().toStdString();

    for (Pokemon* pokemonOwned : *currentTrainer->getItsPokemons())
    {
        if (pokemonOwned->getItsName() == selectedPokemonName)
        {
            currentTrainer->removePokemon(pokemonOwned);
            break;
        }
    }

    currentTrainerTeam->takeItem(currentTrainerTeam->currentRow());
}


void HomeWidget::on_startGame_clicked()
{
    // todo: opti le code

    // on vérifie que les 2 dresseurs ont 6 pokemons
    if (Game().getItsInstance()->getItsFirstTrainer()->getItsPokemons()->size() == 6
        && Game().getItsInstance()->getItsSecondTrainer()->getItsPokemons()->size() == 6)
    {
        qDebug() << "GOooooooo";
        // on regarde si les noms des dresseurs ont été définis
        std::string firstTrainerName = ui->trainer1Name->text().toStdString();

        if (firstTrainerName != "")
        {
            Game().getItsInstance()->getItsFirstTrainer()->setItsName(firstTrainerName);
        }

        std::string secondTrainerName = ui->trainer2Name->text().toStdString();

        if (secondTrainerName != "")
        {
            Game().getItsInstance()->getItsSecondTrainer()->setItsName(secondTrainerName);
        }

        int aiType = ui->aiType->currentIndex();

        Game().getItsInstance()->start(static_cast<AIType>(aiType));
    }
}


void HomeWidget::on_generatePokemon_clicked()
{
    // todo: passer le dresser en attribut pour les autres fonctions
    int dresser = ui->targetedTrainer->currentIndex();
    Trainer* currentTrainer;
    QListWidget* currentTrainerTeam;

    if (dresser == 0)
    {
        currentTrainer = Game().getItsInstance()->getItsFirstTrainer();
        currentTrainerTeam = ui->trainer1Team;
    }
    else
    {
        currentTrainer = Game().getItsInstance()->getItsSecondTrainer();
        currentTrainerTeam = ui->trainer2Team;
    }

    if (currentTrainer->getItsPokemons()->size() == 0)
    {
        std::vector<Pokemon*>* trainerPokemons = currentTrainer->generatePokemons();

        for (Pokemon* pokemon : *trainerPokemons)
        {
            currentTrainerTeam->addItem(QString::fromStdString(pokemon->getItsName()));
        }
    }
}

