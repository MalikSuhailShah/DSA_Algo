#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string decimal_To_Binary(int nums)
{

    if (nums == 0)
        return "0";
    string ans = "";
    while (nums > 0)
    {
        if (nums % 2 == 0)
            ans += '0';
        else
            ans += '1';

        nums = (nums >> 1);
    }
    reverse(ans.begin(), ans.end());

    return ans;
}

int flip_Bits(int nums)
{

    int p=nums;
    int x;

    while (nums > 0)
    {
        x = nums;
        nums = (nums & (nums - 1));
    }

    x <<= 1;
    x -= 1;

    return p ^ x;
}

int main()
{

    int x;
    cout << "Enter the number :" << endl;
    cin >> x;

    int p = flip_Bits(x);

    cout << p << endl;

    cout << decimal_To_Binary(p) << endl;
}