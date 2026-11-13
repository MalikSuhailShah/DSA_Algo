#include<iostream>
using namespace std;

class Bike{
    public:
    int tyreSize;
    int engineSize;


    //Default Constructor
    // Bike (){

    // }

    //parametrised Constructor
    Bike (int tyreSize,int engineSize){

        this->tyreSize=tyreSize;
        this->engineSize=engineSize;
    }
    
};

int main (){

    Bike tvs(15,150);//object creation => default constructor is called by compilor

    cout<<tvs.engineSize;

}