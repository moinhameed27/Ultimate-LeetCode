class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        int i = 0, j = nums.size() - 1;
        // When both pointers point to opposite numbers i.e i = odd & j = even swap them otherwise keep moving
        while (i < j)
        {
            if (nums[i] % 2 == 0)
                i++;
            else if (nums[j] % 2 != 0)
                j--;
            else
                swap(nums[i], nums[j]);
        }
        return nums;
    }
};