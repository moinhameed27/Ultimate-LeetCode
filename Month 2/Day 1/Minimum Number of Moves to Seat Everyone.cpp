class Solution
{
public:
    int minMovesToSeat(vector<int> &seats, vector<int> &students)
    {
        // Sort both arrays
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int n = seats.size(), count = 0;
        // Add the difference between the elements of both arrays to count
        for (int i = 0; i < n; i++)
            count += abs(seats[i] - students[i]);

        return count;
    }
};