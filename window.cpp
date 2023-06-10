#include <QPainter>
#include <QKeyEvent>
#include "window.h"


MainWindow::MainWindow() : sq(0, 0, 10, 10), dir(10, 0)
{
    setFixedSize(480, 320);
    connect(&ticker, &QTimer::timeout, this, &MainWindow::onTick);
    ticker.start(500);

babaFront1.load("babaFront1.png");
babaFront2.load("babaFront2.png");
babaFront3.load("babaFront3.png");

    imageLabel = new QLabel(this);
    imageLabel->setGeometry(0, 0, 480, 320);

    isRotationStarted = false;
    rotationCounter = 0;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter p(this);

     // Calculate the current frame based on the elapsed time
    int frame = (QDateTime::currentMSecsSinceEpoch() / 250) % 3;

    // show the current frame image
    switch (frame)
    {
        case 0:
            p.drawImage(sq, babaFront1);
            break;
        case 1:
            p.drawImage(sq, babaFront2);
            break;
        case 2:
            p.drawImage(sq, babaFront3);
            break;
    }
}

void MainWindow::onTick()
{
    sq.translate(dir);
    isRotationStarted = true;
    update();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Down:
        dir.setX(0);
        dir.setY(10);
        break;
    case Qt::Key_Up:
        dir.setX(0);
        dir.setY(-10);
        break;
    case Qt::Key_Left:
        dir.setX(-10);
        dir.setY(0);
        break;
    case Qt::Key_Right:
        dir.setX(10);
        dir.setY(0);
        break;

    default:
        break;
    }
}