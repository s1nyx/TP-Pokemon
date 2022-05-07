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
#include "homewidget.h"
#include "ui_homewidget.h"

HomeWidget::HomeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomeWidget)
{
    ui->setupUi(this);

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
