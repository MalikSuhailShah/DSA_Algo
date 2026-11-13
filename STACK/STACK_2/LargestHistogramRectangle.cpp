#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int maxArea(int arr[], int n)
{

    vector<int> psi(n);
    stack<int> st;
    psi[0] = -1;
    st.push(0);

    for (int i = 1; i < n; i++)
    {

        while (st.size() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }

        if (st.size() == 0)
            psi[i] = -1;
        else
            psi[i] = st.top();

        st.push(i);
    }

    vector<int> nsi(n);
    stack<int> gt;
    nsi[n - 1] = n;
    gt.push(n - 1);

    for (int i = n - 2; i >= 0; i--)
    {
        while (gt.size() && arr[gt.top()] >= arr[i])
        {
            gt.pop();
        }

        if (gt.size() == 0)
            nsi[i] = n;
        else
            nsi[i] = gt.top();

        gt.push(i);
    }

    int maxArea = 0;

    for (int i = 0; i < n; i++)
    {
        int breadth = nsi[i] - psi[i] - 1;
        int height = arr[i];

        int Area = breadth * height;

        maxArea = max(maxArea, Area);
    }
    return maxArea;
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

    int maxiArea=maxArea(arr,n);

    cout<<"Maximum Area of the rectangle posiible is:"<<endl;
    cout<<maxiArea<<endl;
}