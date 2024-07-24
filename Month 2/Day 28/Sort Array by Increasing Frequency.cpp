class Solution
{
public:
    vector<int> frequencySort(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        // Storing the Frequency of each number
        for (int i : nums)
            freq[i]++;
        // Sorting on the basis of frequency
        sort(nums.begin(), nums.end(), [&](int a, int b)
            {
            // If Frequencies are not equal then return the number having low frequency
            if(freq[a] != freq[b])
                return freq[a] < freq[b];
            // Otherwise return the number having high value
            return a > b; });

        return nums;
    }
};