#include <iostream>
#include <QApplication>
#include <conio.h>
#include "snake.h"
#include "window.h"
//no graphics idk how work help
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    return app.exec();
}
