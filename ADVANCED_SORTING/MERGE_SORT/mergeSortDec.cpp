#include <iostream>
#include <vector>
using namespace std;
void mergeTwo(vector<int> & a,vector<int> & b,vector<int> & ans){
    int i=0,j=0,k=0;

    while(i<a.size() && j<b.size()){
        if(a[i]>=b[j]) ans[k++] =a[i++];
        else ans[k++]=b[j++];

    }

    if(i==a.size()){
        while(j<b.size()){
             ans[k++]=b[j++];
        }
    }

    if(j==b.size()){
        while(i<a.size())  ans[k++]=a[i++];
    }

    return;
}

void mergeSort(vector<int> &ans)
{
    int n = ans.size();

    if (n == 1)
        return;

    int n1 = n / 2;
    int n2 = n - n / 2;

    vector<int> a(n1), b(n2);

    for (int i = 0; i < n1; i++)
        a[i] = ans[i];

    for (int i = 0; i < n2; i++)
        b[i] = ans[i + n1];

    mergeSort(a);

    mergeSort(b);

    mergeTwo(a, b, ans);

    a.clear();
    b.clear();
}
int main()
{
    int arr[] = {6, 8, 7, 5, 2, 3, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> v(arr, arr + n);

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }

    mergeSort(v);

    cout<<endl;

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
}