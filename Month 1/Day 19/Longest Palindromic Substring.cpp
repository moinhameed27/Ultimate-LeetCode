// Way - I (Iterative - Two Pointers - Brute Force)
class Solution
{
public:
    bool isPalindrome(string &s, int i, int j)
    {

        while (i <= j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }

        return true;
    }

    string longestPalindrome(string s)
    {
        int n = s.length();

        int maxLength = INT_MIN;
        int startIdx = 0;

        // Check from the start
        for (int i = 0; i < n; i++)
        {
            // Start checking from i'th character to n
            for (int j = i; j < n; j++)
            {
                // If current substring is Palindrome and it's length is greater than previous max Substring, update
                if (isPalindrome(s, i, j) && j - i + 1 > maxLength)
                {
                    startIdx = i;
                    maxLength = j - i + 1;
                }
            }
        }

        return s.substr(startIdx, maxLength);
    }
};

// Way - II (Recursion + Memoization
class Solution
{
public:
    int t[1001][1001];
    bool isPalindrome(string &s, int i, int j)
    {
        if (i >= j)
            return 1;

        if (t[i][j] != -1)
            return t[i][j];

        if (s[i] == s[j])
            return t[i][j] = isPalindrome(s, i + 1, j - 1);

        return t[i][j] = false;
    }

    string longestPalindrome(string s)
    {
        int n = s.length();
        memset(t, -1, sizeof(t));
        int maxLength = INT_MIN;
        int startIdx = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (isPalindrome(s, i, j))
                {
                    if (j - i + 1 > maxLength)
                    {
                        startIdx = i;
                        maxLength = j - i + 1;
                    }
                }
            }
        }

        return s.substr(startIdx, maxLength);
    }
};)