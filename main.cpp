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
    cout<<endl;
    int counter=1;
    while(!cars.empty()){
        cout<<"Time: "<<counter;
        cout<<" Operation: ";
        if(randomprob()<=55){
            cout<<"Car paid: ";cars.front().print();
            cars.pop_front();
        }
        if(randomprob()<=45){
            Car temp;
            cars.push_back(temp);
        }
        cout<<endl;
        cout<<"Queue: "<<endl;
        for(auto& car: cars){
        car.print();
        }
        counter++;
        cout<<endl;
    }   
    cout<<"Empty"<<endl;
    return 0; 
}
int randomprob(){
        int rand1= rand() % 100 + 1;
        return rand1;
}