#include "snake.h"

SnakeGame::SnakeGame()
    : width(20), height(20), imageName("snake.bmp")
{
    // initialize game settings
    dir = STOP;
    x = width / 2;
    y = height / 2;
    catX = rand() % width;
    catY = rand() % height;
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
    // Code for displaying image using Windows GDI functions
    // You can replace this with your preferred method of image display
    // ...
}

void SnakeGame::Setup()
{
    srand(time(NULL));
}