#ifndef ANT_H
#define ANT_H

#include <iostream>
#include <vector>
using namespace std;

class Ant 
{
public:
    Ant();
    void run(int steps);
    void printGrid() const;
    void printFinalState() const;
private:
    enum Color { WHITE, BLACK };
    enum Heading { UP, RIGHT, DOWN, LEFT };

    vector<vector<Color>> grid;
    int X, Y;
    Heading heading;
    int width, height;

    void move();
    void turnLeft();
    void turnRight();
    void flipColor();
};
#endif 