#include<iostream>
using namespace std;
int main ()
{
   int s;
   cout<<"enter the rows of matrix->";
   cin>>s;
   int r;
   cout<<"enter the columns of matrix->";
   cin>>r;
   int arr[s][r];

   int minr=0;//denoting minimum row
   int maxr=s-1;//denoting maximum row
   int minc =0;//denoting minimum column
   int maxc=s-1;//denoting maximum column

   int n=1;

   int count =0;
   int t=s*s;//total number of elements of array

   while(t>=count){
    
    for(int i=minc;i<=maxc;i++)
    {
        arr[minr][i]=n;
        count++;
        n++;

    }
    minc++;

    if(count>=t) break;

    for(int i=minr;i<=maxr;i++)
    {
        arr[i][maxc]=n;
        count++;
        n++;

    }
    maxc--;

    if(count>=t) break;


    for(int i=maxc;i>=minc;i--)
    {
  
        arr[maxr][i]=n;
        count++;
        n++;
    }
    maxr--;

    if(count>=t) break;

    for(int i=maxr;i>=minr;i--)
    {
        arr[i][minc]=n;
        count++;
        n++;

    }
    minc++;
   }


   for(int i=0;i<s;i++)
   {
    for(int j=0;j<s;j++)
    {
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;

   }



}