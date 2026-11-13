#include <iostream>
using namespace std;
int main()
{

    int m;
    cout << "Enter the size of the array:" << endl;
    cin >> m;

    int arr[m];

    cout << "Enter the elements of the array:" << endl;

    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }

    // BUBBLE SORT OPTIMISED

   
    for (int i = 0; i < m - 1; i++)
    {
         
         bool flag = true;
       
            for (int j = 0; j < m - 1 - i; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                    flag=false;
                }
            }

            if(flag) break;
    }

    cout << "The elements of the array are:" << endl;

    for (int i = 0; i < m; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
