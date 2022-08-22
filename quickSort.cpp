#include <bits/stdc++.h>
using namespace std;

int Partition(vector<int> &arr, int start, int end)
{

    int pivot = arr[start];
    int count = 0;
    for (int i = start+1; i <= end; i++)
    {
        if (arr[i] <= pivot)
            count++;
    }
    int pivotPos = start + count;
    swap(arr[pivotPos], arr[start]);

    int i = start;
    int j = end;

    while (i < pivotPos && j > pivotPos)
    {
        while (arr[i] <= pivot)
            i++;

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < pivotPos && j > pivotPos)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return pivotPos;
}

void QuickSort(vector<int> &arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int pivotLoc = Partition(arr, start, end);
    QuickSort(arr, start, pivotLoc - 1);
    QuickSort(arr, pivotLoc + 1, end);
}

int main()
{
    vector<int> arr{4, 5, 6, 1, 2, 3};
    int n = arr.size();
    cout << "here";
    QuickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }

    return 0;
}