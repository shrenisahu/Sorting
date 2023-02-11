#include<iostream>
#include<vector>

using namespace std;

// how to build  a max heap from a n array :use heapify method TC:O(log N)
void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;

    int lc = (2 * i )+1;
    int rc = (2 * i) + 2;
    if (lc < n && arr[lc] > arr[largest])
        largest = lc;
    if (rc < n && arr[rc] > arr[largest])
        largest = rc;

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
void buildHeap(vector<int> &arr, int n)
{

    for (int i = (n / 2)-1; i >= 0; i--) // build a max heap TC=O(N)
    {
        heapify(arr, n, i);
    }
}
void heapSort(vector<int> &arr, int n)
{
    buildHeap(arr, n);

    int t = n-1;
    while (t > 0)
    {
        swap(arr[0], arr[t]);
        heapify(arr, t, 0);
        t--;
    }
}

int main()
{



vector<int> arr{3,4,5,6,7,1,2};

int n = arr.size();

heapSort(arr, n);
// cout << "sorting " << endl;
for (auto i : arr)
        cout << i << "  ";
    return 0;
}
