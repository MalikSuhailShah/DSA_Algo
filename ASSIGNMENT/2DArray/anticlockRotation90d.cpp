#include<iostream>
using namespace std;
int main ()
{
    int m;
    cout<<"enter the number of rows of matrix:";
    cin>>m;
    int n;
    cout<<"enter the number of columns:";
    cin>>n;

    int arr[m][n];
    cout<<"enter the elements of array:";
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }


    //tranpose transformation

    for(int i=0;i<m;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        }
    }

    //column reversal

    for(int k=0;k<m;k++)
    {
        int i=0;
        int j=n-1;
        while(i<=j){
            int temp=arr[i][k];
            arr[i][k]=arr[j][k];
            arr[j][k]=temp;
            i++;
            j--;
        }
               
    }

    cout<<endl;

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
           cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    
    


}