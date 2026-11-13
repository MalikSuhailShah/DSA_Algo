#include <iostream>
using namespace std;

class vehicle
{
public:
    virtual void showType()
    {
        cout << "i am vehicle!!" << endl;
    }
};

class Bike : public vehicle
{
    public:
      void showType()
    {
        cout << "i am bike!!" << endl;
    }
};

int main()
{

    Bike b;
    // b.showType();
    vehicle* p ;
    p=&b;
    p->showType();
}