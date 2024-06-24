// Way - I (O(n) Space)
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size(), k = 3;
        int flips = 0, flipCountFromI = 0;
        // To check whether flip was done on index i or not
        vector<bool> isFlipped(n, false);
        for (int i = 0; i < n; i++)
        {
            // If current index is out of reach of prevoius flipped subarray
            if (i >= k && isFlipped[i - k] == true)
                flipCountFromI--;
            if (flipCountFromI % 2 == nums[i])
            {
                // If subarray is not possible to flip
                if (i + k > n)
                    return -1;
                flipCountFromI++;
                flips++;
                // Marking the index that it was flipped
                isFlipped[i] = true;
            }
        }
        return flips;
    }
};

// Way - II (Constant Space but In-Place modification)
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size(), k = 3;
        int flips = 0, flipCountFromI = 0;
        for (int i = 0; i < n; i++)
        {
            // If current index is out of reach of prevoius flipped subarray
            if (i >= k && nums[i - k] == 23)
                flipCountFromI--;
            if (flipCountFromI % 2 == nums[i])
            {
                // If subarray is not possible to flip
                if (i + k > n)
                    return -1;
                flipCountFromI++;
                flips++;
                // Marking the index that it was flipped
                nums[i] = 23;
            }
        }
        return flips;
    }
};

// Way - III (Better than O(n) space and In-Place Modification)
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size(), k = 3;
        int flips = 0, flipCountFromI = 0;
        deque<int> dq;
        for (int i = 0; i < n; i++)
        {
            if (i >= k)
            {
                flipCountFromI -= dq.front();
                dq.pop_front();
            }

            if (flipCountFromI % 2 == nums[i])
            {
                if (i + k > n)
                    return -1;
                flipCountFromI++;
                flips++;
                dq.push_back(1);
            }
            else
                dq.push_back(0);
        }
        return flips;
    }
};
