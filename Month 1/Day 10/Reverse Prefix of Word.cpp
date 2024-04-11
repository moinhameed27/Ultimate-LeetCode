// Find the first occurrence of 'ch' character and reverse from 0 index to that 'ch' index

class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        int i = 0, j = 0;
        for (int k = 0; k < word.size(); k++)
        {
            if (word[k] == ch)
            {
                j = k;
                break;
            }
        }

        while (i < j)
        {
            swap(word[i], word[j]);
            i++;
            j--;
        }
        return word;
    }
};