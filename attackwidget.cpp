/*****************************************************************************
 * attackwidget.cpp
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
#include "attackwidget.h"
#include "ui_attackwidget.h"

#include <QTimer>

AttackWidget::AttackWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AttackWidget)
{
    itsTimer = new QTimer();
    ui->setupUi(this);
    currentTrainer = Game().getItsInstance()->getItsFirstTrainer();
}

AttackWidget::~AttackWidget()
{
    delete ui;
}

Ui::AttackWidget *AttackWidget::getUi() const
{
    return ui;
}

void AttackWidget::start()
{
    ui->trainer1Name->setText(Game().getItsInstance()->getItsFirstTrainer()->getItsName());
    ui->trainer2Name->setText(Game().getItsInstance()->getItsSecondTrainer()->getItsName());

    updatePokemons();

    itsTimer->start(1000);
    connect(itsTimer, SIGNAL(timeout()), this, SLOT(gameLoop()));
}

void AttackWidget::gameLoop()
{
    // loop du jeu
    // tant que les pokemons du dresseur 1 et du dresseur sont en vie on continue
    // On attaque l'autre pokemons si il est encore vivant
    // Sinon, on change de pokemon (le dresseur qui a le pokemon mort si il en reste pas mort)

    if (Game().getItsInstance()->getItsFirstTrainer()->getTotalHealthPoints() == 0 || Game().getItsInstance()->getItsSecondTrainer() == 0)
    {
        itsTimer->stop();
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

        if (currentTrainer->getCurrentPokemon()->isDead())
        {
            qDebug() << "Change POK";
            currentTrainer->choosePokemon();
            updatePokemons();
        }

        currentTrainer->getCurrentPokemon()->attack(opponent->getCurrentPokemon());
        qDebug() << "attack";

        if (currentTrainer->getCurrentPokemon()->hasKoOneAttack())
        {
            qDebug() << "Oneshot";
            currentTrainer->addXP(3);
            opponent->removeXP(1);
        }

        currentTrainer = opponent;
    }
}

void AttackWidget::updatePokemons()
{
    QPixmap pix1(":/images/images/" + Game().getItsInstance()->getItsFirstTrainer()->getCurrentPokemon()->getItsName() + ".png");
    pix1 = pix1.scaled(130, 80);
    ui->trainer1Pokemon->setPixmap(pix1);
    ui->trainer1Pokemon->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    ui->trainer1PokemonDescription->setText(Game().getItsInstance()->getItsFirstTrainer()->getCurrentPokemon()->getDescription());

    QPixmap pix2(":/images/images/" + Game().getItsInstance()->getItsSecondTrainer()->getCurrentPokemon()->getItsName() + ".png");
    pix2 = pix2.scaled(130, 80);
    ui->trainer2Pokemon->setPixmap(pix2);
    ui->trainer2Pokemon->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    ui->trainer2PokemonDescription->setText(Game().getItsInstance()->getItsSecondTrainer()->getCurrentPokemon()->getDescription());
}
