#include <iostream>
#include <vector>
using namespace std;

void matrixrow(vector<vector<int>> &v, int r)
{
    int rows = v.size();
    int cols = v[0].size();

    for (int i = 0; i < cols; i++)
    {
        v[r][i] = -1;
    }
    return;
}

void matrixcolumn(vector<vector<int>> &v, int c)
{
    int rows=v.size();

    for(int i=0;i<rows;i++)
    {
        v[i][c]=-1;
    }
    return;
}

int main()
{
    int n, m;
    cout << "Enter the number of rows and columns of the vector matrix:" << endl;
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(m));

    cout << "Enter the elements of the matrix" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    //  1st METHOD
   
//    for(int i=0;i<n;i++)
//    {
//     for(int j=0;j<m;j++)
//    {
//         if(v[i][j]==0)
//         {
//             matrixrow(v,i);
//             matrixcolumn(v,j);
//         }
//    }

//    }
   

//    for(int i=0;i<n;i++)
//    {
//     for(int j=0;j<m;j++)
//     {
//         if(v[i][j]==0) continue;
//         else if(v[i][j]==-1) v[i][j]=0;
//     }
//    }

//2nd METHOD

vector<int> rows(n,0);
vector<int> cols(m,0);

for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        if(v[i][j]==0){
            rows[i]=1;
            cols[j]=1;

        }
    }
}

for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)
    {
        if(rows[i]==1 || cols[j]==1){
            v[i][j]=0;
        }
    }
}

//3rd METHOD

 bool firstRowZero = false, firstColumnZero = false;
    

    //checking for the first row and the first column

    for(int i=0;i<m;i++)
    {
        if(v[0][i]==0) firstRowZero=true;
    }

    for(int i=0;i<n;i++)
    {
        if(v[i][0]==0) firstColumnZero=true;
    }




    for (int i = 1; i < n; i++)
    {

        for (int j = 1; j < m; j++)
        {

            if (v[i][j] == 0)
            {
                v[0][j] = 0;
                v[i][0] = 0;
            }
        }
    }

    for (int i = n - 1; i > 0; i--)
    {
        for (int j = m - 1; j > 0; j--)
        {
            if (v[0][j] == 0 || v[i][0] == 0)
            {

                v[i][j] = 0;
            }
        }
    }

    if(firstRowZero) 
    {
        for(int i=0;i<m;i++)
        {
            v[0][i]=0;

        }
    }

    if(firstColumnZero){
        for(int i=0;i<n;i++)
        {
            v[i][0]=0;
        }
    }




    

    cout << "\n The final matrix is:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}