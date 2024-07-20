class Solution
{
public:
    vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum)
    {
        int m = rowSum.size(), n = colSum.size();
        vector<vector<int>> ans(m, vector<int>(n));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans[i][j] = min(rowSum[i], colSum[j]);
                rowSum[i] -= ans[i][j];
                colSum[j] -= ans[i][j];
            }
        }
        return ans;
    }
};

/*
Dry Run:
rowSum = [3, 8]
colSum = [4, 7]

ans = [
    [0, 0],
    [0, 0]
]

i = 0, j = 0

--> i = 0
    --> j = 0
        ans[0][0] = min(3, 4) = 3
        rowSum[0] = 3 - 3 = 0
        colSum[0] = 4 - 3 = 1
    --> j = 1
        ans[0][1] = min(0, 7) = 0
        rowSum[0] = 0 - 0 = 0
        colSum[1] = 7 - 0 = 7
    rowSum = [0, 8], colSum = [1, 7]

    ans = [
        [3, 0],
        [0, 0]
    ]

--> i = 1
    --> j = 0
        ans[1][0] = min(8, 1) = 1
        rowSum[1] = 8 - 1 = 7
        colSum[0] = 1 - 1 = 0
    --> j = 1
        ans[1][1] = min(7, 7) = 7
        rowSum[1] = 7 - 7 = 0
        colSum[1] = 7 - 7 = 0

    rowSum = [0, 0], colSum = [0, 0]
    
    ans = [
        [3, 0],
        [1, 7]
    ]
*/