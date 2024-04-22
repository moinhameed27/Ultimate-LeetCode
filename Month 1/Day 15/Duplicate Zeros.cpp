class Solution
{
public:
    void duplicateZeros(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            int j = n - 1;
            // If current index is zero, right shift the array one time
            if (arr[i] == 0)
            {
                while (j > i)
                {
                    arr[j] = arr[j - 1];
                    j--;
                }
                i++;    // As there will be one duplicate zero added in this scenario, increment i to skip that zero
            }
        }
    }
};