#include<iostream>
using namespace std;

class bike{;

    public:
    int engineSize;
    int tyreSize;


    bike (int engineSize,int tyreSize){
        this->engineSize=engineSize;
        this->tyreSize=tyreSize;

    }

    bike (bike & b){

        cout<<"Copy constructor is called!!"<<endl;

        this->engineSize=b.engineSize;
        this->tyreSize=b.tyreSize;
        
        
    }
};



int main (){

    bike royalEnfield(350,20);

    bike royalEnfield2=royalEnfield;



     cout<<royalEnfield2.engineSize<<" "<<royalEnfield2.tyreSize<<endl;
     cout<<royalEnfield.engineSize<<" "<<royalEnfield.tyreSize<<endl;


     cout<<"Modifiaction of original object occurs!!"<<endl;

    royalEnfield.engineSize=300;

    
     cout<<royalEnfield2.engineSize<<" "<<royalEnfield2.tyreSize<<endl; 
     cout<<royalEnfield.engineSize<<" "<<royalEnfield.tyreSize<<endl;
}