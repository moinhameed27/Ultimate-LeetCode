// Way - I (Set)
class Solution
{
public:
    int longestPalindrome(string s)
    {
        int n = s.size();
        unordered_set<char> st;
        int ans = 0;

        for (char &ch : s)
        {
            // If the character already is present in set, then these 2 can make a palindrome so add 2 to answer and remove the character
            if (st.count(ch))
            {
                ans += 2;
                st.erase(ch);
            }
            // Otherwise insert the character into set
            else
                st.insert(ch);
        }

        // If set is not empty, means there are odd frequency of elements present in the set, we can only take one of them
        if (!st.empty())
            ans++;

        return ans;
    }
};

// Way - II (Map Frequency Count)
class Solution
{
public:
    int longestPalindrome(string s)
    {
        int n = s.size();
        int ans = 0;
        bool oddPresent = false;
        unordered_map<char, int> mp;

        for (char &ch : s)
            mp[ch]++;

        for (auto it : mp)
        {
            // If frequency is even, we can take all characters
            if (it.second % 2 == 0)
                ans += it.second;
            // If frequency is odd, we can take the even characters which will be (characters - 1)
            else
            {
                ans += it.second - 1;
                oddPresent = true;
            }
        }

        // If there are odd characters present, we can take one of them
        if (oddPresent)
            ans++;

        return ans;
    }
};

// Way - III (Counting Odd Frequency of Characters)
/*
Count number of occurrences of all characters of the string. Then count the number of characters which are
present in odd number. For string to be a palindrome, there's a simple check:
--> If all characters are present in even number of times, string is palindrome.
--> If there are characters present with odd occurrences, then there can be only one odd character used to make the
string palindrome. All rest odd characters should be removed.
--> i.e aabccdee = ace_eca (_ can be either b or d but not both)
*/
class Solution
{
public:
    int longestPalindrome(string s)
    {
        int oddCharacters = 0;
        int n = s.size();
        unordered_map<char, int> freq;
        for (char ch : s)
            freq[ch]++;

        for (auto i : freq)
        {
            if (i.second % 2 == 1)
                oddCharacters++;
        }

        if (oddCharacters > 1)
            return n - oddCharacters + 1;

        return n;
    }
};

// Way - IV (One Iteration)
class Solution
{
public:
    int longestPalindrome(string s)
    {
        int n = s.size();
        int ans = 0;
        int oddFreq = 0;
        unordered_map<char, int> mp;

        // Count the number of odd Frequencies
        for (char &ch : s)
        {
            mp[ch]++;

            if (mp[ch] % 2 == 1)
                oddFreq++;
            else
                oddFreq--;
        }

        // If there are more than 1 odd characters, we can take only one of them
        if (oddFreq > 0)
            return n - oddFreq + 1;

        return n;
    }
};