#include <iostream>
#include <vector>
using namespace std;
void display(vector<int> &v)
{
    int n=v.size();
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void sort(vector<int> &v)
{
    int n = v.size();
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (v[i] > 0 && v[j] < 0)
        {
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            i++;
            j--;
        }
        if (v[i] < 0)
            i++;
        if (v[j] > 0)
            j--;
    }
}
int main()
{
    vector<int> v;
    int n;
    cout << "enter the size of vector array->";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    display(v);
    sort(v);
    display(v);
}