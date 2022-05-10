#include "finishwidget.h"
#include "game.h"
#include "ui_finishwidget.h"

/*!
 * \brief FinishWidget::FinishWidget
 * \param parent
 */
FinishWidget::FinishWidget(QWidget *parent, Game* game) :
    QWidget(parent),
    ui(new Ui::FinishWidget)
{
    itsGame = game;
    ui->setupUi(this);
}

/*!
 * \brief FinishWidget::~FinishWidget
 */
FinishWidget::~FinishWidget()
{
    delete ui;
}

/*!
 * Affiche qui est le gagnant
 * \brief FinishWidget::start
 */
void FinishWidget::start()
{
    ui->winner->setText(itsGame->getItsWinner());
}

/*!
 * Slot appelé lorsque l'utilisateur veut sauvegarder les dresseurs
 * \brief FinishWidget::on_save_clicked
 */
void FinishWidget::on_save_clicked()
{
    itsGame->getItsFirstTrainer()->save(itsGame);
    itsGame->getItsSecondTrainer()->save(itsGame);
}

