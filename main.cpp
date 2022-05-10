#include "game.h"
#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    Game* game = new Game();
    qDebug() << "Database connected: " << game->getItsDatabaseManager()->connect();
    game->getItsDatabaseManager()->startQueries();

    QApplication a(argc, argv);
    Widget w(nullptr, game);

    w.show();

    return a.exec();
}
