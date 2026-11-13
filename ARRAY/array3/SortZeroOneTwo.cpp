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
void sort012M1(vector<int> &v)
{
    int n = v.size();
    int noz = 0;  // intitial number of zeros
    int noO = 0;  // initial number of ones
    int notw = 0; // initial number of 2's
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
            noz++;
        else if (v[i] == 1)
            noO++;
        else
            notw++;
    }
    for (int i = 0; i < n; i++)
    {
        if (i < noz)
            v[i] = 0;
        else if (i < noz + noO)
            v[i] = 1;
        else
            v[i] = 2;
    }
}

// DUTCH FLAG ALGORITHM (three pointer algorithm)
void sort012M2(vector<int> &v)
{
    int n = v.size();
    int low = 0, mid = 0, hi = n - 1;
    while (mid < hi)
    {
        if (v[mid] == 2)
        {
            int temp = v[mid];
            v[mid] = v[hi];
            v[hi] = temp;
            hi--;
        }
        else if (v[mid] == 0)
        {
            int temp = v[mid];
            v[mid] = v[low];
            v[low] = temp;
            mid++;
            low++;
        }
        else
            mid++; // i.e when v[mid]==1;
    }
}



int main()
{
    vector<int> v;
    int n;
    cout << "enter the size of array vector->";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    display(v);
    sort012M2(v);
    display(v);
}