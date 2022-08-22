#include <bits/stdc++.h>
using namespace std;
void ShellSort(vector<int> &nums, int n)
{
    for (int gap = n / 2; gap > 0; gap = gap / 2)
    {
        for (int j = gap; j < n; j++)
        {
            for (int i = j - gap; i >= 0; i = i - gap)
            {
                if (nums[i] > nums[i + gap])
                {
                    swap(nums[i], nums[i + gap]);
                }
                else
                {
                    break;
                }
            }
        }
    }
}
int main()
{
    vector<int> nums{52,23, 29, 15, 19, 31, 7, 9, 52,52};
    int n = nums.size();
    ShellSort(nums, n);
    for(auto num:nums)
    {
        cout << num<< "  ";
    }
    return 0;
}