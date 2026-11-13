#include <iostream>
using namespace std;

int partition(int arr[], int si, int ei)
{

    int pivotElement = arr[(si + ei) / 2];

    int count = 0;

    for (int i = si; i <= ei; i++)
    {
        if (i == (si + ei) / 2)
            continue;
        if (arr[i] <= pivotElement)
            count++;
    }

    int pivotIdx = si + count;

    swap(arr[(si + ei) / 2], arr[pivotIdx]);

    int i = si, j = ei;

    while (i < pivotIdx && j > pivotIdx)
    {
        if (arr[i] <= pivotElement)
            i++;
        if (arr[j] > pivotElement)
            j--;
        else if (arr[i] > pivotElement && arr[j] < pivotElement)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return pivotIdx;
}

int kthSmallest(int arr[],int si,int ei,int k){

    

    int pivotIdx=partition(arr,si,ei);

    if(pivotIdx==k-1) return arr[pivotIdx];
    else if(pivotIdx+1<k) kthSmallest(arr,pivotIdx+1,ei,k); 
    else kthSmallest(arr,si,pivotIdx-1,k);

}
int main()
{
    
    int arr[] = {5, 4,3,2,1,7,8,9,54,12};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    
    int k;
    cout<<"Enter the value of the k:"<<endl;
    cin>>k;

    
   cout<< kthSmallest(arr, 0, n - 1,k);
}