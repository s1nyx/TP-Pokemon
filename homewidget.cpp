#include "databasemanager.h"
#include "game.h"
#include "homewidget.h"
#include "trainer.h"
#include "ui_homewidget.h"

#include <QString>
#include <QSqlRecord>
#include <QList>

/*!
 * \brief HomeWidget::HomeWidget
 * \param parent
 */
HomeWidget::HomeWidget(QWidget *parent, Game* game) :
    QWidget(parent),
    ui(new Ui::HomeWidget)
{
    itsGame = game;
    ui->setupUi(this);
    on_targetedTrainer_currentIndexChanged(0);

    // Connexion entre la base de donnée et les models
    itsFireTypePokemonsModel = new QSqlTableModel(0, itsGame->getItsDatabaseManager()->getItsDatabase());
    itsFireTypePokemonsModel->setTable("fire_pokemons");
    itsFireTypePokemonsModel->select();

    itsPlantTypePokemonsModel = new QSqlTableModel(0, itsGame->getItsDatabaseManager()->getItsDatabase());
    itsPlantTypePokemonsModel->setTable("plant_pokemons");
    itsPlantTypePokemonsModel->select();

    itsElectrikTypePokemonsModel = new QSqlTableModel(0, itsGame->getItsDatabaseManager()->getItsDatabase());
    itsElectrikTypePokemonsModel->setTable("electrik_pokemons");
    itsElectrikTypePokemonsModel->select();

    itsWaterTypePokemonsModel = new QSqlTableModel(0, itsGame->getItsDatabaseManager()->getItsDatabase());
    itsWaterTypePokemonsModel->setTable("water_pokemons");
    itsWaterTypePokemonsModel->select();

    // Connexion entre les models et les tableviews
    ui->firePokemonsTableView->setModel(itsFireTypePokemonsModel);
    ui->firePokemonsTableView->setAlternatingRowColors(true);
    ui->firePokemonsTableView->show();

    ui->plantPokemonsTableView->setModel(itsPlantTypePokemonsModel);
    ui->plantPokemonsTableView->setAlternatingRowColors(true);
    ui->plantPokemonsTableView->show();

    ui->electrikPokemonsTableView->setModel(itsElectrikTypePokemonsModel);
    ui->electrikPokemonsTableView->setAlternatingRowColors(true);
    ui->electrikPokemonsTableView->show();

    ui->waterPokemonsTableView->setModel(itsWaterTypePokemonsModel);
    ui->waterPokemonsTableView->setAlternatingRowColors(true);
    ui->waterPokemonsTableView->show();
}

/*!
 * \brief HomeWidget::~HomeWidget
 */
HomeWidget::~HomeWidget()
{
    delete ui;
    delete itsFireTypePokemonsModel;
    delete itsWaterTypePokemonsModel;
    delete itsElectrikTypePokemonsModel;
    delete itsPlantTypePokemonsModel;
    delete itsCurrentTrainer;
    delete itsCurrentTrainerHPTotal;
    delete itsCurrentTrainerCPTotal;
    delete itsCurrentTrainerSpeedAvg;
    delete itsCurrentTrainerTeam;
}

/*!
 * Renvoie l'UI
 * \brief HomeWidget::getUi
 * \return
 */
Ui::HomeWidget *HomeWidget::getUi() const
{
    return ui;
}

/*!
 * Slot détectant lorsqu'un pokemon est ajouté
 * \brief HomeWidget::on_addPokemon_clicked
 */
