#include <bits/stdc++.h>
using namespace std;

void CountSort(vector<int> &nums, int n, int maxElem, int pos)
{

    vector<int> count(10, 0);
    vector<int> arr(n + 1);
    for (int i = 0; i < n; i++)
    {

        count[(nums[i] / pos) % 10]++;
    }

    for (int i = 1; i <= 9; i++)
    {
        count[i] = count[i] + count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {

        count[(nums[i] / pos) % 10]--;
        int temp = count[(nums[i] / pos) % 10];
        arr[temp] = nums[i];
    }

    for (int i = 0; i < n; i++)
    {
        nums[i] = arr[i];
    }
    for (auto i : nums)
    {
        cout << i << " ";
    }
    cout << endl;
}
void RadixSort(vector<int> &nums, int n, int maxELem)
{
    for (int pos = 1; (maxELem / pos) > 0; pos = pos * 10)
    {

        CountSort(nums, n, maxELem, pos);
    }
}

int main()
{
    vector<int> nums{432, 8, 530, 90, 88, 231, 011, 045, 677, 199};

    int n = nums.size();
    int maxElem = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxElem = max(maxElem, nums[i]);
    }

    RadixSort(nums, n, maxElem);
}
