#include <iostream>
using namespace std;

class complexNumber
{

public:
    int real;
    int imaginary;

    complexNumber operator+(complexNumber &c1)
    {

        complexNumber c3;

        c3.imaginary = c1.imaginary + this->imaginary;
        c3.real = c1.real + this->real;

        return c3;
    }

    complexNumber operator-(complexNumber &c2)
    {
        complexNumber c3;
        c3.real = this->real - c2.real; // this refer to the object left side to the operator
        c3.imaginary = this->imaginary - c2.imaginary;

        return c3;
    }
};

int main()
{

    complexNumber c1;

    c1.imaginary = 150;
    c1.real = 100;

    complexNumber c2;

    c2.imaginary = 290;
    c2.real = 190;

    complexNumber c3 = c2 + c1;
    complexNumber c4 = c3 - c2;

    cout << c3.imaginary << " " << c3.real << endl;
    cout << c4.imaginary << " " << c4.real << endl;
}