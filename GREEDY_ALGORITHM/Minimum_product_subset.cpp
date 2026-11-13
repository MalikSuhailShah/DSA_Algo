#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

long long min_Product(vector<int> & arr){
    long long cn=0, cz=0, cp=0;

    long long prod_Pos=1;
    long long prod_neg=1;
    long long MaxNegative=INT_MIN;

    for(int i=0;i<arr.size();i++){
            if(arr[i]<0){
                cn++;
                prod_neg*=arr[i];
                MaxNegative=max(MaxNegative,(long long)arr[i]);
            }

            else if(arr[i]==0) cz++;
            else {
                cp++;
                prod_Pos*=arr[i];
            }
    }

    if(cn==0){// no negative elements are there
        if(cz>0) return 0;
        else {
            auto it=min_element(arr.begin(), arr.end());// stl to calculate minimum element in the array
            return *it;
        }
    }
    else{//negative elements are there
            if(cn%2!=0){ // odd no. og negative elements are there
                return prod_neg*prod_Pos;
            }
            else{// even no. pg negative elements are there

                return (prod_neg/MaxNegative)*prod_Pos;

            }
    }
}

int main (){
    vector<int> v={-2,-4,-5,0,4,5,6,7};
    cout<<min_Product(v)<<endl;

}