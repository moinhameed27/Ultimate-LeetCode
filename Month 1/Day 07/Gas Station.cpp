class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size(); 
        int start = 0, tank = 0, total = 0;

        for (int i = 0; i < n; ++i)
        {
            // Total contains sum of all differences of gas and cost
            total += gas[i] - cost[i];
            // Tank contains sum of current difference
            tank += gas[i] - cost[i];
            // if Tank is negative, it resets itself and starts from i + 1
            if (tank < 0)
            {
                start = i + 1;
                tank = 0;
            }
        }
        // At the end if total >= 0 means car can travel all gas stations, return the index from where it started
        // Otherwise return -1
        return total >= 0 ? start : -1;
    }
};
