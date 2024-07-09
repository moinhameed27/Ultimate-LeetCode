class Solution
{
public:
    double averageWaitingTime(vector<vector<int>> &customers)
    {
        int chefTime = 0, waitTime = 0, n = customers.size();
        double avgTime = 0;
        for (int i = 0; i < n; i++)
        {
            // Time where chef starts preparing order
            chefTime = max(chefTime, customers[i][0]);
            // Time taken to prepare the current order
            chefTime += customers[i][1];
            // Current customer has to do
            waitTime = chefTime - customers[i][0];
            // For calculating average
            avgTime += waitTime;
        }
        avgTime /= n;
        return avgTime;
    }
};