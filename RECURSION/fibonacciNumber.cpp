#include <iostream>
using namespace std;
int fibo(int n)
{
    if (n == 1 || n == 2)
        return 1;

    int rightAns = fibo(n - 2);
    int leftAns = fibo(n - 1);
    return rightAns + leftAns;
}
int main()
{
    int n;
    cout << "Enter the number :" << endl;
    cin >> n;

    cout << fibo(n) << endl;
}
