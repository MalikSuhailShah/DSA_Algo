#include <iostream>
using namespace std;

class A
{
private: // neither be accessed nor be inherited
    int a_ka_Private;

protected: // can not be accessed but can be inherited
    int a_ka_protected = 10;

public: // can be accessed as well as inherited
    int a_ka_public;
};

class B : protected A
{

private:
    int b_ka_private;

protected:
    int b_ka_protected;

public:
    int b_ka_public;

    void show()
    {
        cout << a_ka_protected << endl;
    }
};

int main()
{
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
    B b;
    b.b_ka_public=10;

    b.show();


}