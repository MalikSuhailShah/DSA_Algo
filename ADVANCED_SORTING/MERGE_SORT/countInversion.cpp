#include <iostream>
#include <vector>
using namespace std;

int inversion(vector<int> &a, vector<int> &b)
{
    int i = 0, j = 0;
    int count = 0;

    while (i < a.size() && j < b.size())
    {
        if (a[i] > b[j])
        {
            count += (a.size() - i);
            j++;
        }
        else
            i++;
    }

    return count;
}

void mergeTwo(vector<int> &a, vector<int> &b, vector<int>& ans)
{

    int i = 0, j = 0, k = 0;

    while (i < a.size() && j < b.size())
    {
        if (a[i] <= b[j])
            ans[k++] = a[i++];
        else
            ans[k++] = b[j++];
    }

    if (i == a.size())
        while (j < b.size())
            ans[k++] = b[j++];
    if (j == b.size())
        while (i < a.size())
            ans[k++] = a[i++];

    return;
}
int mergeSort(vector<int> &ans)
{
    int count = 0;

    
    int n = ans.size();
    if (n == 1)
        return 0;

    int n1 = n / 2, n2 = n - n / 2;

    vector<int> a(n1), b(n2);

    for (int i = 0; i < n1; i++)
        a[i] = ans[i];
    for (int i = 0; i < n2; i++)
        b[i] = ans[i + n1];

    count += mergeSort(a);
    count += mergeSort(b);

    count += inversion(a, b);

    mergeTwo(a, b, ans);
    a.clear();
    b.clear();

    return count;
}

int main()
{
  int arr[]={5,1,8,2,3};
  int n=sizeof(arr)/sizeof(arr[0]);

  vector<int> v(arr,arr+n);

  for(int i=0;i<n;i++){
    cout<<v[i]<<" ";
  }


//   //BRUTE FORCE APPROACH
//   int count=0;

//   for(int i=0;i<n-1;i++){
//     for(int j=i+1;j<n;j++){
//         if(v[i]>v[j]) count++;
        
//     }
//   }




  cout<<endl;

  cout<<mergeSort(v);
}
