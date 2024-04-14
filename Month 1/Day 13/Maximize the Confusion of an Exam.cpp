// Approach - I (Brute Force - Simple Backtracking) [TLE]
/*
Backtracking - Applying recursion with one time flipping and decreasing the k and next time without flipping with same k 
*/
class Solution
{
public:
    int ans = 0;
    int n;

    void findMax(string answerKey)
    {
        int length = 0;
        int i = 0;
        while (i < n)
        {
            if (answerKey[i] == 'T')
            {
                length = 1;
                i++;
                while (i < n && answerKey[i] == 'T')
                {
                    length++;
                    i++;
                }
                ans = max(ans, length);
            }
            else
            {
                length = 1;
                i++;
                while (i < n && answerKey[i] == 'F')
                {
                    length++;
                    i++;
                }
                ans = max(ans, length);
            }
        }
    }

    void solve(int idx, string &answerKey, int k)
    {

        findMax(answerKey);

        if (idx >= n || k <= 0)
        {
            return;
        }

        answerKey[idx] = answerKey[idx] == 'T' ? 'F' : 'T'; // Flipped

        solve(idx + 1, answerKey, k - 1);

        answerKey[idx] = answerKey[idx] == 'T' ? 'F' : 'T'; // Flipped back
        solve(idx + 1, answerKey, k);
    }

    int maxConsecutiveAnswers(string answerKey, int k)
    {
        n = answerKey.length();

        solve(0, answerKey, k);

        return ans;
    }
};

// Approach - II (2 Pass Sliding Window)
class Solution
{
public:
    int maxConsecutiveAnswers(string answerKey, int k)
    {
        int n = answerKey.length();
        int ans = 0;

        // Case - I ('F' --> 'T')
        int i = 0, j = 0;
        int countF = 0;
        while (j < n)
        {
            if (answerKey[j] == 'F')
                countF++;

            while (countF > k)
            {
                if (answerKey[i] == 'F')
                    countF--;
                i++;
            }

            ans = max(ans, j - i + 1);

            j++;
        }

        // Case - I ('F' --> 'T')
        i = 0, j = 0;
        int countT = 0;
        while (j < n)
        {
            if (answerKey[j] == 'T')
                countT++;

            while (countT > k)
            {
                if (answerKey[i] == 'T')
                    countT--;
                i++;
            }

            ans = max(ans, j - i + 1);
            j++;
        }

        return ans;
    }
};

// Approach - III (1 Pass Sliding Window)
class Solution
{
public:
    int maxConsecutiveAnswers(string answerKey, int k)
    {
        int n = answerKey.size();
        unordered_map<char, int> freq;
        int i = 0, j = 0;
        int ans = 0;
        while (j < n)
        {
            freq[answerKey[j]]++;
            while (min(freq['T'], freq['F']) > k)
            {
                freq[answerKey[i]]--;
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};