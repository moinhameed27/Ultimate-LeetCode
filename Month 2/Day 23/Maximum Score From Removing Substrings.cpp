// Way - I (Stack)
/*
1. Go with two passes, remove the string with bigger score in the first pass and second string in second pass.
2. Count the pairs removed in each pair and calculate score.
*/
class Solution
{
    string eraseSubstr(string &s, string &matchStr)
    {
        stack<char> st;
        for (char &ch : s)
        {
            // If current string matches the given string, remove both from stack
            if (ch == matchStr[1] && !st.empty() && st.top() == matchStr[0])
                st.pop();
            else
                st.push(ch);
        }

        // At the end of loop, the characters which are not removed will be in the stack
        string remStr;
        while (!st.empty())
        {
            remStr += st.top();
            st.pop();
        }
        // As storing from stack will store in reverse order, so we'll reverse again to get the required string
        reverse(remStr.begin(), remStr.end());
        return remStr;
    }

public:
    int maximumGain(string s, int x, int y)
    {
        int n = s.size();
        // Find the string with bigger and lower score
        string maxStr = (x > y) ? "ab" : "ba";
        string minStr = (x < y) ? "ab" : "ba";

        int maxScore = 0;

        // First Pass - Remove the string with bigger score
        string strFirst = eraseSubstr(s, maxStr);
        int l = strFirst.size();  // Size of new string
        int charsRemoved = n - l; // Number of characters removed from original string
        // To get pairs from characters removed, divide by 2 and to calculate score, multiply with higher score (As it's first pass)
        maxScore += (charsRemoved / 2) * max(x, y);

        // Second Pass - Remove the string with lower score
        string strSecond = eraseSubstr(strFirst, minStr);
        charsRemoved = l - strSecond.size(); // Number of characters removed from original string
        // To get pairs from characters removed, divide by 2 and to calculate score, multiply with higher score (As it's first pass)
        maxScore += (charsRemoved / 2) * min(x, y);

        return maxScore;
    }
};

// Way - II (Constant Space [Two Pointers])
/*
1. Take two pointers - i for writing and j for reading.
2. j will keep moving and i will store the jth character in ith index.
3. After storing i will check if it's previous two indices matches given string, it will go back two indices to garbage them and store
   the next characters in its place.
4. When j will end traversal, the string before i will be the required string after removal, so we'll remove the next part starting from i.
*/
class Solution
{
    string eraseSubstr(string &s, string &matchStr)
    {
        int i = 0;
        for (int j = 0; j < s.size(); j++)
        {
            s[i] = s[j];
            i++;
            if (i >= 2 && s[i - 2] == matchStr[0] && s[i - 1] == matchStr[1])
                i -= 2;
        }
        s.erase(s.begin() + i, s.end());
        return s;
    }

public:
    int maximumGain(string s, int x, int y)
    {
        int n = s.size();
        // Find the string with bigger and lower score
        string maxStr = (x > y) ? "ab" : "ba";
        string minStr = (x < y) ? "ab" : "ba";

        int maxScore = 0;

        // First Pass - Remove the string with bigger score
        string strFirst = eraseSubstr(s, maxStr);
        int l = strFirst.size();  // Size of new string
        int charsRemoved = n - l; // Number of characters removed from original string
        // To get pairs from characters removed, divide by 2 and to calculate score, multiply with higher score (As it's first pass)
        maxScore += (charsRemoved / 2) * max(x, y);

        // Second Pass - Remove the string with lower score
        string strSecond = eraseSubstr(strFirst, minStr);
        charsRemoved = l - strSecond.size(); // Number of characters removed from original string
        // To get pairs from characters removed, divide by 2 and to calculate score, multiply with higher score (As it's first pass)
        maxScore += (charsRemoved / 2) * min(x, y);

        return maxScore;
    }
};