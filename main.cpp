#include <iostream>
#include <deque>
#include <ctime>
#include <iomanip>
#include <random>
#include <array>
#include "Car.h"
using namespace std;

const int lanesize=2;
const int LEAVE=46;
const int JOIN=39;
const int SHIFT=15;
int randomprob();

int main() {
    deque<Car> cars[4];
    srand(time(0));
    Car startingcar1;
    Car startingcar2;
    for(int i=0;i<4;i++){
        Car temp;
        Car temp2;
        cars[i].push_back(temp);
        cars[i].push_back(temp2);
    }
    cout<<"Initial queue: "<<endl;
    for(int i=0;i<4;i++){
        cout<<"Lane "<<i+1<<endl;
        for(auto& car:cars[i]){
              cout<<"    ";car.print();
        }
    }
    for(int i=1;i<=20;i++){
        int ranNum=randomprob();
        cout<<"Time: "<<i<<endl;
        for(int y=0;y<4;y++){
            cout<<"Lane: "<<y+1;
            //this is to check if its empty for the 50/50 chance to add a car
            if(cars[y].empty()){
                if(randomprob()<=50){
                    Car temp;
                    cars[y].push_back(temp);
                    cout<<" Joined Lane: ";temp.print();
                }
            }
            // if its not empty it goes here
            else{
                //46% probability that the car at the head of the queue pays its toll and leaves the queue
                if(ranNum<=LEAVE){  
                    cout<<" Paid: ";cars[y].front().print();
                    cars[y].pop_front();
                }
                //39% probability that another car joins the queue
                else if(ranNum<=LEAVE+JOIN){
                    Car temp;
                    cars[y].push_back(temp);
                    cout<<" Joined: ";temp.print();
                }
                //15% probability that the rear car will shift lanes
                else{
                  
                }
            }
            cout<<endl;
        }
        cout<<endl;
        for(int i=0;i<4;i++){
            cout<<"Lane "<<i+1<<" Queue:"<<endl;
        if(!cars[i].empty()){
      
        for(auto& car:cars[i]){
              cout<<"    ";car.print();
        }
        }
        else{
            cout<<"Empty"<<endl;;
        }
        }
    }
   /*
    cout<<endl;
    cout<<"Inital queue: "<<endl;
    for(auto& car: cars){
        car.print();
    }
    cout<<endl;
    int counter=1;
    while(!cars.empty()){
        cout<<"Time: "<<counter<<endl;
        cout<<"Operation: ";
        int randomholder=randomprob();
        if(randomprob()<=55){
            cout<<"Car paid: ";cars.front().print();
            cars.pop_front();
        }
        if(randomprob()<=45){
            Car temp;
            cars.push_back(temp);
            cout<<"Joined Lane";temp.print();
        }
        cout<<"Queue: "<<endl;
        if(!cars.empty()){
            for(auto& car: cars){
                cout<<"    ";car.print();
            }
        }
       else{
            cout<<"    Empty";
        }
        counter++;
    }   
        */
    return 0; 
}
int randomprob(){
        int rand1= rand() % 100 + 1;
        return rand1;
}