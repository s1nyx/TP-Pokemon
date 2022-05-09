/*****************************************************************************
 * %{Cpp:License:FileName}
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
#include "widget.h"
#include "ui_widget.h"
#include "attackwidget.h"
#include "ui_attackwidget.h"
#include "homewidget.h"
#include "ui_homewidget.h"
#include "finishwidget.h"
#include "game.h"

#include <QEvent>
#include <qboxlayout.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget), currentWidget(HOME)
{
    ui->setupUi(this);
    // désactive le resize
    setWindowFlags(Qt::Widget | Qt::MSWindowsFixedSizeDialogHint);

    // initialisation du système de navigation
    AttackWidget* attackWidget = new AttackWidget();
    HomeWidget* homeWidget = new HomeWidget();
    FinishWidget* finishWidget = new FinishWidget();

    stackedWidget = new QStackedWidget();
    stackedWidget->addWidget(homeWidget);
    stackedWidget->addWidget(attackWidget);
    stackedWidget->addWidget(finishWidget);

    connect(homeWidget->getUi()->startGame, SIGNAL(clicked()), this, SLOT(navigate()));
    connect(homeWidget->getUi()->startGame, SIGNAL(clicked()), attackWidget, SLOT(start()));
    connect(attackWidget, SIGNAL(gameFinished()), this, SLOT(navigate()));
    connect(attackWidget, SIGNAL(gameFinished()), finishWidget, SLOT(start()));

    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(stackedWidget);

    setLayout(layout);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::navigate()
{
    // TODO: remplacer l'enum par celle du game?
    if (Game().getItsInstance()->canStart())
    {
        if (currentWidget == HOME)
        {
             currentWidget = ATTACK;
        }
        else if (currentWidget == ATTACK)
        {
            currentWidget = FINISHED;
        }

        stackedWidget->setCurrentIndex(currentWidget);
    }
}

