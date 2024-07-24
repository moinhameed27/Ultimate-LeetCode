// Way - I (Brute Force [String])
class Solution
{
    string getMappedNum(string numStr, vector<int> &mapping)
    {
        string mappedStr = "";
        for (int i = 0; i < numStr.size(); i++)
        {
            // Mapping the digit to the new number and storing it in the string
            char ch = numStr[i];
            mappedStr += to_string(mapping[ch - '0']);
        }
        return mappedStr;
    }

public:
    vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums)
    {
        int n = nums.size();
        // Pair of (mappedNum, originalindex)
        vector<pair<int, int>> vp;
        for (int i = 0; i < n; i++)
        {
            // Convert the number to string and map each digit to the new number
            string numStr = to_string(nums[i]);
            string mappedStr = getMappedNum(numStr, mapping);
            // Convert the mapped string to integer and store in the vector of pairs
            int mappedNum = stoi(mappedStr);
            vp.push_back({mappedNum, i});
        }   

        // Sort on the basis of mappedNum
        sort(vp.begin(), vp.end());
        vector<int> ans;
        // Store the result answer according to the original index of nums elements
        for (auto p : vp)
        {
            int idx = p.second;
            ans.push_back(nums[idx]);
        }
        return ans;
    }
};

// Way - II (Better)
class Solution
{
    int getMappedNum(int num, vector<int> &mapping)
    {
        // If the number is less than 10, return the mapped number (No Need for Loop)
        if (num < 10)
            return mapping[num];

        // Go through each digit of the number and map it to the new number
        int placeValue = 1, mappedNum = 0;
        while (num)
        {
            int lastDigit = num % 10;
            int mappedDigit = mapping[lastDigit];
            mappedNum += placeValue * mappedDigit;
            placeValue *= 10;
            num /= 10;
        }
        return mappedNum;
    }

public:
    vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums)
    {
        int n = nums.size();
        // Pair of (mappedNum, originalindex)
        vector<pair<int, int>> vp;
        for (int i = 0; i < n; i++)
        {
            int mappedNum = getMappedNum(nums[i], mapping);
            vp.push_back({mappedNum, i});
        }

        // Sort on the basis of mappedNum
        sort(vp.begin(), vp.end());
        vector<int> ans;
        // Get the original number from the original index and return the answer
        for (auto p : vp)
        {
            int idx = p.second;
            ans.push_back(nums[idx]);
        }
        return ans;
    }
};