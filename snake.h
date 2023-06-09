#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include <string>
using namespace std;

class SnakeGame
{
public:
    SnakeGame();
    //~SnakeGame();
    void Run();

private:
    // game settings
    const int width;
    const int height;
    int x, y, catX, catY, score;
    int tailX[100], tailY[100];
    int nTail;
    enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
    eDirection dir;

    // image display variables
    const string imageName;
    HANDLE hImage;
    int imageWidth, imageHeight;

    // function prototypes
    void Draw();
    void Setup();
    void Input();
    void Logic();
    void ShowImage();
};

#endif

