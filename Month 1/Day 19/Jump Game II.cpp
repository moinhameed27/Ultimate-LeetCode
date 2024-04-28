class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int current = 0, jumps = 0, farthest = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            // Farthest we can reach from current index
            farthest = max(farthest, nums[i] + i);
            // We've checked all paths, and stored the farthest also, so we need to take a jump from here
            if (current == i)
            {
                current = farthest;
                jumps++;
            }
        }
        return jumps;
    }
};
