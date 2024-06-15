class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        int n = profits.size();

        // Making a vector of pairs(capital, profits) to sort them accordingly
        vector<pair<int, int>> vc(n);

        // Assigning values to the vector
        for (int i = 0; i < n; i++)
            vc[i] = {capital[i], profits[i]};

        // As default, it will sort according to the first element
        sort(vc.begin(), vc.end());

        priority_queue<int> pq;

        int i = 0;
        // Run until max projects are done
        while (k--)
        {
            // If i is in bound and the capital of i index is less than our capital
            while (i < n && vc[i].first <= w)
            {
                // Push the profit to the queue
                pq.push(vc[i].second);
                i++;
            }

            // If at any point, queue is empty
            if (pq.empty())
                break;

            // Add max profit to the capital
            w += pq.top();
            // Remove the added profit
            pq.pop();
        }

        return w;
    }
};