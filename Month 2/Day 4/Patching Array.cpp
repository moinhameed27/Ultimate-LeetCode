class Solution
{
public:
    int minPatches(vector<int> &nums, int n)
    {
        int i = 0, s = nums.size();
        int patches = 0;
        long maxReach = 0;
        // Traverse until maxReach is less than given value n
        while (maxReach < n)
        {
            // If index is not out of bound and the current index is equal or less than maxReach + 1
            if (i < s && nums[i] <= maxReach + 1)
                maxReach += nums[i++];
            // If there's some gap between maxReach and current number
            else
            {
                maxReach += (maxReach + 1);
                patches++;
            }
        }
        return patches;
    }
};

/*
----------------------------------------------------------------------------------------------------------
Dry Run:
nums = [1,3], n = 6
maxReach = 0, patches = 0, i = 0

--> if(true)
maxReach = 1

--> else(true)
Add the missing number 2 to the maxReach and now it can reach all numbers till 3
maxReach = 1 + 2 = 3

-----------------------------

nums = [1,5,10], n = 20
--> if(true)
maxReach = 1

--> else(true)
maxReach = 1 + 2 = 3

--> else(true)
maxReach = 3 + 4 = 7

--> if(true)
maxReach = 7 + 5 = 12

--> if(true)
maxReach = 12 + 10 = 22
*/