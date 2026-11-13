#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
public:
    int tyreSize;
    int engineSize;
    int lights;
    string company;
    
    void showCompany(){
        cout<<company<<endl;
    }

    Vehicle()
    {
        cout << "Vehicle constructor call hua!!" << endl;
    }
};

class Bike : public Vehicle
{
public:
    int handleSize;

    Bike()
    {
        cout << "Bike Constructor call hua!!" << endl;
        this->handleSize = handleSize;
    }
};

int main()
{

    Bike splenderPlus;

    splenderPlus.tyreSize = 17;
    splenderPlus.engineSize = 100;
    splenderPlus.lights = 5;
    splenderPlus.company = "HONDA";
    splenderPlus.handleSize = 5;

    splenderPlus.showCompany();


    cout<<splenderPlus.company<<" "<<splenderPlus.engineSize<<" "<<splenderPlus.handleSize<<" "<<splenderPlus.lights<<" "<<splenderPlus.tyreSize<<endl;
}