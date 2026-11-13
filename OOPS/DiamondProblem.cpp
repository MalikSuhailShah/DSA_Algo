#include <iostream>
using namespace std;

class Vehicle {
public:
    Vehicle() {
        cout << "Vehicle constructor called" << endl;
    }
    void showType() {
        cout << "I am a Vehicle" << endl;
    }
};

class Bike : virtual public Vehicle {
};

class Car : virtual public Vehicle {
};

class SportsVehicle : public Bike, public Car {
};

int main() {
    SportsVehicle obj;
    // obj.showType();  
}
