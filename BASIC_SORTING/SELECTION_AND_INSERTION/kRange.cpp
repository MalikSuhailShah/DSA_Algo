#include <iostream>
#include <climits>

using namespace std;

float max(float a, float b)
{
    if (a >= b)
        return a;
    else
        return b;
}

float min(float a, float b)
{
    if (a < b)
        return a;
    else
        return b;
}
int main()
{

    int arr[] = {5, 3, 6};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Elements of the array are:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    float kmax = (float)INT_MAX;
    float kmin = (float)INT_MIN;

    bool flag = true;

    for (int i = 0; i < n - 1; i++)
    {

        if (arr[i] >= arr[i + 1]) // case  of the minimum value of the k
        {

            kmin = max(kmin, (arr[i] + arr[i + 1]) / 2.0);
        }
        else // case of the maximum value of the k
        {

            kmax = min(kmax, (arr[i] + arr[i + 1]) / 2.0);
        }

        if (kmin > kmax)
        {
            flag = false;
            break;
        }
    }

    if (!flag)
        cout << -1;
    else if ((int)kmax == kmin)
    {
        if (kmin - (int)kmin == 0) // kmin and kmax are both integers
            cout << "There is only one value of k :" << kmin;
        else
            cout << -1;
    }
    else
    {
        if (kmin - (int)kmin > 0)
        {
            kmin = (int)kmin + 1;
        }
        cout << "The range of k is :" << "[" << kmin << "," << (int)kmax << "]";
    }
}