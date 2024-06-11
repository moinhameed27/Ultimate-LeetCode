// Way - I (Brute Force)
class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        vector<int> result;
        // Traverse through the relative order array
        for (int i = 0; i < arr2.size(); i++)
        {
            // Traverse through the target array
            for (int j = 0; j < arr1.size(); j++)
            {
                if (arr1[j] == arr2[i])
                {
                    result.push_back(arr1[j]);
                    // Mark the element in target array as visited
                    arr1[j] = -999;
                }
            }
        }

        // Sort the remaining elements in the target array
        sort(arr1.begin(), arr1.end());
        // Add the remaining elements to the result array
        for (int i = 0; i < arr1.size(); i++)
        {
            if (arr1[i] != -999)
                result.push_back(arr1[i]);
        }
        return result;
    }
};

// Way - II (Hashing)
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

// Way - III (Better [Hashing])
class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        int n1 = arr1.size(), n2 = arr2.size();
        unordered_map<int, int> mp;
        vector<int> rem, ans;

        // Initializing elements indices of arr2
        for (int i = 0; i < n2; i++)
            mp[arr2[i]] = 0;

        // If element of arr1 is initialized in map, count frequency, otherwise push into remaining array
        for (int i = 0; i < n1; i++)
        {
            if (mp.find(arr1[i]) != mp.end())
                mp[arr1[i]]++;
            else
                rem.push_back(arr1[i]);
        }

        // Sort the remaining array to add the elements at the last
        sort(rem.begin(), rem.end());

        // Pushing elements of arr2 in answer with respect to their frequency
        for (int i = 0; i < n2; i++)
        {
            for (int j = 0; j < mp[arr2[i]]; j++)
                ans.push_back(arr2[i]);
        }

        // Add remaining elements to answer
        for (int i = 0; i < rem.size(); i++)
            ans.push_back(rem[i]);

        return ans;
    }
};

// Way - IV (Optimal [Counting])
class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        // Max Element in arr1
        int maxElement = *max_element(arr1.begin(), arr1.end());

        vector<int> count(maxElement + 1);

        // Counting the Frequency of arr1 elements
        for (int i : arr1)
            count[i]++;

        vector<int> ans;

        // Storing the elements of arr2 in ans with respect to their frequency
        for (int i : arr2)
        {
            while (count[i] > 0)
            {
                ans.push_back(i);
                count[i]--;
            }
        }

        // Adding the remaining elements to the answer
        for (int i = 0; i <= maxElement; i++)
        {
            while (count[i] > 0)
            {
                ans.push_back(i);
                count[i]--;
            }
        }
        return ans;
    }
};