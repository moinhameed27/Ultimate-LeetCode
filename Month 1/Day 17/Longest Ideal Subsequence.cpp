/*
LIS(Longest Increasing Subsequence) Variant won't work here because of TLE.
So here's an approach to only traverse k indexes before and after the current index.
*/

class Solution
{
public:
    int longestIdealString(string s, int k)
    {
        int n = s.size();
        int ans = 0;
        // Array of 26 Characters initialized with zero
        vector<int> letters(26, 0);

        for (int i = 0; i < n; i++)
        {
            // Current Index 
            int curr = s[i] - 'a';
            // Left Side k elements of current index
            int left = max(0, curr - k);
            // Right Side k elements of current index
            int right = min(25, curr + k);

            int longest = 0;

            // To find the longest between the range (left, right)
            for (int j = left; j <= right; j++)
                longest = max(longest, letters[j]);

            // Updating current index of array with it's longest ideal subsequence
            letters[curr] = max(letters[curr], longest + 1);
            // Updating answer with longest ideal subsequence
            ans = max(ans, letters[curr]);
        }
        return ans;
    }
};