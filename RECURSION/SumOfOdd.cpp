#include <iostream>
using namespace std;

int sumOdd(int curr, int lastNumber)
{
    if (curr > lastNumber)
        return 0;

    if (curr % 2 != 0)
        return curr + sumOdd(curr + 2, lastNumber);

    else {
        return sumOdd(curr+1,lastNumber);
    }
}
int main()
{
    int a;
    cout << "Enter the first number :" << endl;
    cin >> a;

    int b;
    cout << "Enter the second number:" << endl;
    cin >> b;

    cout << sumOdd(a, b);
}