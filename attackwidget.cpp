#include "attackwidget.h"
#include "ui_attackwidget.h"

#include <QTimer>

#define GAME_TIME 1000

/*!
 * \brief AttackWidget::AttackWidget
 * \param parent
 */
AttackWidget::AttackWidget(QWidget *parent, Game* game) :
    QWidget(parent),
    ui(new Ui::AttackWidget)
{
    itsGame = game;
    itsTimer = new QTimer();
    itsRemainingTime = new QTimer();

    ui->setupUi(this);

    itsCurrentTrainer = itsGame->getItsFirstTrainer();
}

/*!
 * \brief AttackWidget::~AttackWidget
 */
AttackWidget::~AttackWidget()
{
    delete ui;
    delete itsCurrentTrainer;
    delete itsTimer;
    delete itsRemainingTime;
}

/*!
 * Renvoie l'UI
 * \brief AttackWidget::getUi
 * \return
 */
Ui::AttackWidget *AttackWidget::getUi() const
{
    return ui;
}

/*!
 * Lance la partie
 * \brief AttackWidget::start
 */
void AttackWidget::start()
{
    ui->trainer1Name->setText(itsGame->getItsFirstTrainer()->getItsName() + " (Niv. " + QString::number(itsGame->getItsFirstTrainer()->getItsLevel()) + " / " + QString::number(itsGame->getItsFirstTrainer()->getItsXP()) + " Exp.)");
    ui->trainer2Name->setText(itsGame->getItsSecondTrainer()->getItsName() + " (Niv. " + QString::number(itsGame->getItsSecondTrainer()->getItsLevel()) + " / " + QString::number(itsGame->getItsSecondTrainer()->getItsXP()) + " Exp.)");

    updatePokemons();

    itsTimer->start(GAME_TIME);
    itsRemainingTime->start(1000);

    itsTimeCounter = GAME_TIME / 1000;
    ui->lcdNumber->display(itsTimeCounter);

    connect(itsTimer, SIGNAL(timeout()), this, SLOT(gameLoop()));
    connect(itsRemainingTime, SIGNAL(timeout()), this, SLOT(onTick()));
}

/*!
 * Permet de modifier l'affichage du compteur de l'intervalle de temps d'attaque
 * \brief AttackWidget::onTick
 */
void AttackWidget::onTick()
{
    itsTimeCounter -= 1;

    if (itsTimeCounter == 0) itsTimeCounter = GAME_TIME / 1000;

    ui->lcdNumber->display(itsTimeCounter);
}

/*!
 * Boucle de jeu
 * \brief AttackWidget::gameLoop
 */
void AttackWidget::gameLoop()
{
    Trainer* firstTrainer = itsGame->getItsFirstTrainer();
    Trainer* secondTrainer = itsGame->getItsSecondTrainer();

    // Si une des deux équipes n'a plus de pokemon en vie, c'est finit
    if (firstTrainer->getTotalHealthPoints() == 0 || secondTrainer->getTotalHealthPoints() == 0)
    {
        itsTimer->stop();
        itsRemainingTime->stop();
        qDebug() << "FIN";

        QString winner;

        if (firstTrainer->getTotalHealthPoints() == 0)
        {
            winner = secondTrainer->getItsName();
        }
        else
        {
            winner = firstTrainer->getItsName();
        }

        itsGame->setItsWinner(winner);
        emit gameFinished();
    }
    else
    {
        Trainer* opponent = itsCurrentTrainer == firstTrainer ? secondTrainer : firstTrainer;
        Pokemon* currentPokemon = itsCurrentTrainer->getItsCurrentPokemon();
        bool noMorePokemon = false;

        // Si le pokemon est mort on le change
        if (currentPokemon->isDead())
        {
            qDebug() << "Change Pokemon";

            itsCurrentTrainer->choosePokemon();
            currentPokemon = itsCurrentTrainer->getItsCurrentPokemon();

            if (currentPokemon->isDead())
            {
                noMorePokemon = true;
            }
            else
            {
                updatePokemons();
            }
        }

        // Si il reste des pokemons on attaque
        if (!noMorePokemon)
        {
            currentPokemon->attack(opponent->getItsCurrentPokemon());
            updateDataShowed();
            qDebug() << "attack";

            if (currentPokemon->hasKoOneAttack())
            {
                qDebug() << "Oneshot";
                itsCurrentTrainer->addXP(3);
                opponent->removeXP(1);
            }

            itsCurrentTrainer = opponent;
        }
    }
}

/*!
 * Permet de mettre à jour les informations des pokemons
 * \brief AttackWidget::updatePokemons
 */
void AttackWidget::updatePokemons()
{
    Trainer* firstTrainer = itsGame->getItsFirstTrainer();
    Trainer* secondTrainer = itsGame->getItsSecondTrainer();

    QPixmap pix1(":/images/images/" + firstTrainer->getItsCurrentPokemon()->getItsName() + ".png");
    pix1 = pix1.scaled(130, 80);
    ui->trainer1Pokemon->setPixmap(pix1);
    ui->trainer1Pokemon->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    ui->trainer1PokemonDescription->setText(firstTrainer->getItsCurrentPokemon()->getDescription());

    QPixmap pix2(":/images/images/" + secondTrainer->getItsCurrentPokemon()->getItsName() + ".png");
    pix2 = pix2.scaled(130, 80);
    ui->trainer2Pokemon->setPixmap(pix2);
    ui->trainer2Pokemon->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    ui->trainer2PokemonDescription->setText(itsGame->getItsSecondTrainer()->getItsCurrentPokemon()->getDescription());

    ui->trainer1Name->setText(firstTrainer->getItsName() + " (Niv. " + QString::number(firstTrainer->getItsLevel()) + " / " + QString::number(firstTrainer->getItsXP()) + " Exp.)");
    ui->trainer2Name->setText(secondTrainer->getItsName() + " (Niv. " + QString::number(secondTrainer->getItsLevel()) + " / " + QString::number(secondTrainer->getItsXP()) + " Exp.)");
}

/*!
 * Permet de mettre à jour les informations du dresseur et la vie du pokemon
 * \brief AttackWidget::updateDataShowed
 */
void AttackWidget::updateDataShowed()
{
    Trainer* firstTrainer = itsGame->getItsFirstTrainer();
    Trainer* secondTrainer = itsGame->getItsSecondTrainer();

    ui->trainer1TotalHP->setText(QString::number(firstTrainer->getTotalHealthPoints()));
    ui->trainer2TotalHP->setText(QString::number(secondTrainer->getTotalHealthPoints()));

    ui->trainer1PokemonHP->setText(QString::number(firstTrainer->getItsCurrentPokemon()->getHpPercentage()) + "% de vie");
    ui->trainer2PokemonHP->setText(QString::number(secondTrainer->getItsCurrentPokemon()->getHpPercentage()) + "% de vie");
}
