/*
Approach:
Given moves are 3, so we can go with 4 combinationsa after sorting to check. Using moves on
1. First 3 numbers
2. Last 3 numbers
3. First One and Last Two Numbers
4. First Two and Last One Numbers
*/

// Way - I
class Solution
{
public:
    int minDifference(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 4)
            return 0;
        sort(nums.begin(), nums.end());
        int minValue = INT_MAX;

        minValue = min(minValue, nums[n - 4] - nums[0]);
        minValue = min(minValue, nums[n - 3] - nums[1]);
        minValue = min(minValue, nums[n - 2] - nums[2]);
        minValue = min(minValue, nums[n - 1] - nums[3]);
        return minValue;
    }
};

// Way - II
class Solution
{
public:
    int minDifference(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 4)
            return 0;
        sort(nums.begin(), nums.end());
        int minValue = INT_MAX;

        for (int i = 0; i <= 3; i++)
            minValue = min(minValue, nums[n - 1 - (3 - i)] - nums[i]);
        return minValue;
    }
};