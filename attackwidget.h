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
    explicit AttackWidget(QWidget *parent = nullptr, Game* game = nullptr);
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
    Game* itsGame;
    Trainer* itsCurrentTrainer;
    QTimer* itsTimer;
    QTimer* itsRemainingTime;
    int itsTimeCounter;

    void updatePokemons();
    void updateDataShowed();
};

#endif // ATTACKWIDGET_H
