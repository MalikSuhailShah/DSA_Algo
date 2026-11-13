#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, m;
    cout << "Enter the number of rows and columns of the vector matrix:" << endl;
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(m));

    cout << "Enter the elements of the binary vector matrix:" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (v[i][0] == 0)
        {
            for (int j = 0; j < m; j++)
            {
                if (v[i][j] == 0)
                    v[i][j] = 1;
                else
                    v[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        int noO = 0, noZ = 0;
        for (int j = 0; j < n; j++)
        {

            if (v[j][i] == 0)
                noZ++;
            else
                noO++;
        }

        if (noO < noZ)
        {
            for (int j = 0; j < n; j++)
            {
                if (v[j][i] == 0)
                    v[j][i] = 1;
                else
                    v[j][i] = 0;
            }
        }
     }

     cout<<"Flipped Matrix:"<<endl;

     for(int i=0;i<n;i++)
     {
        for(int j=0;j<m;j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
     }


     int sum = 0;

        
        for (int i = 0; i < n; i++)
        {
            int f = 1;
            for (int j = m-1; j >= 0; j--)
            {
                sum += f * v[i][j];
                f *= 2;
            }
        }

        cout << "The score of the matrix is " << sum;
}