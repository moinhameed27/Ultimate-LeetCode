// Way - I (Brute Force [Storing the minimum and maximum elements separately])
class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();

        vector<int> rowMinimums(m, INT_MAX);
        vector<int> colMaximums(n, 0);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int currElement = matrix[i][j];
                rowMinimums[i] = min(rowMinimums[i], currElement);
                colMaximums[j] = max(colMaximums[j], currElement);
            }
        }

        vector<int> ans;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int currElement = matrix[i][j];
                // If current element is the minimum in it's row and maximum in it's column
                if (currElement == rowMinimums[i] && currElement == colMaximums[j])
                    ans.push_back(currElement);
            }
        }
        return ans;
    }
};

// Way - II (Constant Space)
/* For every minimum element of a row, find maximum element in that column */
class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        vector<int> ans;
        for (int i = 0; i < m; i++)
        {
            bool flag = true;
            // Minimum element in the row[i]
            auto minIt = min_element(matrix[i].begin(), matrix[i].end());
            int minIdx = distance(matrix[i].begin(), minIt);
            int minElement = *minIt;
            for (int j = 0; j < m; j++)
            {
                // If that minimum element is not the maximum in it's column
                if (matrix[j][minIdx] > minElement)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                ans.push_back(minElement);
        }
        return ans;
    }
};

// Way - III (Only One Lucky Number in a matrix is Possible)
class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        int rowMinMax = INT_MIN, colMaxMin = INT_MAX;
        // Find the minimum of every row, and maximum of all rows minimums (Maximum Element of the column)
        for (int i = 0; i < m; i++)
        {
            int rowMin = INT_MAX;
            for (int j = 0; j < n; j++)
            {
                int currElement = matrix[i][j];
                rowMin = min(rowMin, currElement);
            }
            rowMinMax = max(rowMin, rowMinMax);
        }

        // Find the maximum of every column, and minimum of all columns maximums (Minimum Element of the row)
        for (int j = 0; j < n; j++)
        {
            int colMax = INT_MIN;
            for (int i = 0; i < m; i++)
            {
                int currElement = matrix[i][j];
                colMax = max(colMax, currElement);
            }
            colMaxMin = min(colMax, colMaxMin);
        }

        // If the minimum of a row is equal to the maximum of it's column, then it is the lucky number
        if (rowMinMax == colMaxMin)
            return {rowMinMax};
        return {};
    }
};

/*
Dry Run (Way - III):
matrix = [[3,7,8],[9,11,13],[15,16,17]]
m = 3, n = 3
--> i = 0
    rowMin = 3
    --> j = 0
        currElement = 3
        rowMin = 3
    --> j = 1
        currElement = 7
        rowMin = 3
    --> j = 2
        currElement = 8
        rowMin = 3
    rowMinMax = 3

--> i = 1
    rowMin = 9
    --> j = 0
        currElement = 9
        rowMin = 9
    --> j = 1
        currElement = 11
        rowMin = 9
    --> j = 2
        currElement = 13
        rowMin = 9
    rowMinMax = 9

--> i = 2
    rowMin = 15
    --> j = 0
        currElement = 15
        rowMin = 15
    --> j = 1
        currElement = 16
        rowMin = 15
    --> j = 2
        currElement = 17
        rowMin = 15
    rowMinMax = 15

--> j = 0
    colMax = 15
    --> i = 0
        currElement = 3
        colMax = 3
    --> i = 1
        currElement = 9
        colMax = 9
    --> i = 2
        currElement = 15
        colMax = 15
    colMaxMin = 15

--> j = 1
    colMax = 16
    --> i = 0
        currElement = 7
        colMax = 7
    --> i = 1
        currElement = 11
        colMax = 11
    --> i = 2
        currElement = 16
        colMax = 16
    colMaxMin = 15

--> j = 2
    colMax = 17
    --> i = 0
        currElement = 8
        colMax = 8
    --> i = 1
        currElement = 13
        colMax = 13
    --> i = 2
        currElement = 17
        colMax = 17
    colMaxMin = 15

rowMinMax = 15, colMaxMin = 15
Return {15}
*/