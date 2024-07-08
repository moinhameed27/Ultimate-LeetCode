// Way - I (Array)
class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        vector<bool> eliminated(n, false);
        int countK = 0, rem = n, i = 0;
        // Until there's only one winner left
        while (rem > 1)
        {
            // If current person is not eliminated
            if (!eliminated[i])
            {
                countK++;
                if (countK == k)
                {
                    eliminated[i] = true;
                    countK = 0;
                    rem--;
                }
            }
            // Circular traversal
            i = (i + 1) % n;
        }
        // Find the winner
        for (int i = 0; i < n; i++)
        {
            if (!eliminated[i])
                return i + 1;
        }
        return 0;
    }
};

// Way - II (Queue)
class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        queue<int> q;
        // All elements into Queue
        for (int i = 1; i <= n; i++)
            q.push(i);

        // Until there's only one winner left
        while (q.size() > 1)
        {
            // k - 1 As one person is already counted (front of queue)
            // Send all the persons in the back of queue and finally erase the loser
            for (int i = 0; i < k - 1; i++)
            {
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }
        // There'll only one winner left
        return q.front();
    }
};

// Way - III (Recursion)
class Solution
{
    int findWinner(int n, int k)
    {
        // If there's only one element left, its index will be 0
        if (n == 1)
            return 0;
        int idx = findWinner(n - 1, k);
        // Adding k to find the original index in the original array, and taking % to wrap around in a circle
        idx = (idx + k) % n;
        return idx;
    }

public:
    int findTheWinner(int n, int k)
    {
        int ans = findWinner(n, k);
        // Adding 1 as array index starts from 0
        return ans + 1;
    }
};