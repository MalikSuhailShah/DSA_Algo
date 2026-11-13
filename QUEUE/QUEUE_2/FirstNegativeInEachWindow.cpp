#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> FirstNegative(vector<int> &v, int k)
{
    int n = v.size();

    queue<int> q;

    for (int i = 0; i < n; i++)
    {
        if (v[i] < 0)
        {
            q.push(i);
        }
    }

    vector<int> ans;

    for (int i = 0; i < n - k + 1; i++)
    {
        while (q.size() > 0 && q.front() < i)
            q.pop();
        if (q.size() == 0 || q.front() > i + k)
            ans.push_back(0);
        else
            ans.push_back(v[q.front()]);
    }
    return ans;
}

int main()
{
    vector<int> v = {-1, -2, 3, 4, -5, -6, 4, 7, -9};
    int k;
    cout << "Enter the size of the window:" << endl;
    cin >> k;

    vector<int> ans = FirstNegative(v, k);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}