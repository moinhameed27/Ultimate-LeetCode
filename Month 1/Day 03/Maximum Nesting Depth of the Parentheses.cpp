class Solution
{
public:
    int maxDepth(string s)
    {
        int openBrackets = 0, ans = 0;
        for (char ch : s) 
        {
            // If found '(', increment the counter 
            if (ch == '(')
                openBrackets++;
            // If found ')', decrement the counter
            else if (ch == ')')
                openBrackets--;
            // Update the answer with the maximum of counter
            ans = max(ans, openBrackets);
        }
        return ans;
    }
};
