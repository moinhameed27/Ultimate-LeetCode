class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        vector<int> dup(heights);
        sort(dup.begin(), dup.end());
        int n = heights.size(), count = 0;
        for (int i = 0; i < n; i++)
        {
            if (heights[i] != dup[i])
                count++;
        }
        return count;
    }
};