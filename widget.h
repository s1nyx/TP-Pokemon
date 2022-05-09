#ifndef WIDGET_H
#define WIDGET_H

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
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void navigate();

private:
    Ui::Widget *ui;
    WidgetType currentWidget;
    QStackedWidget* stackedWidget;
};
#endif // WIDGET_H
