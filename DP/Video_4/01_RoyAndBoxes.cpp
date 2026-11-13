// dp use din precomputation 
#include <iostream>
#include <vector>
using namespace std;
int main()
{

    int n; // n= number of boxes
    cin >> n;
    int m; // m = no. of ranges of boxer i.e number of L and R values
    cin >> m;

    vector<int> f(n + 1, 0); // f[i]== no. of time ith boxes is present in given ranges
    vector<int> l(n + 1, 0); // values of L
    vector<int> r(n + 1, 0); // values of R
    vector<int> c(n + 1, 0); // c[i]==no. of boxes containing exactly i coins

    for (int i = 0; i < m; i++)
    {
        int L, R;
        cin >> L >> R;
        l[L]++, r[R]++;
    }

    int q; // number of queries
    cin >> q;
    
    f[1] = l[1];
    for (int i = 2; i <= n; i++)
    {
        f[i] = l[i] - r[i - 1] + f[i - 1];
    }

    for (int i = 1; i <= m; i++)
    {
        c[f[i]]++;
    }

    // suffix sum
    for (int i = c.size() - 2; i >= 0; i--)
    {
        c[i] = c[i] + c[i + 1];
    }

    
    while (q--)
    {
        int num; // query
        cin >> num;
      cout<<c[num]<<endl;
    }
    
    /*second approach
    
    
    int n; // number  of boxes
    cin >> n;
    int m;
    cin >> m;

    vector<int> f(n + 1, 0);
    vector<int> c(n + 1, 0);

    for (int i = 1; i <= m; i++)
    {
        int L, R;
        cin >> L >> R;
        f[L]++;
        f[R + 1]--;
    }

    for (int i = 2; i <= n; i++)
    {
        f[i] += f[i - 1];
    }

    for (int i = 1; i <= n; i++)
    {
        c[f[i]]++;
    }

    // suffix sum
    for (int i = c.size() - 2; i >= 0; i--)
    {
        c[i] = c[i] + c[i + 1];
    }

    int q;
    cin >> q;
    while (q--)
    {
        int num;
        cin >> num;
        cout << c[num];
    }

    */

}