/*
Store all the digits in an array. Sort the array and then the anwer will be ac * 10 + bd * 10
*/

class Solution
{
public:
    int minimumSum(int num)
    {
        vector<int> nums(4);
        for (int i = 0; i < 4; i++)
        {
            nums[i] = num % 10;
            num /= 10;
        }
        sort(begin(nums), end(nums));
        return (nums[0] * 10 + nums[2]) + (nums[1] * 10 + nums[3]);
    }
};