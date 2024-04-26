class Solution
{
public:
    int n;
    // 2-D Array for Memoization
    int t[201][201];
    int solve(vector<vector<int>> &grid, int row, int col)
    {
        // Base Case(For the last row)
        if (row == n - 1)
        {
            return grid[row][col];
        }

        // If answer is already stored of that specific row and column
        if (t[row][col] != -1)
        {
            return t[row][col];
        }

        // Recursion Call
        int ans = INT_MAX;
        for (int nextCol = 0; nextCol < n; nextCol++)
        {
            // Avoiding Same column in adjacent rows
            if (nextCol != col)
            {
                // Checking for every column in adjacent rows
                ans = min(ans, solve(grid, row + 1, nextCol));
            }
        }

        // Adding answer with the first row and column
        return t[row][col] = grid[row][col] + ans;
    }

    int minFallingPathSum(vector<vector<int>> &grid)
    {
        n = grid.size();
        memset(t, -1, sizeof(t));

        int ans = INT_MAX;
        // Calling the Recursive function for every column
        for (int col = 0; col < n; col++)
        {
            ans = min(ans, solve(grid, 0, col));
        }

        return ans;
    }
};