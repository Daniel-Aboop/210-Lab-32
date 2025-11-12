#include <iostream>
#include <deque>
#include "Car.h"
using namespace std;

const int startingsize=2;

int main() {
 deque<Car> cars;
 Car startingcar1;
 Car startingcar2;
cars.push_back(startingcar1);
cars.push_back(startingcar2);

    return 0; 
}