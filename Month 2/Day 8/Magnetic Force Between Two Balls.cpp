class Solution
{
    bool possibleToPlace(vector<int> &position, int force, int m)
    {
        // Initially, one Ball is placed at the start
        int prev = position[0], countBalls = 1;
        for (int i = 0; i < position.size(); i++)
        {
            int curr = position[i];
            // Check if next ball can be placed with the force value or not
            if (curr - prev >= force)
                countBalls++, prev = curr;
            if (countBalls == m)
                return true;
        }
        return false;
    }

public:
    int maxDistance(vector<int> &position, int m)
    {
        int n = position.size();
        // Sort the array to get the elements like in a number line
        sort(position.begin(), position.end());
        int minForce = 1;
        int maxForce = position[n - 1] - position[0];

        while (minForce <= maxForce)
        {
            int mid = minForce + (maxForce - minForce) / 2;
            // Check whether the balls can be placed according to mid value or not
            if (possibleToPlace(position, mid, m))
                minForce = mid + 1;
            else
                maxForce = mid - 1;
        }
        return maxForce;
    }
};