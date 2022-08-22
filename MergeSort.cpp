#include <bits/stdc++.h>
using namespace std;
void merge(int *arr, int start, int mide, int end)

{
    int mid = (start + end) / 2;
    int leftSize = mid - start + 1;

    int rightSize = end - mid;
    int leftArr[leftSize];
    int rightArr[rightSize];
    // vector<int> leftArr(leftSize);
    // vector<int> rightArr(rightSize);
    int mainArrayIndex = start;
    for (int i = 0; i < leftSize; i++)
    {
        leftArr[i] = arr[mainArrayIndex++];
    }
    mainArrayIndex = mid + 1;
    for (int i = 0; i < rightSize; i++)
    {
        rightArr[i] = arr[mainArrayIndex++];
    }

    int i = 0;
    int j = 0;
    mainArrayIndex = start;
    while (i < leftSize && j < rightSize)
    {
        if (leftArr[i] < rightArr[j])
        {
            arr[mainArrayIndex] = leftArr[i];
            i++;
            mainArrayIndex++;
        }
        else
        {
            arr[mainArrayIndex] = rightArr[j];
            j++;
            mainArrayIndex++;
        }
    }

    while (i < leftSize)
    {
        arr[mainArrayIndex] = leftArr[i];
        i++;
        mainArrayIndex++;
    }
    while (j < rightSize)
    {
        arr[mainArrayIndex] = rightArr[j];
        j++;
        mainArrayIndex++;
    }
    
    return;
}

void Solve(int *arr, int start, int end)

{

    if (start >= end)
    {
        return;
    }

    int mid = (start + end) / 2;
    Solve(arr, start, mid);
    Solve(arr, mid + 1, end);
   
    merge(arr, start, mid, end);
}

int main()
{
   int  arr[]={13, 12, 3, 43, 533};
    int n = 5;
   
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl<<"sorted array is "<<endl;
    Solve(arr, 0, n - 1);

    for (auto i : arr)
    {
        cout << i << " ";
    }

    return 0;
}