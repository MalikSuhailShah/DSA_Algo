#include <iostream>
using namespace std;

void Zigzag(int n)
{
    if(n==0) return ;

    cout << n<<" ";
    Zigzag(n - 1);
    cout << n<<" ";
    Zigzag(n - 1);
    cout << n<<" ";
}
int main()
{
    int n;
    cout << "Enter the number:" << endl;
    cin >> n;
    Zigzag(n);
}