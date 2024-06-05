class Solution
{
    void countFrequency(string &word, int count[26])
    {
        for (char &ch : word)
            count[ch - 'a']++;
    }

public:
    vector<string> commonChars(vector<string> &words)
    {
        vector<string> ans;
        int n = words.size();
        int count[26] = {0};

        // Count the Frequency of first string of Words Array
        countFrequency(words[0], count);

        // Then traverse whole array of strings to compare to the initial count and then modify the count if there's something different
        for (int i = 1; i < n; i++)
        {
            int temp[26] = {0};

            // Counting the frequency of ith string of words
            countFrequency(words[i], temp);

            // Taking the minimum value from both arrays, means the common characters count
            for (int j = 0; j < 26; j++)
                count[j] = min(count[j], temp[j]);
        }

        // At the end Storing the result in the answer
        for (int i = 0; i < 26; i++)
        {
            if (count[i] != 0)
            {
                // If any character's frequency is more than 1 (All duplicates are included)
                int c = count[i];
                while (c--)
                    ans.push_back(string(1, 'a' + i));
            }
        }

        return ans;
    }
};