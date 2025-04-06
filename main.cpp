#include <iostream>
#include "Ant.h"
using namespace std;

int main() {
    int width, height, steps;
    cout << "Enter number of steps: ";
    cin >> steps;
    Ant ant;
    ant.run(steps);
    ant.printGrid();
    ant.printFinalState();
    return 0;
}
