// Way - I (Max and Min Heap)
class Solution
{
public:
    typedef pair<int, int> P;
    int longestSubarray(vector<int> &nums, int limit)
    {
        int n = nums.size();
        // Max Heap
        priority_queue<P> maxPQ;
        // Min Heap
        priority_queue<P, vector<P>, greater<P>> minPQ;

        int i = 0, j = 0, maxLength = 0;
        while (j < n)
        {
            // Pushing elements to both heaps
            maxPQ.push({nums[j], j});
            minPQ.push({nums[j], j});

            // Check if subarray is valid or not (Max element in the subarray - min element in the subarray)
            while (maxPQ.top().first - minPQ.top().first > limit)
            {
                // Shrink from left, i will go to either of the heaps top minimum's index
                i = min(maxPQ.top().second, minPQ.top().second) + 1;
                // Removing elements which are not in the subarray (i - j)
                while (i > maxPQ.top().second)
                    maxPQ.pop();
                while (i > minPQ.top().second)
                    minPQ.pop();
            }
            maxLength = max(maxLength, j - i + 1);
            j++;
        }
        return maxLength;
    }
};

// Way - II (Multiset)
class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        int n = nums.size();
        multiset<int> st;

        int i = 0, j = 0, maxLength = 0;
        while (j < n)
        {
            st.insert(nums[j]);
            // Checking if subarray is valid or not
            while (*st.rbegin() - *st.begin() > limit)
            {
                // Erase the elements which are disrupting the subarray to be good
                st.erase(st.find(nums[i]));
                i++;
            }
            maxLength = max(maxLength, j - i + 1);
            j++;
        }
        return maxLength;
    }
};

/*
-------------------------------------------------------------------------------------------------------------------------------------
Way - I (Heaps)
* Separate heaps for minimum element and maximum element
* Separately maintain both heaps
Way - II (Multiset)
* Contains dupliactes
* Keeps the elements in sorted order
* Delete elements efficiently
*/