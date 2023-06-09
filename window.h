//#pragma once
#ifndef WINDOW_H
#define WINDOW_H
#include <QImage>
#include <QLabel>
#include <QKeyEvent>
#include <QWidget>
#include <QTimer>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow();
protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void onTick();

private:
    QTimer ticker;
    QRect sq;
    QPoint dir;
    QLabel *imagesLabel;
    QImage babaFront1;
    QImage babaFront2;
    QImage babaFront3;
    // bool isRotationStarted;
    // int rotationCounter;

};
#endif