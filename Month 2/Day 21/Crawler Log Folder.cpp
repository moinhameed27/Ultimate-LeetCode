// Way - I (Constant Space)
class Solution
{
public:
    int minOperations(vector<string> &logs)
    {
        int ops = 0;
        for (string st : logs)
        {
            if (st == "../")
                ops = max(0, ops - 1);
            else if (st == "./")
                continue;
            else
                ops++;
        }
        return ops;
    }
};

// Way - II (Stack)
class Solution
{
public:
    int minOperations(vector<string> &logs)
    {
        stack<int> st;
        for (string str : logs)
        {
            if (str == "../")
            {
                if (!st.empty())
                    st.pop();
            }
            else if (str == "./")
                continue;
            else
                st.push(1);
        }
        return st.size();
    }
};