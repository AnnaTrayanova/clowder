#include "snake.h"

SnakeGame::SnakeGame()
    : width(20), height(20), imageName("snake.bmp")
{
    // game settings
    dir = STOP;
    x = width / 2;
    y = height / 2;
    catX = rand() % width;
    catY = rand() % height;
    score = 0;
    nTail = 0;
}

void SnakeGame::Run()
{
    // game goooo
    while (true)
    {
        // do it draw the game board
        Draw();

        // player input 
        Input();

        // update it dumb code
        Logic();

        // wait 
        Sleep(50);
    }
}

void SnakeGame::Logic()
{
    // update tail positions
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
}
    void SnakeGame::ShowImage()
{
    // display image with google

    // ...
}

void SnakeGame::Setup()
{
    srand(time(NULL));
}
