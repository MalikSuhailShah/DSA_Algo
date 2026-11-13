#include<iostream>
using namespace std;

class vehicle{
    public:

    virtual void CalculateMilage()=0;

    virtual void refuel()=0;
};

class bike{

    public:

     void  CalculateMilage(){
        cout<<"Milage is excellent"<<endl;
     }

     void refuel(){
        cout<<"Takes less time"<<endl;
     }

    };

int main (){


    bike splender;

    splender.CalculateMilage();

    splender.refuel();

}