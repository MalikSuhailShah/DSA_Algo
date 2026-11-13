#include <iostream>
#include <vector>
// #include <algorithm>
using namespace std;

void display(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return;
}

// Method 1-> In this method 1 is pushed towards right indices and zero is pushed towards left indices
void sort01M1(vector<int> &v)
{
    int n = v.size();
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        if (v[i] == 0)
            i++;
        if (v[j] == 1)
            j--;
        if (i > j) // without this condition code is not correct for input   array before swapping->1 1 0 1 0 1 1 0
                   //                                                        array after swapping ->0 0 1 0 1 1 1 1
            break;
        if (v[i] == 1 && v[j] == 0) // needs swapping
        {
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }
    return;
}

// Method 2
void sort01M2(vector<int> &v)
{
    int noz = 0; // noz=no.of zeros
    int noo = 0; // noo=no. of ones
    int n = v.size();
    // counting Zeros And Ones.
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
            noz++;
        else
            noo++;
    }
    // filling the elements
    for (int i = 0; i < n; i++)
    {
        if (i < noz)
            v[i] = 0;
        else
            v[i] = 1;
    }
}

//Bubble Sort
void sort01M3(vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[j] > v[j + 1])
            {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
    return;
}

// int main()
// {
//     vector<int> v;
//     int n;
//     cout << " enter the size of vector array:";
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         int x;
//         cin >> x;
//         v.push_back(x);
//     }
//     cout << "array before swapping->";
//     display(v);
//     sort01M1(v);
//     cout << "array after swapping ->";
//     display(v);
// }


