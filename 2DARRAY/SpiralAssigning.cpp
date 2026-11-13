#include<iostream>
#include<vector>
using namespace std;
int main (){
    int n;
    cout<<"Enter the side of the  square matrix:"<<endl;
    cin>>n;
   int a[n][n];

   
    int tne=n*n,count=0;

    int r=1;

    int minr=0,minc =0;
    int maxc=n-1,maxr=n-1;

    while(count<tne)
    {
        for(int i=minc;i<=maxc && count<tne;i++)
        {
            a[minr][i]=r++;
            count++;
        }

        minr++;


        for(int i=minr;i<=maxr && count<tne;i++)
        {
            a[i][maxc]=r++;
            count++;
        }

        maxc--;

        for(int i=maxc;i>=minc && count<tne;i--){
            a[maxr][i]=r++;
            count++;
        }

        maxr--;

        for(int i=maxr;i>=minr && count<tne;i--)
        {
            a[i][minc]=r++;
            count++;
        }
        minc++;
    }


    cout<<"\n spiral order\n";

    for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        cout<<a[i][j]<<" ";
    }
    cout<<endl;
}

}