#include<iostream>
#include<vector>

using namespace std;

int inversion(vector<int> & a , vector<int> & b){
    int i=0, j=0;
    int count =0;
    while(i<a.size() && j<b.size()){
        if(a[i]>b[j])
        { // all the elements next to a[i] in vector a, will always be greater the b[j] and they will always form count inversion pair with b[j]

            count += (a.size()-i);
            j++;
        }
        else i++;

        
    }
    return count;

}

void mergeTwo(vector<int> &a, vector<int> &b, vector<int> &res)
{
    int i = 0, j = 0, k = 0;

    while (i < a.size() && j < b.size())
    {
        if (a[i] <= b[j]) res[k++] = a[i++] ;
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

int mergeSort(vector<int> & v){
    int n = v.size();
    int count =0;

    if(n<=1) return 0;

    int n1 = n/2, n2 = n-n1;

    vector<int> a(n1), b(n2);

    for(int i=0; i<n1;i++){ // all elements in a , will always have lower index than all elements of b in original vector
       a[i]= v[i];
    }

    for(int i=0;i<n2;i++){
        b[i] = v[i+n1];
    }

    count += mergeSort(a);
    count += mergeSort(b);
    count += inversion(a,b);
    mergeTwo(a,b,v);

    a.clear(), b.clear(); // clearing space to improve Space complexity

    return count;

}

int  main (){

    vector<int> v = {5,1,8,2,3};

    cout<<mergeSort(v);
    cout<<endl;
    for(int ele : v) cout<<ele<<" ";

}