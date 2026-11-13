#include<iostream>
using namespace std;

class complexNumber
{
    private:
    int prev=10;

public:
    int real;
    int imaginary;

    friend complexNumber operator + (complexNumber & c1,complexNumber & c2);

    friend class prime;


    
};

complexNumber operator+(complexNumber &c1,complexNumber & c2)
    {

        complexNumber c3;

        c3.imaginary = c1.imaginary + c2.imaginary;
        c3.real=c1.real+ c2.real;

        return c3;
    }

class prime {
    public:
    void show(complexNumber &c){
        cout<<c.prev<<endl;
    }
};




int main (){

    
    complexNumber c1;
    
    c1.imaginary =150;
    c1.real=100;

    complexNumber c2;

    c2.imaginary=290;
    c2.real=190;

    complexNumber c3=c2+c1;

    //cout<<c3.imaginary<<" "<<c3.real<<endl;

    prime p;
    p.show(c3);

}