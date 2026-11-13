#include<iostream>
using namespace std;

//Deep Copy
class Player{
    public:
    int score; // normal variable
};

class Bike{
    public:
    int* EngineCapacity; // raw pointer

      // Normal/parameterized constructor
    Bike(int value){
        EngineCapacity = new int(value); // => shallow copy
    }

    // custom copy constructor 
    Bike(const Bike& other) {
    EngineCapacity = new int(*other.EngineCapacity); // => this will create a deep copy
}
};

int main (){

    Player A;
    A.score=100;
    Player B(A);// => Deep Copy

    cout<<B.score<<" "<<A.score<<endl;

    B.score=190;
    cout<<B.score<<" "<<A.score<<endl;


}