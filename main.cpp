#include <iostream>
#include "snake.h"
#include <QApplication> 
#include "borders.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    return app.exec();

    // testing some stuff
}
