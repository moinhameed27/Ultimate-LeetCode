class Solution
{
public:
    int countPairs(vector<int> &nums, int target)
    {
        sort(begin(nums), end(nums));
        int count = 0, n = nums.size();
        int i = 0, j = n - 1;
        while (i < j)
        {
            // If nums[i] + nums[j] < target, then surely all values of nums[j] will be less than target
            // So we'll increment in the count and check for next left pointer values
            if (nums[i] + nums[j] < target)
            {
                count += j - i;
                i++;
            }
            else
                j--;
        }
        return count;
    }
};