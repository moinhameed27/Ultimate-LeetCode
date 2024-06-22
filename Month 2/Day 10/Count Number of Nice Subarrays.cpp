// Way - I (Sliding Window)
class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        int oddNums = 0, countSubarrays = 0;
        int i = 0, j = 0, count = 0;
        while (j < n)
        {
            // If current number is odd, increase the count of odd numbers and reinitialize the previous count of subarrays
            if (nums[j] % 2 == 1)
                oddNums++, count = 0;
            while (oddNums == k)
            {
                count++;
                // If after shrinking the window from left, number removed was odd, decrease the count of odd numbers
                if (i < n && nums[i] % 2 == 1)
                    oddNums--;
                i++;
            }
            countSubarrays += count;
            j++;
        }
        return countSubarrays;
    }
};

// Way - II (Hashing)
class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        int count = 0, oddNums = 0;

        unordered_map<int, int> mp;
        mp[0] = 1; // As at the start of array, odd Count is 1

        for (int i = 0; i < n; i++)
        {
            oddNums += (nums[i] % 2);
            // If odd Nums were present before, add it's count to total count
            if (mp.find(oddNums - k) != mp.end())
                count += mp[oddNums - k];
            mp[oddNums]++;
        }
        return count;
    }
};

/*
Test Cases:
nums = [1, 2], k = 1
nums = [1, 2, 1], k = 1
nums = [2, 1, 2, 1], k = 1
*/