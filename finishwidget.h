#ifndef FINISHWIDGET_H
#define FINISHWIDGET_H

#include "game.h"

#include <QWidget>

namespace Ui {
    class FinishWidget;
}

class FinishWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FinishWidget(QWidget *parent = nullptr, Game* game = nullptr);
    ~FinishWidget();

public slots:
    void start();

private slots:
    void on_save_clicked();

private:
    Ui::FinishWidget *ui;
    Game* itsGame;
};

#endif // FINISHWIDGET_H
