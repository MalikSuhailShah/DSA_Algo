#include<iostream>
#include<vector>

using namespace std;

void cycleSort(vector<int> &arr){
    int i=0, n = arr.size();

    while(i<n){
        if(arr[i]!=(i+1)){
            int correctIdx = arr[i]-1;

            swap(arr[i], arr[correctIdx]);
        }

        else i++;
    }
}


int main (){
    vector<int> v ={4,5,6,1,2,3};

    cycleSort(v);
    for(int ele : v) cout<<ele<<" ";
}