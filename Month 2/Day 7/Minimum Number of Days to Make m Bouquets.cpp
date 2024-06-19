// Way - I (Brute Force [Binary Search])
class Solution
{
    // Function to check whether m bouquets can be made in given days or not
    bool count(vector<int> &bloomDay, int m, int k, int days)
    {
        int count = 0, bouquets = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] <= days)
                count++;
            else
                count = 0;

            // If adjacent k flowers are found, bouquet can be made
            if (count == k)
                bouquets++, count = 0;
        }
        return bouquets >= m;
    }

public:
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int n = bloomDay.size();
        if (static_cast<long long>(m) * k > n)
            return -1;

        // Minimum number of days for a flower to bloom
        int l = *min_element(bloomDay.begin(), bloomDay.end());
        // Maximum number of days for a flwoer to bloom
        int r = *max_element(bloomDay.begin(), bloomDay.end());

        while (l < r)
        {
            int mid = l + (r - l) / 2;
            // If bouquets can be made in mid days, try for less days
            if (count(bloomDay, m, k, mid))
                r = mid;
            // If bouquets can't be made, go for more days
            else
                l = mid + 1;
        }
        return l;
    }
};

// Way - II (A Little Change)
class Solution
{
    bool count(vector<int> &bloomDay, int m, int k, int days)
    {
        int count = 0, bouquets = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] <= days)
                count++;
            else
                count = 0;

            if (count == k)
                bouquets++, count = 0;
        }
        return bouquets >= m;
    }

public:
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        // Minimum number of days for a flower to bloom
        int l = *min_element(bloomDay.begin(), bloomDay.end());
        // Maximum number of days for a flwoer to bloom
        int r = *max_element(bloomDay.begin(), bloomDay.end());
        int minDays = -1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            // If bouquets can be made in mid days, try for less days
            if (count(bloomDay, m, k, mid))
                minDays = mid, r = mid - 1;
            // If bouquets can't be made, go for more days
            else
                l = mid + 1;
        }

        return minDays;
    }
};
