class Solution
{
public:
    /*
    The main thing about this question is that we have to return the minimized maximum sum of a pair and we can't
    just get the correct result by adding adjacent elements as pairs. So the approach will be to add the maximum
    number with the minimum number of the array. For this we'll sort the array and add elements by using two pointers
    approach. 
    */
    int minPairSum(vector<int> &nums)
    {
        int i = 0, j = nums.size() - 1;
        int sum = 0, ans = 0;
        sort(begin(nums), end(nums));
        while (i <= j)
        {
            sum = nums[i] + nums[j];
            ans = max(sum, ans);
            i++;
            j--;
        }
        return ans;
    }
};
