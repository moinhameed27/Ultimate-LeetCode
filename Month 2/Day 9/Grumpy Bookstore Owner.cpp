class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int n = customers.size();
        int currUnhappy = 0;
        // Counting max Consecutive unhappy Customers in first minutes elements of the array
        for (int i = 0; i < minutes; i++)
            currUnhappy += customers[i] * grumpy[i];
        
        int totalUnhappy = currUnhappy;
        int i = 0, j = minutes;
        // Running the loop further to get the max count of consecutive unsatisfied customers
        while (j < n)
        {
            currUnhappy += customers[j] * grumpy[j];    // Adding next element
            currUnhappy -= customers[i] * grumpy[i];    // Removing previous element

            totalUnhappy = max(totalUnhappy, currUnhappy);
            i++;
            j++;
        }
        int maxCustomers = totalUnhappy;

        // Now adding the max unsatisfied customers on which power can be used to all the satisfied customers
        for (int i = 0; i < n; i++)
            maxCustomers += customers[i] * (1 - grumpy[i]);

        return maxCustomers;
    }
};