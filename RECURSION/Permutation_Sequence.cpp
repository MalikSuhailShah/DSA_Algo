#include<bits/stdc++.h>
using namespace std;

string KthPermutation(string str, int k, string ans)
{
    int n = str.length();

    if (n == 1)
    {
        ans += str;
        return ans;
    }

    int fact = 1;
    for (int i = 2; i < n; i++)
        fact *= i; // calculating the (n-1)! to find number of  permutation starting from diff character

    int idx = k / fact;

    if (k % fact == 0)
        idx--; // this means the last permutation for any particular first character

    char ch = str[idx]; // first char of the required permutation

    int q;
    if (k % fact == 0)
        q = fact;
    else
        q = k % fact;

    string left = str.substr(0, idx), right = str.substr(idx + 1);
     return KthPermutation(left + right, q, ans + ch);
}

int main (){
    string str ="1234";
    int k =16;
    string ans = KthPermutation(str,16,"");

    cout<<ans<<" ";

}