class Solution
{
    void reverseString(string &s, int i, int j)
    {
        while (i < j)
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }

public:
    string reverseStr(string s, int k)
    {
        int n = s.size();
        // For every 2k characters from the start
        for (int i = 0; i < n; i += 2 * k)
        {
            // If greater than or equal to k characters left, reverse the first k
            if (i + k <= n)
                reverseString(s, i, i + k - 1);
            // Otherwise reverse the remaining string
            else
                reverseString(s, i, n - 1);
        }
        return s;
    }
};