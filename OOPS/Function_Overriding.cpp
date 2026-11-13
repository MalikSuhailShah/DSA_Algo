#include<iostream>
using namespace std;

class vehicle{

    public:
    int engineSize;
    int tyreSize;

    void ShowType(){
        cout<<"I am a vehicle!!"<<endl;
    }

};

class bike:public vehicle{

    public:

    void ShowType()
      {
          cout<<"I am a bike!!"<<endl;
      }

};


int main (){

    bike bmw;

    //bmw.ShowType();

    bmw.ShowType();
  

}