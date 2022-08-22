#include <bits/stdc++.h>
using namespace std;
// modifes count sort for negative elem also
vector<int> CountSort(vector<int> &nums, int n, int k, int minElem)
{
    vector<int> count(k + 1, 0);
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        int temp = nums[i] - minElem;
        count[temp]++;
    }
    for (int i = 1; i <= k; i++)
    {
        count[i] = count[i] + count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int elem = nums[i];
        int idx = elem - minElem;
        count[idx]--;
        int temp = count[idx];

        arr[temp] = elem;
    }

    return arr;
}

int main()
{
    vector<int> nums{2, 1, 1, 0, 2, 5, 4, 0, 2, 8, 7, 7, 9, 2, 0, 1, -3};
    int n = nums.size();
    int maxElem = INT_MIN;
    int minElem = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        maxElem = max(maxElem, nums[i]);
        minElem = min(minElem, nums[i]);
    }
    int k = maxElem - minElem;
    vector<int> arr = CountSort(nums, n, k, minElem);
    for (auto k : arr)
    {
        cout << k << "  ";
    }
    return 0;
}