// Duplicate Problem : 1296. Divide Array in Sets of K Consecutive Numbers

// Way - I (Hashing + Brute Force)
class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        int n = hand.size();
        // If number of groups of groupSize are not possible
        if (n % groupSize != 0)
            return false;

        // Counting frequency of elements in ordered map
        map<int, int> freq;
        for (int i : hand)
            freq[i]++;

        // Loop will run for n / groupSize (Number of Groups)
        for (int i = 0; i < n / groupSize; i++)
        {
            vector<int> v;
            auto it = freq.begin();
            // Loop will run for number of elements
            for (int j = 0; it != freq.end() && j < groupSize; it++)
            {
                // If it's first element or the two elements are consecutive
                if (it->second > 0 && (v.empty() || it->first == v.back() + 1))
                {
                    v.push_back(it->first);
                    it->second--;
                    j++;
                }
                // If Elements are not consecutive
                else if (it->second > 0 && !v.empty() && abs(it->first - v.back()) != 1)
                    return false;
            }

            // Check if array made is of groupSize elements
            if (v.size() != groupSize)
                return false;
        }
        return true;
    }
};