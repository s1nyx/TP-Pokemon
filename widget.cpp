#include "widget.h"
#include "ui_widget.h"
#include "attackwidget.h"
#include "ui_attackwidget.h"
#include "homewidget.h"
#include "ui_homewidget.h"
#include "finishwidget.h"
#include "game.h"

/*!
 * \brief Widget::Widget
 * \param parent
 */
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

    // ajout au widget widget principal
    stackedWidget = new QStackedWidget();
    stackedWidget->addWidget(homeWidget);
    stackedWidget->addWidget(attackWidget);
    stackedWidget->addWidget(finishWidget);

    // connecter les menus entre eux
    connect(homeWidget->getUi()->startGame, SIGNAL(clicked()), this, SLOT(navigate()));
    connect(homeWidget->getUi()->startGame, SIGNAL(clicked()), attackWidget, SLOT(start()));
    connect(attackWidget, SIGNAL(gameFinished()), this, SLOT(navigate()));
    connect(attackWidget, SIGNAL(gameFinished()), finishWidget, SLOT(start()));

    // affiché le QStackedWidget grâce à un VerticalBoxLayout
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(stackedWidget);

    setLayout(layout);
}

/*!
 * \brief Widget::~Widget
 */
Widget::~Widget()
{
    delete ui;
    delete stackedWidget;
}

/*!
 * Permet de naviguer entre les GUIs
 * \brief Widget::navigate
 */
void Widget::navigate()
{
    // Si les pokemons ont été générés, on peut commencer la partie
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

