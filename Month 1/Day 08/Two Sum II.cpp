// Two Sum II - Input Array is Sorted
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans;
        int start = 0, end = nums.size() - 1;
        while (start < end)
        {
            int sum = nums[start] + nums[end];
            if (sum == target)
            {
                ans.push_back(start + 1);
                ans.push_back(end + 1);
                return ans;
            }
            else if (sum > target)
                end--;
            else
                start++;
        }
        return ans;
    }
};
