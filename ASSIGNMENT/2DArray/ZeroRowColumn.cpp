#include<iostream>
using namespace std;
int main ()
{
    int n;
    cout<<"enter the rows of array->";
    cin>>n;
    int m;
    cout<<"enter the column ofarray->";
    cin>>m;

    int arr[n][m];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
        
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]==0)
            {
                for(int k=0;k<n;k++)
                {
                    arr[k][j]=0;
                    
                }

                for(int k=0;k<n;k++)
                {
                    
                    arr[i][k]=0;
                }

                break;
            
               
            }
            ;
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<arr[i][j];
        }
        cout<<endl;
        
    }

}