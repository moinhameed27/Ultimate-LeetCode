class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        // Unordered Map for counting the frequency of window characters
        unordered_map<char, int> freq;
        int n = s.size();
        int length = 0;
        int i = 0, j = 0;
        while (j < n)
        {
            // Frequency Counter
            freq[s[j]]++;
            // If a character repeats, slide the window until window doesn't have repeated characters
            while (freq[s[j]] > 1)
            {
                freq[s[i]]--;
                i++;
            }
            // Update the length with the maximum length of the window
            length = max(length, j - i + 1);
            j++;
        }
        return length;
    }
};