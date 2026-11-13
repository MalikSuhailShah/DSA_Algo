#include<iostream>
using namespace std;

class calculator{

    private:
    int a;
    int b;

    public:

    //setter
     
    void setA(int c){
        cout<<"The value of a is modifiedDyna"<<endl;
        a=c;
    }

    void setB(int x){
        cout<<"The value of b is modified"<<endl;
        b=x;
    }

    void add(){
        cout<<a+b<<endl;
    }
    
    void substract(){
        cout<<a-b<<endl;
    }
};

int main (){

    calculator calci;

    calci.setA(70);
    calci.setB(20);

    calci.add();
    calci.substract();

}