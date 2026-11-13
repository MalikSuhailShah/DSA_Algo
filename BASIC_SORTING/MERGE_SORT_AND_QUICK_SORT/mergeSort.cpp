#include <iostream>
#include <vector>
using namespace std;

void mergeTwo(vector<int> &a, vector<int> &b, vector<int> &res)
{
    int i = 0, j = 0, k = 0;

    while (i < a.size() && j < b.size())
    {
        if (a[i] <= b[i]) res[k++] = a[i++] ;
        else res[k++] = b[j++];
    }
    if(i==a.size()){
        while(j<b.size()) res[k++] = b[j++];
    }
    if(j==b.size()){
        while(i<a.size()) res[k++] = a[i++];
    }

    return;

}

void mergeSort(vector<int> & v){
    int n = v.size();

    if(n==1) return;

    int n1 = n/2, n2 = n-n1;

    vector<int> a(n1), b(n2);

    for(int i=0; i<n1;i++){
       a[i]= v[i];
    }

    for(int i=0;i<n2;i++){
        b[i] = v[i+n1];
    }

    mergeSort(a);
    mergeSort(b);

    mergeTwo(a,b,v);

    a.clear(), b.clear(); // clearing space to improve Space complexity

}

int main()
{
    // vector<int> a ={1,2,3,8};
    // vector<int> b ={4,5,6,7};
    // int n1= a.size();                               
    // int n2= b.size();         
    // vector<int>  res(n1+n2);
    // mergeTwo(a,b,res);

    vector<int> v = {5,1,8,2,3};

    mergeSort(v);

    for(int ele : v) cout<<ele<<" ";


}