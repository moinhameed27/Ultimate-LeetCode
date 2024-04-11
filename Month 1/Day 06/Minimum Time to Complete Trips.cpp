class Solution
{
public:
    long long minimumTime(vector<int> &time, int totalTrips)
    {
        // Minimum time to complete one trip
        long long start = 1;
        // Here we can take any large value like 1e14 and check in between
        // but the perfect value will be minimum time to complete given trips using the fastest bus
        long long end = (long long) *min_element(time.begin(), time.end()) * totalTrips;
        while (start < end)
        {
            long long mid = start + (end - start) / 2;
            long long actualTrips = 0;

            // Counting the trips completed by using the middle bus
            for (int i : time)
            {
                actualTrips += mid / i;
            }

            // If more or equal trips can be completed than given trips, shrink from the right side to check for minimum trips
            if (actualTrips >= totalTrips)
                end = mid;
            // Otherwise, shrink from the left side
            else
                start = mid + 1;
        }
        // At the end, start element will be the minimum time to complete totalTrips
        return start;
    }
};
