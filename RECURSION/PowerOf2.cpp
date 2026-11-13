#include <iostream>
using namespace std;

bool power2(int n)
{

    if (n == 1)
    {
        return true;
    }

    if (n % 2 == 0)
        return power2(n / 2);
    else
        return false;
}

bool power(int n, int product)
{

    if (product > n)
    {
        return false;
    }

    if (n == product)
        return true;

    return power(n, product * 2);
}
int main()
{
    int n;
    cout << "Enter the number:" << endl;
    cin >> n;
    int product = 1;
    int idx = 1;
    cout << power2(n);
}