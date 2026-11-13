#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> PreviousGreater(int arr[],int n){

    stack<int> st;

    vector<int> ans(n);
    
    ans[0]=-1;

    st.push(arr[0]);

    for(int i=1;i<n;i++){
        while(st.size() && st.top()<=arr[i]){
            st.pop();
        
        }

        if(st.size()==0) ans[i]=-1;
        else ans[i]=st.top();

        st.push(arr[i]);
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


    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;

    vector<int> ans=PreviousGreater(arr,n);

    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

}

