class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        map<int, int> mp;
        int n = arr2.size();
        // Storing the Frequency of arr1 elements
        for (int &i : arr1)
            mp[i]++;

        // Placing the arr1 elements according to arr2 elements order
        int i = 0, j = 0;
        while (i < n)
        {
            while (mp[arr2[i]] > 0)
            {
                arr1[j++] = arr2[i];
                mp[arr2[i]]--;
            }
            i++;
        }

        // For the elements which are only present in arr1, place them on the end
        for (auto &it : mp)
        {
            while (it.second > 0)
            {
                arr1[j++] = it.first;
                it.second--;
            }
        }

        return arr1;
    }
};