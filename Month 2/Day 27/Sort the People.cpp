// Way - I (Selection Sort [1])
class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        int n = names.size();
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                if (heights[j] < heights[j + 1])
                {
                    swap(heights[j], heights[j + 1]);
                    swap(names[j], names[j + 1]);
                }
            }
        }
        return names;
    }
};

// Way - II (Selection Sort [2])
class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        int n = names.size();
        for (int i = 0; i < n - 1; i++)
        {
            int maxi = i;
            for (int j = i + 1; j < n; j++)
            {
                if (heights[j] > heights[maxi])
                    maxi = j;
            }
            swap(heights[i], heights[maxi]);
            swap(names[i], names[maxi]);
        }
        return names;
    }
};

// Way - III (Making Pairs and Sorting)
class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        int n = names.size();
        vector<pair<int, string>> v;
        for (int i = 0; i < n; i++)
            v.push_back({heights[i], names[i]});

        sort(v.begin(), v.end(), greater<>());

        for (int i = 0; i < n; i++)
            names[i] = v[i].second;
        return names;
    }
};

// Way - IV (Hashing)
class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        int n = names.size();

        unordered_map<int, string> mp;
        for (int i = 0; i < n; i++)
            mp[heights[i]] = names[i];

        sort(heights.begin(), heights.end(), greater<>());

        for (int i = 0; i < n; i++)
            names[i] = mp[heights[i]];

        return names;
    }
};
