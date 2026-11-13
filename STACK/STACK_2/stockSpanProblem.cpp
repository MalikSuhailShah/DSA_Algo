#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> Previous(int arr[],int n){

    stack<int> st;

    vector<int> ans(n);
    
    ans[0]=-1;

    st.push(0);

    for(int i=1;i<n;i++){
        while(st.size() && arr[st.top()]<=arr[i]){
            st.pop();
        
        }

        if(st.size()==0) ans[i]=-1;
        else ans[i]=st.top();

        st.push(i);
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

    vector<int> pgi=Previous(arr,n);


    vector<int> ans(n);
 
    for(int i=0;i<n;i++){
        ans[i]=i-pgi[i];
    }


    cout<<"The stock span is :"<<endl;
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }

    
}
