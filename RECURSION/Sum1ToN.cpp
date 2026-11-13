#include <iostream>
using namespace std;

// PARAMETRISED(Extra Parameter)

void sumPara(int sum, int n)
{
    if (n == 0)
    {
        cout << sum;
        return;
    }

    sumPara(n + sum, n - 1);
}

// WITHOUT EXTRA PARAMETER (RETURN TYPE)

int Sum(int n)
{
    if (n == 1)
        return 1;

    return n + Sum(n - 1);
}

int main()
{
    int n;
    cout << "Enter the number:" << endl;
    cin >> n;

    int sum = 0;
    
   sumPara(sum, n);
    
    
}