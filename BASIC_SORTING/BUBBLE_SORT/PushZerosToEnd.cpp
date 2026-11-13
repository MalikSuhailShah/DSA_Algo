#include <iostream>
using namespace std;
int main()
{
    int arr[] = {5,0,1,2,0,0,4,0,3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "The elements of the array are:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    for(int i=0;i<n-1;i++){

        bool flag=true;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]==0 && arr[j+1]!=0){
                swap(arr[j],arr[j+1]);
                flag=false;
            }
        }
        if(flag) break;
    }

    cout<<endl<<"The array after sorting is:"<<endl;

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}