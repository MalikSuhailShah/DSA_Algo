#include<iostream>
#include<vector>
using namespace std;

int occurence(vector<int> &v,int x){

    int lo=0;
    int hi=v.size()-1;
    bool flag=false;

    while(lo<=hi){
        int mid=lo+(hi-lo)/2;

        if(x==v[mid]){
            if(v[mid-1]==x) hi=mid-1;
            else{

                flag=true;
                return mid;
            }
        }
        else if(x>v[mid]) lo=mid+1;
        else hi=mid-1;
    }

    if(!flag) return -1;

}
int main (){
    vector<int> v={1,2,2,2,3,3,3,3,4,5,8,9,9};

    cout<<occurence(v,6);


}