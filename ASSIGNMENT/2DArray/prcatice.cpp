#include <iostream>
using namespace std;

int main()
{
    int p;
    cout << "Enter the side of the square matrix: ";
    cin >> p;
    
    int arr[p][p];  // Declare the 2D array for the matrix
    
    int minr = 0; // Starting row
    int maxr = p - 1; // Ending row
    int minc = 0; // Starting column
    int maxc = p - 1; // Ending column
    
    int n = 1; // Start with 1
    int count = 0; // To track the number of elements placed
    int tne = p * p; // Total number of elements in the matrix
    
    while (count < tne)
    {
        // Rightward filling
        for (int i = minc; i <= maxc; i++)
        {
            arr[minr][i] = n;
            count++;
            n++;
        }
        minr++; // Move the top boundary downwards
        
        if (count >= tne) break;
        
        // Downward filling
        for (int i = minr; i <= maxr; i++)
        {
            arr[i][maxc] = n;
            count++;
            n++;
        }
        maxc--; // Move the right boundary left
        
        if (count >= tne) break;
        
        // Leftward filling
        for (int i = maxc; i >= minc; i--)
        {
            arr[maxr][i] = n;
            count++;
            n++;
        }
        maxr--; // Move the bottom boundary upwards
        
        if (count >= tne) break;
        
        // Upward filling
        for (int i = maxr; i >= minr; i--)
        {
            arr[i][minc] = n;
            count++;
            n++;
        }
        minc++; // Move the left boundary right
    }
    
    // Print the matrix
    for (int i = 0; i < p; i++) // Use 'p' to print the matrix correctly
    {
        for (int j = 0; j < p; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
