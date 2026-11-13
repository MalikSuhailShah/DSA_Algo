#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, m;
    cout << "Enter the number of rows and columns of the vector matrix:";
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(m));

    cout << "Enter the elements of the vector array:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    int target;
    cout << "Enter the targetted element:" << endl;
    cin >> target;

    int i = 0;
    int j = m - 1;

    bool flag = false;

    int a, b;

    while (i < n && j >= 0)
    {
        if (target == v[i][j])
        {
            flag = true;
            cout << "The element is present at (" << i << "," << j<<")";
            break;
            
        }
        else if (target > v[i][j])
        {

            i++;
        }
        else
            j--;
    }

    if (!flag)
        cout << "Element not present";
}