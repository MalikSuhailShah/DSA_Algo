#include <iostream>
#include <vector>
using namespace std;
int main()
{

    int n, m;
    cout << "Enter the number of rows and columns of the vector array:";
    cin >> n >> m;

    cout<<"Enter the elements of the vector array:"<<endl;
    vector<vector<int>> a(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    // SPIRAL PRINTING

    int minr = 0, minc = 0;

    int maxr = n - 1, maxc = m - 1;

    int tne = n * m, count = 0;

    while (tne > count)
    {

        // left to right

        for (int i = minc; i <= maxc && count < tne; i++)
        {
            cout << a[minr][i] << " ";
            count++;
        }

        minr++;

        // top to bottom

        for (int i = minr; i <= maxr && count < tne; i++)
        {
            cout << a[i][maxc] << " ";
            count++;
        }

        maxc--;

        // right to left

        for (int i = maxc; i >= minc && count < tne; i++)
        {
            cout << a[maxr][i] << " ";
            count++;
        }

        maxr--;

        // bottom to top

        for (int i = maxr; i >= minr && count < tne; i++)
        {
            cout << a[i][minc] << " ";
            count++;
        }

        minc++;
    }
}