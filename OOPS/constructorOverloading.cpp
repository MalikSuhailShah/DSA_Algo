#include<iostream>
using namespace std;

class bike{
    public:
    int tyreSize;
    int EngineSize;


    bike(int ts, int es): tyreSize(ts), EngineSize(es){};
    bike(int ts): tyreSize(ts), EngineSize(100){};
    bike(): tyreSize(50), EngineSize(100){};

    //depending upon how many parameter is passed different constructor is called automatically
};

int main (){

}