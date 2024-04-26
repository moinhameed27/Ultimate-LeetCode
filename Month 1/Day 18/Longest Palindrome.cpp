/*
Count number of occurrences of all characters of the string. Then count the number of characters which are
present in odd number. For string to be a palindrome, there's a simple check:
--> If all characters are present in even number of times, string is palindrome.
--> If there are characters present with odd occurrences, then there can be only one odd character used to make the
string palindrome. All rest odd characters should be removed.
--> i.e aabccdee = ace_eca (_ can be either b or d but not both)
*/

class Solution {
public:
    int longestPalindrome(string s) {
        int oddCharacters = 0;
        unordered_map<char, int> freq;
        for(char ch : s)
            freq[ch]++;
        
        for(auto i : freq)
        {
            if(i.second % 2 == 1)
                oddCharacters++;
        }
        
        if(oddCharacters > 1)
            return s.size() - oddCharacters + 1;
        
        return s.size();
        
    }
};