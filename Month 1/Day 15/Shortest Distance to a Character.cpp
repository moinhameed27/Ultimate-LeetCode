// Way - I (Two Pointers)
class Solution
{
public:
    vector<int> shortestToChar(string s, char c)
    {
        int n = s.size();
        int i = 0, j = 0, closest = n;    // Any value greater than n can be taken
        vector<int> ans;
        while (i < n)
        {
            if (s[j] == c)
            {
                while (i <= j)
                {
                    int distance = min(abs(i - j), abs(closest - i));
                    ans.push_back(distance);
                    i++;
                }
                closest = j;
            }
            else if (j == n - 1)
            {
                while (i <= j)
                {
                    int distance = abs(closest - i);
                    ans.push_back(distance);
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};

// Way - II (Scan from left to right and from right to left)
class Solution
{
public:
    vector<int> shortestToChar(string s, char c)
    {
        int n = s.size(), closest = n;  // Any value greater than n can be taken(For correct first index calculation)
        vector<int> ans(n, n);

        // Scan from Left to Right
        for (int i = 0; i < n; i++)
        {
            if (s[i] == c)
                closest = i;
            ans[i] = min(ans[i], abs(i - closest));
        }

        // Scan from Left to Right
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == c)
                closest = i;
            ans[i] = min(ans[i], abs(i - closest));
        }
        return ans;
    }
};