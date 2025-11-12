#include <iostream>
#include <deque>
#include <ctime>
#include <iomanip>
#include <random>
#include "Car.h"
using namespace std;

const int startingsize=2;
int randomprob();

int main() {
    deque<Car> cars;
    srand(time(0));
    Car startingcar1;
    Car startingcar2;
    cars.push_back(startingcar1);
    cars.push_back(startingcar2);
    cout<<endl;
    cout<<"Inital queue: "<<endl;
    for(auto& car: cars){
        car.print();
    }
    while(!cars.empty()){
        if(randomprob()<=55){
            
        }
        if(randomprob()<=45){
            Car temp;
            cars.push_back(temp);
        }

    }

    return 0; 
}
int randomprob(){
        int rand1= rand() % 100 + 1;
        return rand1;
}