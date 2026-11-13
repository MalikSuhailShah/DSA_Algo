#include <iostream>
using namespace std;

float power(int a, int b)
{
    if (a == 0 && b == 0)
    {
        cout << "0 raised to power 0 is not defined";
        return 0;
    }
    else if (b == 0)
        return 1;

    if (b < 0)
        b = -b;

    return a * power(a, b - 1);
}
int main()
{

    int a, b;
    cout << "Enter the base:" << endl;
    cin >> a;
    cout << "Enter the exponent:" << endl;
    cin >> b;

    float p = power(a, b);

    if (b < 0)
        p = 1 / p;

    cout << a << " raised to power " << b << " is " << p;
}