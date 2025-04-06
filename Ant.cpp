#include "Ant.h"
#include <iostream>
#include <vector>
using namespace std;

Ant::Ant() : width(10), height(10) 
{
    grid.resize(height, vector<Color>(width, WHITE));
    X = width / 2;
    Y = height / 2;
    heading = UP;
}

void Ant::run(int steps) 
{
    for (int i = 0; i < steps; ++i)
    {
        if (grid[X][Y] == WHITE) 
        {
            turnRight();
        }
        else 
        {
            turnLeft();
        }
        flipColor();
        move();
    }
}

void Ant::printGrid() const 
{
    for (int i = 0; i < height; ++i) 
    {
        for (int j = 0; j < width; ++j) 
        {
            if (i == Y && j == X) 
            {  
                switch (heading) 
                {  
                case UP:
                    cout << "\033[30;31m^ ";
                    break;
                case RIGHT:
                    cout << "\033[30;31m> ";
                    break;
                case DOWN:
                    cout << "\033[30;31mv ";
                    break;
                case LEFT:
                    cout << "\033[30;31m< ";
                    break;
                }
            }
            else {  
                cout << (grid[i][j] == WHITE ? "\033[47;30m  " : "\033[40;30m  ");
            }
        }
        cout << endl;
    }
}

void Ant::move()
{
    switch (heading) 
    {
    case UP:
        --Y;
        break;
    case RIGHT:
        ++X;
        break;
    case DOWN:
        ++Y;
        break;
    case LEFT:
        --X;
        break;
    }
    X = (X + width) % width;
    Y = (Y + height) % height;
}

void Ant::turnLeft() 
{
    switch (heading)
    {
    case DOWN:
    {
        heading = RIGHT;
        break;
    }
    case LEFT:
    {
        heading = DOWN;
        break;
    }
    case UP:
    {
        heading = LEFT;
        break;
    }
    case RIGHT:
    {
        heading = UP;
    }
    }
}

void Ant::turnRight() 
{
    switch (heading)
    {
    case DOWN:
    {
        heading = LEFT;
        break;
    }
    case LEFT:
    {
        heading = UP;
        break;
    }
    case UP:
    {
        heading = RIGHT;
        break;
    }
    case RIGHT:
    {
        heading = DOWN;
    }
    }
}

void Ant::flipColor()
{
    grid[X][Y] = (grid[X][Y] == WHITE ? BLACK : WHITE);
}

void Ant::printFinalState() const 
{
    cout << "Final position: (" << X << ", " << Y << ")" << endl;
    cout << "Facing direction: ";
    switch (heading)
    {
    case UP:
        cout << "UP";
        break;
    case RIGHT:
        cout << "RIGHT";
        break;
    case DOWN:
        cout << "DOWN";
        break;
    case LEFT:
        cout << "LEFT";
        break;
    }
    cout << endl;
}