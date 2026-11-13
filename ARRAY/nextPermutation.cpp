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

void reversepart(vector<int> &v, int a, int b)
{
    int n = v.size();
    for (int i = a, j = b; i < j; i++, j--)
    {
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }
    return;
}

void nextpermutation(vector<int> &v)
{
    int n = v.size();
    int idx = -1;
    for (int i = n - 2; i >= 0; i--) // because second last element is compared with last element
    {
        if (v[i + 1] > v[i])
        {
            idx = i;
            break;
        }
    }
     if (idx == -1)// if array is already greatest
    {
        reversepart(v, 0, n - 1);
        return;
    }

    // sorting/reverse after pivot index
    reversepart(v, idx + 1, n - 1);


    // finding just greater number than v[idx]
    int j=-1;
    for(int i=idx+1;i<n;i++)
    {
        if(v[i]>v[idx])
        {
            j=i;
            break;
        }
    }
                                                                                                                                                            
    // swapping idx and idx+1
    int temp = v[idx];
    v[idx] = v[j];
    v[j] = temp;

   

    return;
}

int main()
{
    int n;
    cout << "enter the size of vector array->";
    cin >> n;
    vector<int> v;
    cout<<"Enter the elements of the array:";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    display(v);
    nextpermutation(v);
    display(v);
}
