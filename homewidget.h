#ifndef HOMEWIDGET_H
#define HOMEWIDGET_H

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
    explicit HomeWidget(QWidget *parent = nullptr);
    ~HomeWidget();

    Ui::HomeWidget *getUi() const;

private slots:
    void on_addPokemon_clicked();
    void on_removePokemon_clicked();
    void on_startGame_clicked();
    void on_generatePokemon_clicked();

private:
    Ui::HomeWidget *ui;
    QSqlTableModel* fireTypePokemonsModel;
    QSqlTableModel* waterTypePokemonsModel;
    QSqlTableModel* electrikTypePokemonsModel;
    QSqlTableModel* plantTypePokemonsModel;

    void generateTeamData(int trainerID);
};

#endif // HOMEWIDGET_H
