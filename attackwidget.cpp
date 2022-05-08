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
#define GAME_TIME 1000

AttackWidget::AttackWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AttackWidget)
{
    itsTimer = new QTimer();
    itsRemainingTime = new QTimer();

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
    if (Game().getItsInstance()->getItsFirstTrainer()->getTotalHealthPoints() == 0 || Game().getItsInstance()->getItsSecondTrainer() == 0)
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

        if (currentTrainer->getCurrentPokemon()->isDead())
        {
            qDebug() << "Change POK";
            currentTrainer->choosePokemon();
            updatePokemons();
        }

        currentTrainer->getCurrentPokemon()->attack(opponent->getCurrentPokemon());
        updateDataShowed();
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

void AttackWidget::updateDataShowed()
{
    ui->trainer1TotalHP->setText(QString::number(Game().getItsInstance()->getItsFirstTrainer()->getTotalHealthPoints()));
    ui->trainer2TotalHP->setText(QString::number(Game().getItsInstance()->getItsSecondTrainer()->getTotalHealthPoints()));

    ui->trainer1PokemonHP->setText(QString::number(Game().getItsInstance()->getItsFirstTrainer()->getCurrentPokemon()->getHpPercentage()) + "% de vie");
    ui->trainer2PokemonHP->setText(QString::number(Game().getItsInstance()->getItsSecondTrainer()->getCurrentPokemon()->getHpPercentage()) + "% de vie");
}
