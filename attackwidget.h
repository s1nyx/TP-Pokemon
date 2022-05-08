/*****************************************************************************
 * attackwidget.h
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
#ifndef ATTACKWIDGET_H
#define ATTACKWIDGET_H

#include "game.h"
#include <QWidget>

namespace Ui {
class AttackWidget;
}

class AttackWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AttackWidget(QWidget *parent = nullptr);
    ~AttackWidget();

    Ui::AttackWidget *getUi() const;

public slots:
    void start();

signals:
    void gameFinished();

private slots:
    void gameLoop();
    void onTick();

private:
    Ui::AttackWidget *ui;
    Trainer* currentTrainer;
    QTimer* itsTimer;
    QTimer* itsRemainingTime;
    int itsTimeCounter;
    void updatePokemons();
    void updateDataShowed();
};

#endif // ATTACKWIDGET_H
