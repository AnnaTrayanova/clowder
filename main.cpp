#include <iostream>
#include <windows.h>
#include <QApplication>
#include <conio.h>
#include "snake.h"
#include "borders.h"


int main(/* int argc, char *argv[] */)
{
    // QApplication app(argc, argv);
    // MainWindow window;
    // window.show();
    // return app.exec();
    SnakeGame game;
    game.Run();

    return 0;
}
