#include "attackwidget.h"
#include "ui_attackwidget.h"
#include <QTimer>
#define GAME_TIME 1000

/*!
 * \brief AttackWidget::AttackWidget
 * \param parent
 */
AttackWidget::AttackWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AttackWidget)
{
    itsTimer = new QTimer();
    itsRemainingTime = new QTimer();

    ui->setupUi(this);

    currentTrainer = Game().getItsInstance()->getItsFirstTrainer();
}

/*!
 * \brief AttackWidget::~AttackWidget
 */
AttackWidget::~AttackWidget()
{
    delete ui;
    delete currentTrainer;
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

void AttackWidget::start()
{
    ui->trainer1Name->setText(Game().getItsInstance()->getItsFirstTrainer()->getItsName() + " (Niv. " + QString::number(Game().getItsInstance()->getItsFirstTrainer()->getItsLevel()) + " / " + QString::number(Game().getItsInstance()->getItsFirstTrainer()->getItsXP()) + " Exp.)");
    ui->trainer2Name->setText(Game().getItsInstance()->getItsSecondTrainer()->getItsName() + " (Niv. " + QString::number(Game().getItsInstance()->getItsSecondTrainer()->getItsLevel()) + " / " + QString::number(Game().getItsInstance()->getItsSecondTrainer()->getItsXP()) + " Exp.)");

    updatePokemons();

    itsTimer->start(GAME_TIME);
    itsRemainingTime->start(1000);

    itsTimeCounter = GAME_TIME / 1000;
    ui->lcdNumber->display(itsTimeCounter);

    connect(itsTimer, SIGNAL(timeout()), this, SLOT(gameLoop()));
    connect(itsRemainingTime, SIGNAL(timeout()), this, SLOT(onTick()));
}

void AttackWidget::onTick()
{
    itsTimeCounter -= 1;

    if (itsTimeCounter == 0) itsTimeCounter = GAME_TIME / 1000;
    ui->lcdNumber->display(itsTimeCounter);
}

void AttackWidget::gameLoop()
{
    if (Game().getItsInstance()->getItsFirstTrainer()->getTotalHealthPoints() == 0 || Game().getItsInstance()->getItsSecondTrainer()->getTotalHealthPoints() == 0)
    {
        itsTimer->stop();
        itsRemainingTime->stop();
        qDebug() << "FIN";

        QString winner;

        if (Game().getItsInstance()->getItsFirstTrainer()->getTotalHealthPoints() == 0)
        {
            winner = Game().getItsInstance()->getItsSecondTrainer()->getItsName();
        }
        else
        {
            winner = Game().getItsInstance()->getItsFirstTrainer()->getItsName();
        }

        Game().getItsInstance()->setItsWinner(winner);
        emit gameFinished();
    }
    else
    {
        Trainer* opponent = currentTrainer == Game().getItsInstance()->getItsFirstTrainer() ? Game().getItsInstance()->getItsSecondTrainer() : Game().getItsInstance()->getItsFirstTrainer();
        bool noMorePokemon = false;

        if (currentTrainer->getItsCurrentPokemon()->isDead())
        {
            qDebug() << "Change POK ";

            currentTrainer->choosePokemon();
            if (currentTrainer->getItsCurrentPokemon()->isDead())
            {
                noMorePokemon = true;
            }
            else
            {
                updatePokemons();
            }
        }

        if (!noMorePokemon)
        {
            currentTrainer->getItsCurrentPokemon()->attack(opponent->getItsCurrentPokemon());
            updateDataShowed();
            qDebug() << "attack";

            if (currentTrainer->getItsCurrentPokemon()->hasKoOneAttack())
            {
                qDebug() << "Oneshot";
                currentTrainer->addXP(3);
                opponent->removeXP(1);
            }

            currentTrainer = opponent;
        }
    }
}

void AttackWidget::updatePokemons()
{
    QPixmap pix1(":/images/images/" + Game().getItsInstance()->getItsFirstTrainer()->getItsCurrentPokemon()->getItsName() + ".png");
    pix1 = pix1.scaled(130, 80);
    ui->trainer1Pokemon->setPixmap(pix1);
    ui->trainer1Pokemon->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    ui->trainer1PokemonDescription->setText(Game().getItsInstance()->getItsFirstTrainer()->getItsCurrentPokemon()->getDescription());

    QPixmap pix2(":/images/images/" + Game().getItsInstance()->getItsSecondTrainer()->getItsCurrentPokemon()->getItsName() + ".png");
    pix2 = pix2.scaled(130, 80);
    ui->trainer2Pokemon->setPixmap(pix2);
    ui->trainer2Pokemon->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    ui->trainer2PokemonDescription->setText(Game().getItsInstance()->getItsSecondTrainer()->getItsCurrentPokemon()->getDescription());

    ui->trainer1Name->setText(Game().getItsInstance()->getItsFirstTrainer()->getItsName() + " (Niv. " + QString::number(Game().getItsInstance()->getItsFirstTrainer()->getItsLevel()) + " / " + QString::number(Game().getItsInstance()->getItsFirstTrainer()->getItsXP()) + " Exp.)");
    ui->trainer2Name->setText(Game().getItsInstance()->getItsSecondTrainer()->getItsName() + " (Niv. " + QString::number(Game().getItsInstance()->getItsSecondTrainer()->getItsLevel()) + " / " + QString::number(Game().getItsInstance()->getItsSecondTrainer()->getItsXP()) + " Exp.)");
}

void AttackWidget::updateDataShowed()
{
    ui->trainer1TotalHP->setText(QString::number(Game().getItsInstance()->getItsFirstTrainer()->getTotalHealthPoints()));
    ui->trainer2TotalHP->setText(QString::number(Game().getItsInstance()->getItsSecondTrainer()->getTotalHealthPoints()));

    ui->trainer1PokemonHP->setText(QString::number(Game().getItsInstance()->getItsFirstTrainer()->getItsCurrentPokemon()->getHpPercentage()) + "% de vie");
    ui->trainer2PokemonHP->setText(QString::number(Game().getItsInstance()->getItsSecondTrainer()->getItsCurrentPokemon()->getHpPercentage()) + "% de vie");
}
