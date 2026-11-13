#include<iostream>
using namespace std;


class Vehicle{
    public:
    int tyreSize;
    int engineSize;
    int lights;
};

class Bike:public Vehicle{
    public:
    int handleSize;
};

class Car:public Vehicle{
    public:
    int stearingSize;
};

int main (){

    Car BMW;

    BMW.engineSize=1500;
    BMW.lights=8;
    BMW.stearingSize=30;
    BMW.tyreSize=30;

     Bike royalEnfield;;

    royalEnfield.engineSize=350;
    royalEnfield.lights=4;
    royalEnfield.handleSize=10;
    royalEnfield.tyreSize=15;

}