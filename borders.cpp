#include "window.h"
#include <QPainter>
#include <QKeyEvent>

MainWindow::MainWindow() : sq(0, 0, 10, 10), dir(10, 0)
{
    setFixedSize(480, 320);
    connect(&ticker, &QTimer::timeout, this, &MainWindow::onTick);
    ticker.start(500);
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.setBrush(Qt::black);
    p.drawRect(sq);
    
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
