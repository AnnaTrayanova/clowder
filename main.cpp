#include <iostream>
#include <QApplication>
#include <conio.h>
#include "snake.h"
#include "window.h"
/* I don't know what else to do, I tried so many things
Theres something wrong with the Qt, not al the code is
finished because I wanted to fix the errors first but I
couldn't. There's even some things that repeat*/
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    return app.exec();
}
