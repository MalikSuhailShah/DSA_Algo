#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
//  iterating over windows to select index best optimal window 
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

    int n = arr.size();
    int lo=0, hi= n-k;

    while(lo<hi){
        int mid = lo+(hi-lo)/2;
        if(x-arr[mid] > arr[mid+k]-x){ // right candidate is more closer
            lo = mid+1;
        }
        else hi = mid;   // because mid itself can be an answer
    }

    return vector<int>  (arr.begin()+lo, arr.begin()+lo+k);
    }
};

class solution {
public:

    

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();

        vector<int> v(k);

         if(x<=arr[0]){
                for(int i=0;i<k;i++){
                    v[i]=arr[i];
                }
                return v;
            }
            else if(x>arr[n-1]) {
                int i=k-1;
                int j=n-1;
                while(i>=0){
                    v[i]=arr[j];
                    i--;
                    j--;
                }
                return v;
            }



        bool flag=false;

        int lo=0,hi=n-1;
        int t=0;
        int mid=-1;
        while(lo<=hi){
             mid=lo+(hi-lo)/2;

            if(arr[mid]==x) {
                flag=true;
                v[t]=arr[mid];
                t++;
                break;
            }

            else if(arr[mid]>x) hi=mid-1;
            else lo=mid+1;

        }

        int ub=lo;
        int lb=hi;

        if(flag==true){
            ub=mid+1;
            lb=mid-1;
        }

        while(t<k && lb>=0 && ub<=n-1){
            int d1=abs(x-arr[lb]);
            int d2=abs(x-arr[ub]);

            if(d1<=d2) {
                v[t]=arr[lb];
                lb--;

            }

            else{
                v[t]=arr[ub];
                ub++;
            }

            t++;

        }

        if(lb<0){
            while(t<k){
                v[t]=arr[ub];
                ub++;
                t++;
            }
        }

        if(ub>n-1){
            while(t<k){
                v[t]=arr[lb];
                lb--;
                t++;

            }
        }

        sort(v.begin(),v.end());
        return v;
       
    }
};