#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        bool flag = true;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] < a[i + 1])
            {

                continue;
                ;
            }
            else
            {
                a[i] = b[0] - a[i];
            }
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                flag = false;
                break;
            }
        }
        if (flag == true)
            cout << "YES";
        else
            cout << "NO";
    }
}
