class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        // a --> First Pointer, b --> Primary Pointer, c --> Pointer from the last
        int a = 0, b = 0;
        int c = n - 1;

        while (b <= c)
        {
            // If element is 0, swap it to the start
            if (nums[b] == 0)
            {
                swap(nums[a], nums[b]);
                a++;
                b++;
            }
            // If element is 1, keep the place and increase the pointer
            else if (nums[b] == 1)
                b++;
            // If element is 2, swap it to the last element and decrease the pointer
            else
            {
                swap(nums[b], nums[c]);
                c--;
            }
        }
    }
};