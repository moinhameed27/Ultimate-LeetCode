// Way - I (Hashing)
class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        for (int i : nums)
            freq[i]++;

        vector<int> ans;

        for (auto &it : freq)
            if (it.second == 1)
                ans.push_back(it.first);

        return ans;
    }
};

// Way - II (Bit Manipulation)
class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        long long xor_r = 0;
        // XOR of all elements. Final result will be XOR of two single elements, twice elements will cancel each other
        for (int &num : nums)
            xor_r ^= num;

        // Mask will have the first bit which is different for the two single elements and on this basis we'll divide them into 2 groups
        int mask = (xor_r) & (-xor_r);

        int groupa = 0, groupb = 0;

        for (int &num : nums)
        {
            if (num & mask)
                groupa ^= num;
            else
                groupb ^= num;
        }

        return {groupa, groupb};
    }
};