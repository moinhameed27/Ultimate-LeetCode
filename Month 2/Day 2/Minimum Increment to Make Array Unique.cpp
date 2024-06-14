class Solution
{
public:
    int minIncrementForUnique(vector<int> &nums)
    {
        int n = nums.size();
        int moves = 0;
        sort(nums.begin(), nums.end());

        for (int i = 1; i < n; i++)
        {
            if (nums[i] <= nums[i - 1])
            {
                // Number of moves to make the elements equal and plus one for to element to be unique
                moves += nums[i - 1] - nums[i] + 1;
                // Now updating the current element by adding 1 to it's previous element
                nums[i] = nums[i - 1] + 1;
            }
        }
        return moves;
    }
};