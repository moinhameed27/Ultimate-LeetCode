
class Solution
{
    // Check how many hours it'll take to eat all by eating mid bananas per hour
    bool canEatAll(vector<int> &piles, int mid, int h)
    { 
        int hours = 0;
        for (int i : piles)
        {
            // 11 / 3 = 3, 11 % 3 = 2 --> So total hours = 3 + 1(if remainder is != 0)
            hours += i / mid;
            if (i % mid != 0)
                hours++;
        }
        // If hours are <= h, then return true otherwise false
        return hours <= h;
    }

public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int n = piles.size();
        // Minimum Number of bananas Koko can eat
        int left = 1;
        // Maximum Number of bananas Koko can eat
        int right = *max_element(piles.begin(), piles.end());

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            // If Koko can eat 'mid' Bananas in 'h' hours, shrink the window from right to check for minimum bananas
            if (canEatAll(piles, mid, h))
                right = mid;
            // Otherwise, shrink from the left
            else
                left = mid + 1;
        }
        // At the end, return left as it'll be equal to minimum number of banans Koko can eat
        return left;
    }
};
