#ifndef WIDGET_H
#define WIDGET_H

#include <game.h>

#include <QStackedWidget>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

// Widgets à afficher
enum WidgetType
{
    HOME,
    ATTACK,
    FINISHED
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr, Game* game = nullptr);
    ~Widget();

private slots:
    void navigate();

private:
    Ui::Widget *ui;
    Game* itsGame;
    WidgetType itsCurrentWidget;
    QStackedWidget* itsStackedWidget;
};
#endif // WIDGET_H
