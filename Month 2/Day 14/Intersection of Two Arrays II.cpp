// Way - I (Hashing)
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> mp;
        vector<int> ans;
        for (int i : nums1)
            mp[i]++;

        for (int i = 0; i < nums2.size(); i++)
        {
            int num = nums2[i];
            if (mp[num] > 0)
            {
                ans.push_back(num);
                mp[num]--;
            }
        }
        return ans;
    }
};

// Way - II (Two Pointers)
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size(), n2 = nums2.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        vector<int> ans;
        while (i < n1 && j < n2)
        {
            if (nums1[i] == nums2[j])
            {
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
            else if (nums1[i] < nums2[j])
                i++;
            else
                j++;
        }
        return ans;
    }
};