class Solution
{
public:
    bool isLongPressedName(string name, string typed)
    {
        int i = 0, j = 0, n = name.size(), t = typed.size();
        while (j < t)
        {
            // If characters match in both strings
            if (name[i] == typed[j]) 
            {
                i++;
                j++;
            }
            // Skip repeated character
            else if (j > 0 && typed[j] == typed[j - 1])
                j++;
            // Mismatched characters
            else
                return false;
        }
        // All characters in name are checked 
        return i == n;
    }
};
