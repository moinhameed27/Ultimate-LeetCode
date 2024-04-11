class Solution
{
    bool isVowel(char c)
    { 
        if ((c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ||
            (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'))
            return true;
        return false;
    } 

public:
    string reverseVowels(string s)
    {
        int i = 0, j = s.size() - 1;
        while (i <= j)
        {
            // Iterate until a vowel is not found at start
            if (!isVowel(s[i]))
                i++;
            // Iterate until a vowel is not found at end
            else if (!isVowel(s[j]))
                j--;
            // When vowels are found at both places, swap them
            else
                swap(s[i], s[j]), i++, j--;
        }
        return s;
    }
};
