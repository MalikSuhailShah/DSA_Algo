#include <iostream>
using namespace std;

class Vehicle
{ // Purely Abstract Class

public:
    virtual void calculateMilage() = 0; // pure virtual function
    virtual void refuel() = 0;          // pure virtual function
};

int main()
{
}