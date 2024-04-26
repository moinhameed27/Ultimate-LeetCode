class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        int n = s.size();
        string ans;
        // Taken array to check if current character is repeating 
        vector<bool> taken(26, false);
        // Last index array to check the last index of character in the string
        vector<int> lastIndex(26);

        // Storing the last indices of all characters
        for (int i = 0; i < n; i++)
            lastIndex[s[i] - 'a'] = i;


        for (int i = 0; i < n; i++)
        {
            char ch = s[i];

            // If character is repeating, skip
            if (taken[ch - 'a'] == true)
                continue;

            // If last character of answer is larger than current, means order is not being followed
            // and the character is also present in the later part of the string
            while (ans.size() > 0 && ans.back() > ch && lastIndex[ans.back() - 'a'] > i)
            {
                // Unmarking the presence of the character
                taken[ans.back() - 'a'] = false;
                // Removing from the answer so that it can be added afterwards
                ans.pop_back();
            }

            // Marking the presence of the character
            taken[ch - 'a'] = true;
            // Adding to the answer
            ans.push_back(ch);
        }
        return ans;
    }
};