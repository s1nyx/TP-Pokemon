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
Widget::Widget(QWidget *parent, Game* game)
    : QWidget(parent)
    , ui(new Ui::Widget), itsCurrentWidget(HOME)
{
    ui->setupUi(this);

    itsGame = game;

    // désactive le resize
    setWindowFlags(Qt::Widget | Qt::MSWindowsFixedSizeDialogHint);

    // initialisation du système de navigation
    AttackWidget* attackWidget = new AttackWidget(nullptr, game);
    HomeWidget* homeWidget = new HomeWidget(nullptr, game);
    FinishWidget* finishWidget = new FinishWidget(nullptr, game);

    // ajout au widget widget principal
    itsStackedWidget = new QStackedWidget();
    itsStackedWidget->addWidget(homeWidget);
    itsStackedWidget->addWidget(attackWidget);
    itsStackedWidget->addWidget(finishWidget);

    // connecter les menus entre eux
    connect(homeWidget->getUi()->startGame, SIGNAL(clicked()), this, SLOT(navigate()));
    connect(homeWidget->getUi()->startGame, SIGNAL(clicked()), attackWidget, SLOT(start()));
    connect(attackWidget, SIGNAL(gameFinished()), this, SLOT(navigate()));
    connect(attackWidget, SIGNAL(gameFinished()), finishWidget, SLOT(start()));

    // affiché le QStackedWidget grâce à un VerticalBoxLayout
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(itsStackedWidget);

    setLayout(layout);
}

/*!
 * \brief Widget::~Widget
 */
Widget::~Widget()
{
    delete ui;
    delete itsStackedWidget;
}

/*!
 * Permet de naviguer entre les GUIs
 * \brief Widget::navigate
 */
void Widget::navigate()
{
    // Si les pokemons ont été générés, on peut commencer la partie
    if (itsGame->canStart())
    {
        if (itsCurrentWidget == HOME)
        {
             itsCurrentWidget = ATTACK;
        }
        else if (itsCurrentWidget == ATTACK)
        {
            itsCurrentWidget = FINISHED;
        }

        itsStackedWidget->setCurrentIndex(itsCurrentWidget);
    }
}

