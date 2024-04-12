/*
If a open bracket is accompanied by closing bracket, decrease the counter as it is not disturbing our pattern.
By doing this, we'll be left with only open brackets. So we'll return the half size of them.
*/

class Solution
{
public:
    int minSwaps(string s)
    {
        int ans = 0;

        for (char ch : s)
        {
            if (ch == '[')
                ans++;
            else if (ans != 0)
                ans--;
        }
        return (ans + 1) / 2;
    }
};