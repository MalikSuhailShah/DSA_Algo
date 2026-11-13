#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> VisiblePerson( int v[],int n){
    

    vector<int> ans(n);

    stack<int> st;

    ans[n-1]=0;

    st.push(v[n-1]);

    for(int i=n-2;i>=0;i--){

        int count=0;
        while(st.size()>0 && v[i]>st.top()){
            st.pop();
            count++;

        }

        if(st.size()!=0) count++;
        ans[i]=count;
        st.push(v[i]);
    }

    return ans;

}

int main (){

    int n;
    cout<<"Enter the size of the array:"<<endl;
    cin>>n;

    int arr[n];

    cout<<"Enter the elements of the array:"<<endl;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<int> ans=VisiblePerson(arr,n);


    cout<<"Number of the visible persons are:"<<endl;
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    
}