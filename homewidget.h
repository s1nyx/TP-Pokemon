#ifndef HOMEWIDGET_H
#define HOMEWIDGET_H

#include "game.h"

#include <QLabel>
#include <QListWidget>
#include <QSqlTableModel>
#include <QWidget>

namespace Ui {
class HomeWidget;
}

class HomeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HomeWidget(QWidget *parent = nullptr, Game* game = nullptr);
    ~HomeWidget();

    Ui::HomeWidget *getUi() const;

private slots:
    void on_addPokemon_clicked();
    void on_removePokemon_clicked();
    void on_startGame_clicked();
    void on_generatePokemon_clicked();

    void on_targetedTrainer_currentIndexChanged(int index);

private:
    Ui::HomeWidget *ui;
    Game* itsGame;
    QSqlTableModel* itsFireTypePokemonsModel;
    QSqlTableModel* itsWaterTypePokemonsModel;
    QSqlTableModel* itsElectrikTypePokemonsModel;
    QSqlTableModel* itsPlantTypePokemonsModel;

    Trainer* itsCurrentTrainer;
    QLabel* itsCurrentTrainerHPTotal;
    QLabel* itsCurrentTrainerCPTotal;
    QLabel* itsCurrentTrainerSpeedAvg;
    QListWidget* itsCurrentTrainerTeam;

    void generateTeamData();
};

#endif // HOMEWIDGET_H