void HomeWidget::on_addPokemon_clicked()
{
    // checker que le dresseur a pas déjà 6 pokemons
    if (itsCurrentTrainer->getItsPokemons()->size() == 6)
    {
        ui->errorInput->setText("Vous possédez déjà 6 pokemons !");
    }
    else
    {
        bool hasSelectedOne = false;
        int electrikSelectedID = ui->electrikPokemonsTableView->currentIndex().row();
        QString pokemonName;

        // Si un pokemon electrik est sélectionné
        if (electrikSelectedID != -1)
        {
            hasSelectedOne = true;

            pokemonName = itsElectrikTypePokemonsModel->record(electrikSelectedID).value("name").toString();
            itsCurrentTrainer->addPokemon(itsGame->getItsDatabaseManager()->getElectrikTypePokemons()->at(electrikSelectedID));
        }

        int fireSelectedID = ui->firePokemonsTableView->currentIndex().row();

        // Si un pokemon feu est sélectionné
        if (fireSelectedID != -1)
        {
            if (!hasSelectedOne) hasSelectedOne = true;

            pokemonName = itsFireTypePokemonsModel->record(fireSelectedID).value("name").toString();
            itsCurrentTrainer->addPokemon(itsGame->getItsDatabaseManager()->getFireTypePokemons()->at(fireSelectedID));
        }

        int waterSelectedID = ui->waterPokemonsTableView->currentIndex().row();

        // Si un pokemon eau est sélectionné
        if (waterSelectedID != -1)
        {
            if (!hasSelectedOne) hasSelectedOne = true;

            pokemonName = itsWaterTypePokemonsModel->record(waterSelectedID).value("name").toString();
            itsCurrentTrainer->addPokemon(itsGame->getItsDatabaseManager()->getWaterTypePokemons()->at(waterSelectedID));
        }

        int plantSelectedID = ui->plantPokemonsTableView->currentIndex().row();

        // Si un pokemon plante est sélectionné
        if (plantSelectedID != -1)
        {
            if (!hasSelectedOne) hasSelectedOne = true;

            pokemonName = itsPlantTypePokemonsModel->record(plantSelectedID).value("name").toString();
            itsCurrentTrainer->addPokemon(itsGame->getItsDatabaseManager()->getPlantTypePokemons()->at(plantSelectedID));
        }

        if (!hasSelectedOne)
        {
            ui->errorInput->setText("Vous devez sélectionner au minmum 1 pokemon sur 6");
        }
        else
        {
            itsCurrentTrainerTeam->addItem(pokemonName);
            generateTeamData();
        }
    }
}

/*!
 * Slot détectant lorsqu'un pokemon est retiré
 * \brief HomeWidget::on_removePokemon_clicked
 */
void HomeWidget::on_removePokemon_clicked()
{
    if (itsCurrentTrainerTeam->currentItem() == nullptr)
    {
        ui->errorInput->setText("Vous n'avez pas sélectionné de pokemon !");
    }
    else
    {
        QString selectedPokemonName = itsCurrentTrainerTeam->currentItem()->text();

        // vérifie qu'il a au moins 2XP
        bool canRemovePokemon = false;

        for (Pokemon* pokemonOwned : *itsCurrentTrainer->getItsPokemons())
        {
            if (pokemonOwned->getItsName() == selectedPokemonName)
            {
                canRemovePokemon = itsCurrentTrainer->removePokemon(pokemonOwned);
                break;
            }
        }

        if (!canRemovePokemon)
        {
            ui->errorInput->setText("Vous n'avez plus assez d'XP pour retirer un pokemon");
        }
        else
        {
            itsCurrentTrainerTeam->takeItem(itsCurrentTrainerTeam->currentRow());
            generateTeamData();
        }
    }
}

/*!
 * Slot détectant lorsque la partie commence
 * \brief HomeWidget::on_startGame_clicked
 */
void HomeWidget::on_startGame_clicked()
{
    // on vérifie que les 2 dresseurs ont 6 pokemons
    if (itsGame->getItsFirstTrainer()->getItsPokemons()->size() != 6
        || itsGame->getItsSecondTrainer()->getItsPokemons()->size() != 6)
    {
        ui->errorInput->setText("Vous n'avez pas choisi les pokemons des dresseurs !");
    }
    else
    {
        qDebug() << "GOooooooo";
        // on regarde si les noms des dresseurs ont été définis
        QString firstTrainerName = ui->trainer1Name->text();

        if (firstTrainerName != "")
        {
            itsGame->getItsFirstTrainer()->setItsName(firstTrainerName);
        }

        QString secondTrainerName = ui->trainer2Name->text();

        if (secondTrainerName != "")
        {
            itsGame->getItsSecondTrainer()->setItsName(secondTrainerName);
        }

        int aiType = ui->aiType->currentIndex();

        itsGame->start(static_cast<AIType>(aiType));
    }
}

