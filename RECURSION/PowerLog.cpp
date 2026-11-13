#include <iostream>
using namespace std;

float power(int a, int b)
{
    if (b == 0)
        return 1;

    float ans = power(a, b / 2);

    if (b % 2 == 0)
        return ans * ans ;
    else
        return ans * ans*a;
}
int main()
{
    int a;
    cout << "Enter the base:" << endl;
    cin >> a;
    int b;
    cout << "Enter the exponent:" << endl;
    cin >> b;

  

    if(b < 0) cout << (1.0 / power(a, -b));
    else   cout << power(a, b);
}