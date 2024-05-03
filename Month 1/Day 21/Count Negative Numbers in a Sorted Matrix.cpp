// Way - I (Brute Force)
class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;
        for (int i = 0; i < m; i++)
        {
            // Start from the right most column and if any positive number appears, break the loop
            for (int j = n - 1; j >= 0; j--)
            {
                if (grid[i][j] < 0)
                    count++;
                else
                    break;
            }
        }
        return count;
    }
};

// Way - II (Binary Search)
class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;
        // Start from the last row and first column
        int i = m - 1, j = 0;

        while (i >= 0 && j < n)
        {
            // If negative number appears
            if (grid[i][j] < 0)
            {
                // If any element of row is negative, it means all next elements of same row will also be negative, so add 
                // remaining number of columns to count
                count += n - j;
                i--;    // Decrease the row
            }

            else
                j++;    // Increase the column
        }

        return count;
    }
};