/*!
 * Slot détectant lorsqu'on souhaite générer la liste des pokemons
 * \brief HomeWidget::on_generatePokemon_clicked
 */
void HomeWidget::on_generatePokemon_clicked()
{
    if (itsCurrentTrainer->getItsPokemons()->size() == 6)
    {
        ui->errorInput->setText("Vous possédez déjà 6 pokemons !");
    }
    else
    {
        itsCurrentTrainer->getItsPokemons()->clear();
        itsCurrentTrainerTeam->clear();

        std::vector<Pokemon*>* trainerPokemons = itsCurrentTrainer->generatePokemons(itsGame);

        for (Pokemon* pokemon : *trainerPokemons)
        {
            itsCurrentTrainerTeam->addItem(pokemon->getItsName());
        }

        generateTeamData();
    }
}

/*!
 * Met à jour les informations affichés sur l'UI
 * \brief HomeWidget::generateTeamData
 * \param trainerID
 */
void HomeWidget::generateTeamData()
{
    itsCurrentTrainerHPTotal->setText(QString::number(itsCurrentTrainer->getTotalHealthPoints()));
    itsCurrentTrainerCPTotal->setText(QString::number(itsCurrentTrainer->getTotalStrengthPower()));
    itsCurrentTrainerSpeedAvg->setText(QString::number(itsCurrentTrainer->getAverageAttackSpeed()));

    unsigned int firstTrainerProbability = itsGame->getItsFirstTrainer()->getTotalStrengthPower() / itsGame->getItsFirstTrainer()->getTotalHealthPoints() * 100;
    unsigned int opponentTrainerProbability = itsGame->getItsSecondTrainer()->getTotalStrengthPower() / itsGame->getItsSecondTrainer()->getTotalHealthPoints() * 100;

    if (firstTrainerProbability > opponentTrainerProbability)
    {
        ui->potentialWinner->setText(itsGame->getItsFirstTrainer()->getItsName() + " (" + QString::number(firstTrainerProbability) + "%)");
    }
    else if (firstTrainerProbability < opponentTrainerProbability)
    {
        ui->potentialWinner->setText(itsGame->getItsSecondTrainer()->getItsName() + " (" + QString::number(opponentTrainerProbability) + "%)");
    }
    else
    {
        ui->potentialWinner->setText("50-50");
    }
}

/*!
 * Met à jour les pointeurs en fonction du dresseur que l'on souhaite modifier
 * \brief HomeWidget::on_targetedTrainer_currentIndexChanged
 * \param index
 */
void HomeWidget::on_targetedTrainer_currentIndexChanged(int index)
{
    if (index == 0)
    {
        itsCurrentTrainer = itsGame->getItsFirstTrainer();
        itsCurrentTrainerTeam = ui->trainer1Team;
        itsCurrentTrainerHPTotal = ui->trainer1TotalHP;
        itsCurrentTrainerCPTotal = ui->trainer1TotalCP;
        itsCurrentTrainerSpeedAvg = ui->trainer1SpeedAvg;
    }
    else
    {
        itsCurrentTrainer = itsGame->getItsSecondTrainer();
        itsCurrentTrainerTeam = ui->trainer2Team;
        itsCurrentTrainerHPTotal = ui->trainer2TotalHP;
        itsCurrentTrainerCPTotal = ui->trainer2TotalCP;
        itsCurrentTrainerSpeedAvg = ui->trainer2SpeedAvg;
    }
}

