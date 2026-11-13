#include<iostream>
#include<stack>
#include<vector>

using namespace std;

vector<int> MaxSlidingWindow(vector<int> &v, int k){
    if(k==1) return v;
    int n=v.size();

    //creating next greater index array
    int ngi[n];
    stack<int> st;
    ngi[n-1]=n;
    st.push(n-1);
    for(int i=n-2;i>=0;i--){
        while(st.size() && v[st.top()]<v[i]) st.pop();

        if(st.size()==0) ngi[i]=n;
        else ngi[i]=st.top();

        st.push(i);
    }

    int j=0;
    vector<int> ans;
    for(int i=0;i<n-k+1;i++){
        int mx=v[j];
        if(j<i) j=i;
        while(j<i+k){
           mx=v[j];
           if(ngi[j]>i+k) break;
           j=ngi[j];
        }
        ans.push_back(mx);
    }

    return ans;
}

int main (){
    int k;
    cout<<"Enter the size of the window:"<<endl;
    cin>>k;

   vector<int> v;

    cout<<"Enter the elements of the array:"<<endl;
    for(int i=0;i<v.size();i++){
        int x;
        cin>>x;
        v.push_back(x);
    }

    
}

