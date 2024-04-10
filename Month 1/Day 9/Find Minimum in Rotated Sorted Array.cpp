class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int start = 0, middle, end = nums.size() - 1;
        while (start < end)
        {
            middle = (start + end) / 2;
            if (nums[middle] < nums[end])
                end = middle;
            else
                start = middle + 1;
        }
        return nums[start];
    }
};
