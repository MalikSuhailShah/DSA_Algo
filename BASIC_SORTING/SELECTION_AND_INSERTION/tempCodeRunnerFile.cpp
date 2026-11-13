oid f(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] < arr[i] && arr[j]>0)

                count++;
        }
        // cout << arr[i] << " " << count << endl;

        arr[i] = -count;
    }

    for(int i=0;i<n;i++) arr[i]*=-1;
}
