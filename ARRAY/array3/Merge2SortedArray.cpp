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
    int i = 0; // for v1 array
    int j = 0; // for v2 array
    int k = 0; // for resultant array
    vector<int> res(n + m);
    while (i < n && j < m)
    {
        if (v1[i] < v2[j])
        {
            res[k] = v1[i];
            i++;
        }
        else
        {
            res[k] = v2[j];
            j++;
        }
        k++;
    }

    if (i == n) // when all the elements of array v1 is taken
    {
        while (j < m)
        {
            res[k] = v2[j];
            j++;
            k++;
        }
    }

    if (j == m) // when all the elements of array v2 is taken
    {

        while (i < n)
        {
            res[k] = v1[i];
            i++;
            k++;
        }
    }

    return res;
}

int main()
{
    vector<int> v1;
    int n;
    cout << "enter the size of vector v1->";
    cin >> n;
    cout << "enter the sorted vector v1->";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v1.push_back(x);
    }
   


    vector<int> v2;
    
    int m;
    cout << "enter the size of vector v2->";
    cin >> m;
    cout << "enter the sorted vector v2->";
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        v2.push_back(x);
    }

    vector<int> res = merge(v1, v2);
    display(res);

    return 0;
}
