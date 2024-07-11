// Way - I (Stack)
/*
1. When an open bracket is seen, push it's index to stack.
2. When a close bracket is seen, get the index of it's opening bracket and reverse that part.
*/
class Solution
{
public:
    string reverseParentheses(string s)
    {
        stack<int> bracketIdx;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                bracketIdx.push(i);
            else if (s[i] == ')')
            {
                int j = bracketIdx.top();
                bracketIdx.pop();
                reverse(s.begin() + j + 1, s.begin() + i);
            }
        }

        string ans;
        for (auto ch : s)
        {
            if (ch != '(' && ch != ')')
                ans += ch;
        }
        return ans;
    }
};

// Way - II (Stack)
/*
1. If character is seen, push it to another string.
2. If an open bracket encounters, get the count of it's previous characters.
3. When close bracket comes, reverse the part of string starting from the index saved above till now.
*/
class Solution
{
public:
    string reverseParentheses(string s)
    {
        stack<int> bracketIdx;
        string ans;
        for (auto ch : s)
        {
            if (ch == '(')
                bracketIdx.push(ans.size());
            else if (ch == ')')
            {
                int idx = bracketIdx.top();
                bracketIdx.pop();
                reverse(ans.begin() + idx, ans.end());
            }
            else
                ans += ch;
        }
        return ans;
    }
};

// Way - III (Wormhole Teleportation [Stack])
/*
1. Find the mapping of opening braces with close and closing braces with open.
2. So in the second pass, when going RTL, if open bracket comes, go to it's respective closing bracket and store the characters in another string.
3. If braces come in between, go to their respective brackets and change the direction each time.
*/
class Solution
{
public:
    string reverseParentheses(string s)
    {
        stack<int> bracketIdx;
        int n = s.size();
        vector<int> door(n);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                bracketIdx.push(i);
            else if (s[i] == ')')
            {
                int j = bracketIdx.top();
                bracketIdx.pop();
                door[i] = j;
                door[j] = i;
            }
        }

        int direction = 1;
        string ans;
        for (int i = 0; i < n; i += direction)
        {
            if (s[i] == '(' || s[i] == ')')
            {
                i = door[i];
                direction = -direction;
            }
            else
                ans += s[i];
        }
        return ans;
    }
};
