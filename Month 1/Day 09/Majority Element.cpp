// Way - I (Counting the Frequency and Getting the Majority element)

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int size = nums.size();
        // Using map instead of a vector as the elements can be negative as well
        map<int, int> freqMap;

        for (int i = 0; i < size; i++)
        {
            // Frequencies stored on particular indexes of the map(keys of maps)
            freqMap[nums[i]]++;
        }

        int maxElement = 0, maxFreq = 0;

        for (auto mp : freqMap)
        {
            {
                // mp.first is key(index or element) and mp.second is value at the specific index/key
                if (mp.second > maxFreq)
                    maxElement = mp.first;
                maxFreq = mp.second;
            }
        }

        return maxElement;
    }
};

// Way - II (Boyer-Moore Voting Algorithm)

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int element = nums[0];
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (count == 0)
                element = nums[i];
            count += (element == nums[i]) ? 1 : -1;
        }
        return element;
    }
};
