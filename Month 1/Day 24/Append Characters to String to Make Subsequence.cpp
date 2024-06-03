class Solution
{
public:
    int appendCharacters(string s, string t)
    {
        int i = 0, j = 0;
        int m = s.size(), n = t.size();
        int count = 0;
        while (i < m)
        {
            if (s[i] == t[j])
            {
                count++;
                i++;
                j++;
            }
            else
                i++;
        }
        return n - count;
    }
};
/*
Find the longest subsequence of t in s.
1. Two pointers to iterate through both strings. 
2. If both match, increment both pointers otherwise increase first string pointer.
*/