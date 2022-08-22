#include <bits/stdc++.h>
using namespace std;
void merge(int *arr, int start, int mide, int end)

{
    int B[end];
    int mid = (start + end) / 2;

    int mainArrayIndex = start;

    int i = start;
    int j = mid + 1;
    mainArrayIndex = start;
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            B[mainArrayIndex] = arr[i];
            i++;
            mainArrayIndex++;
        }
        else
        {
            B[mainArrayIndex] = arr[j];
            j++;
            mainArrayIndex++;
        }
    }

    while (i <= mid)
    {
        B[mainArrayIndex] = arr[i];
        i++;
        mainArrayIndex++;
    }
    while (j <= end)
    {
        B[mainArrayIndex] = arr[j];
        j++;
        mainArrayIndex++;
    }
    for (int i = start; i <= end; i++)
    {
        arr[i] = B[i];
    }
    return;
}

void Solve(int *arr, int start, int end)

{

    if (start < end)
    {
        int mid = (start + end) / 2;

        Solve(arr, start, mid);
        Solve(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int main()
{
    int arr[5] = {13, 12, 3, 43, 533};

    int n = 5;
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl
         << "sorted array is " << endl;
    Solve(arr, 0, n - 1);

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}