#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
using namespace std;

class SnakeGame
{
public:
    SnakeGame();
    ~SnakeGame();
    void Run();
private:
    // game settings
    const int width;
    const int height;
    int x, y, fruitX, fruitY, score;
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
 
// snake.cpp


#include "snake.h"

SnakeGame::SnakeGame()
    : width(20), height(20), imageName("snake.bmp")
{
    // initialize game settings
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
    nTail = 0;

    // initialize image display variables
    hImage = LoadImage(NULL, imageName.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
    if (hImage == NULL)
    {
        cerr << "Error loading image file." << endl;
        exit(1);
    }
    BITMAP bmp;
    GetObject(hImage, sizeof(bmp), &bmp);
    imageWidth = bmp.bmWidth;
    imageHeight = bmp.bmHeight;
}

SnakeGame::~SnakeGame()
{
    // release image resources
    DeleteObject(hImage);
}

void SnakeGame::Run()
{
    // game loop
    while (true)
    {
        // draw game board and image
        Draw();
        ShowImage();

        // handle player input
        Input();

        // update game state
        Logic();

        // wait before updating game state again
        Sleep(50);
    }
}

void SnakeGame::Draw()
{
    system("cls");
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "#";
            if (i == y && j == x)
                cout << "O";
            else if (i == fruitY && j == fruitX)
                cout << "F";
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                 void SnakeGame::Setup()
{
    srand(time(NULL));
}

void SnakeGame::Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            exit(0);
        }
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

    // update head position
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    } 

