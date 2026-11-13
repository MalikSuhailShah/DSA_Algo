#include <iostream>
#include<vector>
using namespace std;
void arrayTraversing(int arr[],int n){
   
   if(n<=0) return;
    arrayTraversing(arr,n-1);
    cout<<arr[n-1]<<" ";
}

void vectorTraversing(vector<int>& v,int idx){
    if(idx==v.size()) return;

    cout<<v[idx]<<" ";

    vectorTraversing(v,idx+=1);
}
int main()
{
    int n;
    cout << "Enter the number of elements of the array:" << endl;
    cin >> n;

    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];

    }

  //  arrayTraversing(arr,n);

    vector<int> v(n);
    for(int i=0;i<n;i++){
        v[i]=arr[i];
    }

    vectorTraversing(v,0);

}