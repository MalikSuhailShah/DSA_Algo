#include<iostream>
using namespace std;

class A{
    public :
    int age;

    A(){
        cout<<"A ka constructor call hua!!"<<endl;
    }
};

class B{
    public:
    int address;

    B(){
        cout<<"B ka constructor call hua!!"<<endl;
    }
};

class C:public A,public B{
    public :
    int phoneNumber;

};

int main (){

    C a;
    a.address=150;
    a.age=19;
    a.phoneNumber=99099;

}