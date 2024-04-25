// Way - I(Sorting the Array & Adding to sum)
class Solution
{
public:
    int maximizeSum(vector<int> &nums, int k)
    {
        int n = nums.size();
        // Sorting the Array to get the maximum element
        sort(nums.begin(), nums.end());
        int sum = 0;

        for (int i = 0; i < k; i++)
        {
            sum += nums[n - 1];
            nums[n - 1]++;
        }
        return sum;
    }
};

// Way - II(Finding Only Max Element of the Array)
class Solution
{
public:
    int maximizeSum(vector<int> &nums, int k)
    {
        auto maxIt = max_element(nums.begin(), nums.end());
        int maxIdx = distance(nums.begin(), maxIt);

        int sum = 0;
        for (int i = 0; i < k; i++)
        {
            sum += nums[maxIdx];
            nums[maxIdx]++;
        }
        return sum;
    }
};
