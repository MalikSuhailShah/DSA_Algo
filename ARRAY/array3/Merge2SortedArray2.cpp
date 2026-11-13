#include <iostream>
#include <vector>
using namespace std;
void display(vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

vector<int> merge(vector<int> &v1, vector<int> &v2)
{
    int n = v1.size();
    int m = v2.size();
    int i = n - m - 1;
    int j = m - 1;
    int k = n - 1;
    while (i >= 0 && j >= 0)
    {
        if (v1[i] > v2[j])
        {
            v1[k] = v1[i];
            i--;
            k--;
        }
        else
        {
            v1[k] = v2[j];
            j--;
            k--;
        }
    }
    if (i < 0)
    {
        while(j>=0)
        {
            v1[k]=v2[j];
            j--;
            k--;
        }
    }

    if(j < 0)
    {
        while(i>0)
        {
            v1[k]=v1[i];
            k--;
            i--;

        }
    }
    return v1;
}

int main()
{
    int n;
    cout << "enter the 1st vector size-> ";
    cin >> n;
    int m;
    cout << "enter the 2nd vector size-> ";
    cin >> m;
    vector<int> v1(n + m);
    cout << "enter the elements of 1st vector->";
    for (int i = 0; i < n; i++)
    {
        cin >> v1[i];
    }

    vector<int> v2(m);
    cout << "enter the elements of 2nd vector->";
    for (int i = 0; i < m; i++)
    {
        cin >> v2[i];
    }

    display(v1);
    display(v2);
    v1 = merge(v1, v2);
    display(v1);
}