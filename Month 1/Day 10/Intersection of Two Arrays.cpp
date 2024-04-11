// Way - I (Brute-Force)
class Solution
{
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        for (int i : nums1)
        {
            bool flag = false;
            for (int j : nums2)
            {
                if (i == j)
                {
                    flag = true;
                    break;
                }
            }
            if (flag == true)
                ans.push_back(i);
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};

// Way - II (Set)
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {

        vector<int> ans;
        // Set stores unique elements only
        set<int> set1(nums1.begin(), nums1.end());

        for (int i : nums2)
        {   
            // If element is present in nums2, then add it to answer and remove it from nums1 set
            if (set1.find(i) != set1.end())
            {
                ans.push_back(i);
                set1.erase(i);
            }
        }
        return ans;
    }
};
