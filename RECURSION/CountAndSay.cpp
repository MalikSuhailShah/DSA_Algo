#include <iostream>
#include <string>
using namespace std;

string countAndsay(int n)
{
    if (n == 1)
    {
        return "1";
    }
    string say = countAndsay(n - 1); // basically gives the previous string of upper block

    // processing

    string ans = "";

    for (int i = 0; i < say.length(); i++)
    {
        char ch = say[i];

        int count = 1;
        while (i < say.length() - 1 && say[i] == say[i + 1]) // this loop will run only on case in previous string adjacent character are same
        {
            count++;
            i++;
        }

        ans += to_string(count) + string(1, ch);
    }
    return ans;
}
int main()
{

    int n;
    cout << "Enter the number of terms of the sequence:" << endl;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cout << countAndsay(i)<<endl;
    }
}