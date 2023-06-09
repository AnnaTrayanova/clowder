#include "borders.h"
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>
#include <QLabel>
#include <QImage>

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
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.setBrush(Qt::black);
    p.drawRect(sq);
    
}

private:
    QLabel* images;
    QImage babaFront1;//da iztria li tova????
    QImage babaFront2;//v smsl
    QImage babaFront3;//tezi trite?
    bool isRotationStarted;
    int rotationCounter;

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

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_S:
        dir.setX(0);
        dir.setY(10);
        break;
    case Qt::Key_W:
        dir.setX(0);
        dir.setY(-10);
        break;
    case Qt::Key_D:
        dir.setX(-10);
        dir.setY(0);
        break;
    case Qt::Key_A:
        dir.setX(10);
        dir.setY(0);
        break;

    default:
        break;
    }
}

void MainWindow::onTick()
{
    sq.translate(dir);
    update();
}
