#include "game.h"
#include "widget.h"
// #include "tests.cpp"

#include <QApplication>

int main(int argc, char *argv[])
{  
    /*
    test_waterpokemon();
    test_plantpokemon();
    test_firepokemon();
    test_electrikpokemon();
    test_game();
    test_trainer();
    */

    // Définition du SEED
    srand(time(0));

    Game* game = new Game();

    // Connexion à la BDD & récupération en mémoire des pokemons
    qDebug() << "Database connected: " << game->getItsDatabaseManager()->connect();
    game->getItsDatabaseManager()->startQueries();

    QApplication a(argc, argv);
    Widget w(nullptr, game);

    w.show();

    return a.exec();
}
