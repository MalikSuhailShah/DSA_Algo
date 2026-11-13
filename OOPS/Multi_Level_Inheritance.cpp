#include<iostream>
using namespace std;

class vehicle{
    public:
    int tyreSize;
    int engineSize;
    int lights;
};

class Bike:public vehicle{
    public:
    int handleSize;
};

class ElectricBike:public Bike{
    public:
    int batteryCapacity;
};


int main (){

}