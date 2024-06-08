class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();

        unordered_map<int, int> mp;

        mp[0] = -1; // Corner Case
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];

            int rem = sum % k;

            // If rem is found, check for size otherwise add to the map
            if (mp.find(rem) != mp.end())
            {
                if (i - mp[rem] >= 2)
                    return true;
            }
            // No Modification done if an index is present before
            else
                mp[rem] = i;
        }
        return false;
    }
};

/*
Using the Formula:
31 % 4 = 3
31 % (4 * k) = 3 (means with any multiple of 4, modulus will always return 3)

1. [23,2,6,4,7], k = 6
True
2. [23,2,6,4,7], k = 13
False
3. [1, 2, 3] , k = 6 (Corner Case that why 0 index should be settled as -1 before)
True 
*/