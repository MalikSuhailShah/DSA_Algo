#include <iostream>
#include <vector>
#include<stack>
using namespace std;

vector<int>  nextGreater(int arr[],int n)
{

    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        ans[i] = -1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                ans[i] = arr[j];
                break;
            }
        }
    }


    return ans;

}

vector<int> nextGreaterTwo(int arr[],int n){
    
    stack<int> st;

    vector<int> ans(n);
    ans[n-1]=-1;
    
    st.push(arr[n-1]);


    for(int i=n-2;i>=0;i--){
        while(st.size() && st.top()<=arr[i]){
            st.pop();

        }

        if(st.size()==0) ans[i]=-1;
        else ans[i]=st.top();

        st.push(arr[i]);
    }


    return ans;

}

int main()
{
    int n;
    cout << "Enter the size of the array:" << endl;
    cin >> n;

    int arr[n];

    cout << "Enter the elements of the array:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    vector<int> ans=nextGreater(arr,n);

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}