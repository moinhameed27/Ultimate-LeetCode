class Solution
{
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {
        int m = difficulty.size();
        int n = worker.size();

        // Make a pair of difficulty and profit to sort them accordingly
        vector<pair<int, int>> vc(m);
        for (int i = 0; i < m; i++)
            vc[i] = {difficulty[i], profit[i]};

        // Sort the pair according to difficulty
        sort(vc.begin(), vc.end());
        // Sort the workers also (A higher difficulty worker can also do jobs of lower difficulty workers)
        sort(worker.begin(), worker.end());

        int j = 0, maxProfit = 0, totalProfit = 0;
        for (int i = 0; i < n; i++)
        {
            // If job can be done(Difficulty Condition satisfied)
            while (j < m && worker[i] >= vc[j].first)
            {
                maxProfit = max(maxProfit, vc[j].second);
                j++;
            }
            totalProfit += maxProfit;
        }
        return totalProfit;
    }
};